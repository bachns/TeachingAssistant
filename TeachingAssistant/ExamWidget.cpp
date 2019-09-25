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
* File name: TeachingAssistant/ExamWidget.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include "ExamWidget.h"
#include "ExamModel.h"
#include "Vietnamese.h"
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include <QTextStream>

ExamWidget::ExamWidget(QWidget *parent)
	: QWidget(parent), m_currentAction(NONE)
{
	setupUi(this);
	createConnections();
	tableWidget->setColumnCount(1);
	tableWidget->setHorizontalHeaderLabels({Vietnamese::str(L"Bài tập") });
	tableWidget->horizontalHeader()->setStretchLastSection(true);
	refresh();
}

ExamWidget::~ExamWidget() = default;

void ExamWidget::refresh() const
{
	tableWidget->setRowCount(0);
	const auto exams = ExamModel::getExams();
	for (auto i = 0; i < exams.size(); i++)
	{
		const auto& exam = exams.at(i);
		tableWidget->insertRow(i);
		const auto item = new QTableWidgetItem(exam.name());
		item->setData(Qt::UserRole, exam.id());
		tableWidget->setItem(i, 0, item);
	}
	tableWidget->resizeColumnToContents(0);
	tableWidget->resizeRowsToContents();
	tableWidget->clearSelection();
}

void ExamWidget::add()
{
	clear();
	m_currentAction = ADD;
	pushMessage(PMT_INFO, L"Thêm:", L"Nhập mới sau đó nhấn xác nhận", true);
}

void ExamWidget::edit()
{
	clear();
	m_currentAction = EDIT;
	examLedr->setText(m_exam.name());
	pushMessage(PMT_INFO, L"Sửa:", L"Sửa đổi sau đó nhấn xác nhận", true);
}

void ExamWidget::remove()
{
	if (m_exam.id() > 0 &&
		QMessageBox::question(this, Vietnamese::str(L"Xóa bài tập"),
			Vietnamese::str(L"Bạn muốn xóa bài %1?").arg(m_exam.name()))
		== QMessageBox::Yes)
	{
		const ExamModel model(m_exam);
		if (model.remove())
		{
			pushMessage(PMT_INFO, L"Đã xóa", L"", false);
			m_exam.setId(0);
			refresh();
		}
		else
		{
			pushMessage(PMT_ERROR, L"Lỗi SQL", L"Kiểm tra log.txt", false);
		}
	}
}

void ExamWidget::load()
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
				auto name = textStream.readLine().trimmed();
				if (!name.isEmpty())
				{
					Exam ex(0, name);
					ExamModel model(ex);
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

void ExamWidget::clear() const
{
	examLedr->clear();
	examLedr->setFocus();
}

void ExamWidget::showItem(QTableWidgetItem* item)
{
	if (item)
	{
		m_exam.setId(item->data(Qt::UserRole).toInt());
		m_exam.setName(item->text());
		examLedr->setText(m_exam.name());
	}
}

void ExamWidget::createConnections()
{
	connect(importBtn, &QPushButton::clicked, [=] { load(); });
	connect(addBtn, &QPushButton::clicked, [=] { add(); });
	connect(editBtn, &QPushButton::clicked, [=] { edit(); });
	connect(removeBtn, &QPushButton::clicked, [=] { remove(); });
	connect(applyBtn, &QPushButton::clicked, [=] { apply(); });
	connect(tableWidget, &QTableWidget::itemClicked, this, &ExamWidget::showItem);
}

void ExamWidget::pushMessage(PushMessageType type, const wchar_t* actionName, const wchar_t* message, bool freeze)
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

void ExamWidget::apply()
{
	if (m_currentAction == ADD)
	{
		m_exam.setName(examLedr->text().trimmed());
		const ExamModel model(m_exam);
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
		m_exam.setName(examLedr->text().trimmed());
		const ExamModel model(m_exam);
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
