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
* File name: TeachingAssistant/HomeWidget.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include "HomeWidget.h"
#include "Vietnamese.h"
#include "Student.h"
#include "StudentModel.h"
#include "Exam.h"
#include "ExamModel.h"
#include <random>
#include <QMessageBox>
#include "Assignment.h"
#include "AssignmentModel.h"

HomeWidget::HomeWidget(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	createConnections();
	tableWidget->setColumnCount(2);
	tableWidget->setHorizontalHeaderLabels({
		Vietnamese::str(L"Họ tên"),
		Vietnamese::str(L"Bài tập") });
	tableWidget->horizontalHeader()->setStretchLastSection(true);
	refresh();
}

HomeWidget::~HomeWidget() = default;

void HomeWidget::refresh() const
{
	const auto assignmentNames = AssignmentModel::getAssignmentNames();
	tableWidget->setRowCount(0);
	for (auto i = 0; i < assignmentNames.size(); i++)
	{
		const auto& assignmentName = assignmentNames.at(i);
		const auto itemStu = new QTableWidgetItem(assignmentName.first);
		const auto itemEx = new QTableWidgetItem(assignmentName.second);
		tableWidget->insertRow(i);
		tableWidget->setItem(i, 0, itemStu);
		tableWidget->setItem(i, 1, itemEx);
	}
	tableWidget->resizeColumnToContents(0);
	tableWidget->resizeRowsToContents();
	tableWidget->clearSelection();
}

void HomeWidget::createConnections()
{
	connect(generateBtn, &QPushButton::clicked, [=] { generateMatching(); });
}

void HomeWidget::generateMatching()
{
	const auto students = StudentModel::getStudents();
	auto exams = ExamModel::getExams();
	if (students.empty() || exams.empty())
	{
		QMessageBox::warning(this, Vietnamese::str(L"Thiếu thông tin"),
			Vietnamese::str(L"Chưa có dữ liệu học viên hoặc bài tập"));
		return;
	}

	if (tableWidget->rowCount() &&
		QMessageBox::question(this, Vietnamese::str(L"Tạo mới"),
			Vietnamese::str(L"Bạn muốn tạo mới lại?")) == QMessageBox::No)
	{
		return;
	}
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(exams.begin(), exams.end(), g);

	tableWidget->setRowCount(0);
	AssignmentModel::removeAll();
	for (auto i = 0; i < students.size(); i++)
	{
		const auto& stu = students.at(i);
		const auto& ex = exams.at(i);
		Assignment assignment(0, stu.id(), ex.id());
		AssignmentModel model(assignment);
		// ReSharper disable once CppExpressionWithoutSideEffects
		model.insert();
		
		const auto itemStu = new QTableWidgetItem(stu.fullName());
		const auto itemEx = new QTableWidgetItem(ex.name());
		tableWidget->insertRow(i);
		tableWidget->setItem(i, 0, itemStu);
		tableWidget->setItem(i, 1, itemEx);
	}
	tableWidget->resizeColumnToContents(0);
	tableWidget->resizeRowsToContents();
	tableWidget->clearSelection();
}
