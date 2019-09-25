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
* File name: TeachingAssistant/StudentModel.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include "Student.h"
#include <QList>

class StudentModel
{
public:
	StudentModel();
	explicit StudentModel(const Student& stu);
	~StudentModel();

	bool insert() const;
	bool update() const;
	bool remove() const;
	static QList<Student> getStudents();
	
private:
	Student m_student;
};

#endif // STUDENTMODEL_H
