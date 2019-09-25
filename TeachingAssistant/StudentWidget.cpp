/********************************************************************************
*   Copyright (C) 2019 by Bach Nguyen Sy                                       *
*   Unauthorized copying of this file via any medium is strictly prohibited    *
*                                                                              *
*   <bachns.dev@gmail.com>                                                     *
*   https://bachns.wordpress.com                                               *
*   https://www.facebook.com/bachns.dev                                        *
*                                                                              *
********************************************************************************/

/**
* File name: TeachingAssistant/StudentWidget.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include "StudentWidget.h"
#include "StudentModel.h"
#include "Vietnamese.h"
#include <QTimer>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>

StudentWidget::StudentWidget(QWidget* parent)
	: QWidget(parent), m_currentAction(NONE)
{
	setupUi(this);
	createConnections();
	tableWidget->setColumnCount(1);
	tableWidget->setHorizontalHeaderLabels({Vietnamese::str(L"Họ và tên")});
	tableWidget->horizontalHeader()->setStretchLastSection(true);
	refresh();
}

void StudentWidget::refresh() const
{
	tableWidget->setRowCount(0);
	const auto students = StudentModel::getStudents();
	for (auto i = 0; i < students.size(); i++)
	{
		const auto& stu = students.at(i);
		tableWidget->insertRow(i);
		const auto item = new QTableWidgetItem(stu.fullName());
		item->setData(Qt::UserRole, stu.id());
		tableWidget->setItem(i, 0, item);
	}
	tableWidget->resizeColumnToContents(0);
	tableWidget->resizeRowsToContents();
	tableWidget->clearSelection();
}

void StudentWidget::add()
{
	clear();
	m_currentAction = ADD;
	pushMessage(PMT_INFO, L"Thêm:", L"Nhập mới sau đó nhấn xác nhận", true);
}

void StudentWidget::edit()
{
	clear();
	m_currentAction = EDIT;
	studentLedr->setText(m_student.fullName());
	pushMessage(PMT_INFO, L"Sửa:", L"Sửa đổi sau đó nhấn xác nhận", true);
}

void StudentWidget::remove()
{
	if (m_student.id() > 0 &&
		QMessageBox::question(this, Vietnamese::str(L"Xóa học viên"),
		Vietnamese::str(L"Bạn muốn xóa học viên %1?").arg(m_student.fullName()))
		== QMessageBox::Yes)
	{
		const StudentModel model(m_student);
		if (model.remove())
		{
			pushMessage(PMT_INFO, L"Đã xóa", L"", false);
			m_student.setId(0);
			refresh();
		}
		else
		{
			pushMessage(PMT_ERROR, L"Lỗi SQL", L"Kiểm tra log.txt", false);
		}
	}
}

void StudentWidget::load()
{
	const auto fileName = QFileDialog::getOpenFileName(this, Vietnamese::str(L"Chọn tệp tải vào"),
		QString(), "Text (*.txt)");
	
	if (!fileName.isEmpty())
	{
		QFile file(fileName);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			auto result = true;
			QTextStream textStream(&file);
			textStream.setCodec("UTF-8");
			while (!textStream.atEnd())
			{
				auto fullName = textStream.readLine().trimmed();
				if (!fullName.isEmpty())
				{
					Student stu(0, fullName);
					StudentModel model(stu);
					result &= model.insert();
				}
			}
			
			if (result)
			{
				pushMessage(PMT_INFO, L"Tải vào thành công", L"", false);
			}
			else
			{
				pushMessage(PMT_ERROR, L"Có lỗi:", L"Kiểm tra log.txt", false);
			}
			refresh();
		}
		else
		{
			pushMessage(PMT_ERROR, L"Lỗi:", L"Không thể mở tệp", false);
		}
	}
}

void StudentWidget::clear() const
{
	studentLedr->clear();
	studentLedr->setFocus();
}

void StudentWidget::showItem(QTableWidgetItem* item)
{
	if (item)
	{
		m_student.setId(item->data(Qt::UserRole).toInt());
		m_student.setFullName(item->text());
		studentLedr->setText(m_student.fullName());
	}
}

void StudentWidget::createConnections()
{
	connect(importBtn, &QPushButton::clicked, [=] { load(); });
	connect(addBtn, &QPushButton::clicked, [=] { add(); });
	connect(editBtn, &QPushButton::clicked, [=] { edit(); });
	connect(removeBtn, &QPushButton::clicked, [=] { remove(); });
	connect(applyBtn, &QPushButton::clicked, [=] { apply(); });
	connect(tableWidget, &QTableWidget::itemClicked, this, &StudentWidget::showItem);
}

void StudentWidget::pushMessage(const PushMessageType type, const wchar_t* actionName,
	const wchar_t* message, const bool freeze)
{
	if (type == PMT_INFO)
	{
		actionNameLbl->setText(Vietnamese::green(actionName));
	}
	else
	{
		actionNameLbl->setText(Vietnamese::red(actionName));
	}
	
	messageLbl->setText(Vietnamese::str(message));
	if (!freeze)
	{
		QTimer::singleShot(2500, [=] { actionNameLbl->clear(); });
		QTimer::singleShot(2500, [=] { messageLbl->clear(); });
	}
}

void StudentWidget::apply()
{
	if (m_currentAction == ADD)
	{
		m_student.setFullName(studentLedr->text().trimmed());
		const StudentModel model(m_student);
		if (model.insert())
		{
			pushMessage(PMT_INFO, L"Thêm thành công", L"", false);
			refresh();
		}
		else
		{
			pushMessage(PMT_ERROR, L"Lỗi SQL", L"Kiểm tra log.txt", false);
		}
	}
	else if (m_currentAction == EDIT)
	{
		m_student.setFullName(studentLedr->text().trimmed());
		const StudentModel model(m_student);
		if (model.update())
		{
			pushMessage(PMT_INFO, L"Sửa thành công", L"", false);
			refresh();
		}
		else
		{
			pushMessage(PMT_ERROR, L"Lỗi SQL", L"Kiểm tra log.txt", false);
		}
	}
	clear();
	m_currentAction = NONE;
}
