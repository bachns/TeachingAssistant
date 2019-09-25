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
* File name: TeachingAssistant/ExamModel.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "ExamModel.h"

ExamModel::ExamModel() = default;

ExamModel::ExamModel(const Exam& exam)
	: m_exam(exam)
{
}

ExamModel::~ExamModel() = default;

bool ExamModel::insert() const
{
	QSqlQuery query;
	query.prepare("INSERT INTO Exam(NAME) VALUES(:name)");
	query.bindValue(":name", m_exam.name());
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

bool ExamModel::update() const
{
	QSqlQuery query;
	query.prepare("UPDATE Exam SET NAME=:name WHERE ID=:id");
	query.bindValue(":name", m_exam.name());
	query.bindValue(":id", m_exam.id());
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

bool ExamModel::remove() const
{
	QSqlQuery query;
	query.prepare("DELETE FROM Exam WHERE ID=:id");
	query.bindValue(":id", m_exam.id());
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

QList<Exam> ExamModel::getExams()
{
	QSqlQuery query;
	query.prepare("SELECT ID, NAME FROM Exam");
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return {};
	}
	QList<Exam> exams;
	while (query.next())
	{
		const auto id = query.value("ID").toInt();
		const auto name = query.value("NAME").toString();
		Exam ex(id, name);
		exams.append(ex);
	}
	return exams;
}
