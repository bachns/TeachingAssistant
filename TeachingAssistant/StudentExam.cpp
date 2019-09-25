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
* File name: TeachingAssistant/StudentExam.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include "StudentExam.h"

StudentExam::StudentExam()
	: m_idStudent(0), m_idExam(0)
{
}

StudentExam::StudentExam(const StudentExam& studentExam)
{
	m_idStudent = studentExam.m_idStudent;
	m_idExam = studentExam.m_idExam;
}

StudentExam::StudentExam(const int idStudent, const int idExam)
	: m_idStudent(idStudent), m_idExam(idExam)
{
}

StudentExam::~StudentExam() = default;

void StudentExam::setIdStudent(const int id)
{
	m_idStudent = id;
}

void StudentExam::setIdExam(const int id)
{
	m_idExam = id;
}

int StudentExam::idStudent() const
{
	return m_idStudent;
}

int StudentExam::idExam() const
{
	return m_idExam;
}
