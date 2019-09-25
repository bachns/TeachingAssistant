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
* File name: TeachingAssistant/AssignmentModel.cpp
* Date created: September 24, 2019
* Written by Bach Nguyen Sy
*/

#include "AssignmentModel.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

AssignmentModel::AssignmentModel() = default;

AssignmentModel::AssignmentModel(const Assignment& assignment)
	: m_assignment(assignment)
{
}

AssignmentModel::~AssignmentModel() = default;

bool AssignmentModel::insert() const
{
	QSqlQuery query;
	query.prepare(
		"INSERT INTO Assignment(STU_ID, EXAM_ID)"
		" VALUES(:stu_id, :exam_id)");
	query.bindValue(":stu_id", m_assignment.studentId());
	query.bindValue(":exam_id", m_assignment.examId());
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

bool AssignmentModel::removeAll()
{
	QSqlQuery query;
	query.prepare("DELETE FROM Assignment");
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

QList<QPair<QString, QString>> AssignmentModel::getAssignmentNames()
{
	QSqlQuery query;
	query.prepare("SELECT LAST, FIRST, NAME"
		" FROM Assignment, Student, Exam"
		" WHERE Assignment.STU_ID = Student.ID"
		" AND Assignment.EXAM_ID = EXAM.ID");
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return {};
	}

	QList<QPair<QString, QString>> assignmentNames;
	while (query.next())
	{
		const auto last = query.value("LAST").toString();
		const auto first = query.value("FIRST").toString();
		const auto examName = query.value("NAME").toString();
		const auto fullName = last + " " + first;
		assignmentNames.append(QPair<QString, QString>(fullName, examName));
	}
	return assignmentNames;
}
