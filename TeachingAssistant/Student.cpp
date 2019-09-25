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
* File name: TeachingAssistant/Student.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include "Student.h"
#include <utility>
#include <QString>
#include "Vietnamese.h"


Student::Student() : m_id(0)
{
}

Student::Student(const Student& stu)
{
	m_id = stu.m_id;
	m_firstName = stu.m_firstName;
	m_firstNameEn = stu.m_firstNameEn;
	m_lastName = stu.m_lastName;
	m_lastnameEn = stu.m_lastnameEn;
}

Student::~Student() = default;

void Student::setId(const int id)
{
	m_id = id;
}

void Student::setFirstName(const QString& firstName)
{
	m_firstName = firstName;
	m_firstNameEn = Vietnamese::removeTone(m_firstName);
}

void Student::setLastName(const QString& lastName)
{
	m_lastName = lastName;
	m_lastnameEn = Vietnamese::removeTone(m_lastName);
}

void Student::setFullName(const QString& fullName)
{
	const auto index = fullName.lastIndexOf(" ");
	const auto last = fullName.left(index);
	const auto first = fullName.right(fullName.length() - index - 1);
	setFirstName(first);
	setLastName(last);
}

int Student::id() const
{
	return m_id;
}

QString Student::firstName() const
{
	return m_firstName;
}

QString Student::lastName() const
{
	return m_lastName;
}

QString Student::fullName() const
{
	return m_lastName + " " + m_firstName;
}

QString Student::firstNameEn() const
{
	return m_firstNameEn;
}

QString Student::lastNameEn() const
{
	return m_lastnameEn;
}

Student::Student(const int id, QString firstName, QString lastName)
	: m_id(id), m_firstName(std::move(firstName)), m_lastName(std::move(lastName))
{
}

Student::Student(const int id, const QString& name)
	: m_id(id)
{
	setFullName(name);
}
