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
* File name: TeachingAssistant/StudentModel.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "StudentModel.h"

StudentModel::StudentModel() = default;

StudentModel::StudentModel(const Student& stu)
	: m_student(stu)
{
}

StudentModel::~StudentModel() = default;

bool StudentModel::insert() const
{
	QSqlQuery query;
	query.prepare(
		" INSERT INTO Student(FIRST, LAST, FIRST_EN, LAST_EN)"
		" VALUES(:first, :last, :first_en, :last_en)");
	query.bindValue(":first", m_student.firstName());
	query.bindValue(":last", m_student.lastName());
	query.bindValue(":first_en", m_student.firstNameEn());
	query.bindValue(":last_en", m_student.lastNameEn());
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

bool StudentModel::update() const
{
	QSqlQuery query;
	query.prepare(
		" UPDATE Student"
		" SET FIRST=:first, LAST=:last, FIRST_EN=:first_en, LAST_EN=:last_en"
		" WHERE ID=:id");
	query.bindValue(":first", m_student.firstName());
	query.bindValue(":last", m_student.lastName());
	query.bindValue(":first_en", m_student.firstNameEn());
	query.bindValue(":last_en", m_student.lastNameEn());
	query.bindValue(":id", m_student.id());
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

bool StudentModel::remove() const
{
	QSqlQuery query;
	query.prepare(
		" DELETE FROM Student"
		" WHERE ID=:id");
	query.bindValue(":id", m_student.id());
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

QList<Student> StudentModel::getStudents()
{
	QSqlQuery query;
	query.prepare("SELECT ID, FIRST, LAST FROM Student ORDER BY FIRST_EN, LAST_EN");
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return {};
	}
	QList<Student> students;
	while (query.next())
	{
		const auto id = query.value("ID").toInt();
		const auto first = query.value("FIRST").toString();
		const auto last = query.value("LAST").toString();
		Student stu(id, first, last);
		students.append(stu);
	}
	return students;
}
