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
* File name: TeachingAssistant/Assignment.cpp
* Date created: September 24, 2019
* Written by Bach Nguyen Sy
*/

#include "Assignment.h"

Assignment::Assignment() : m_id(0), m_studentId(0), m_examId(0){}

Assignment::Assignment(const Assignment& a)
{
	m_id = a.m_id;
	m_studentId = a.m_studentId;
	m_examId = a.m_examId;
}

Assignment::Assignment(const int id, const int studentId, const int examId)
	: m_id(id), m_studentId(studentId), m_examId(examId)
{
}

Assignment::~Assignment() = default;

void Assignment::setId(const int id)
{
	m_id = id;
}

void Assignment::setStudentId(const int id)
{
	m_studentId = id;
}

void Assignment::setExamId(const int id)
{
	m_studentId = id;
}

int Assignment::id() const
{
	return m_id;
}

int Assignment::studentId() const
{
	return m_studentId;
}

int Assignment::examId() const
{
	return m_examId;
}
