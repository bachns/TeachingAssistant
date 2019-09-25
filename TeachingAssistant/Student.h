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
* File name: TeachingAssistant/Student.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
	Student();
	Student(const Student& stu);
	Student(int id, QString firstName, QString lastName);
	Student(int id, const QString& fullName);
	~Student();

	void setId(int id);
	void setFirstName(const QString& firstName);
	void setLastName(const QString& lastName);
	void setFullName(const QString& fullName);

	int id() const;
	QString firstName() const;
	QString lastName() const;
	QString fullName() const;
	QString firstNameEn() const;
	QString lastNameEn() const;

private:
	int m_id;
	QString m_firstName;
	QString m_lastName;
	QString m_firstNameEn;
	QString m_lastnameEn;
};

#endif // STUDENT_H
