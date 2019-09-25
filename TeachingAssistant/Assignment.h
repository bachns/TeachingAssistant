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
* File name: TeachingAssistant/Assignment.h
* Date created: September 24, 2019
* Written by Bach Nguyen Sy
*/
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

class Assignment
{
public:
	Assignment();
	Assignment(const Assignment& a);
	Assignment(int id, int studentId, int examId);
	~Assignment();

	void setId(int id);
	void setStudentId(int id);
	void setExamId(int id);
	
	int id() const;
	int studentId() const;
	int examId() const;

private:
	int m_id;
	int m_studentId;
	int m_examId;
};

#endif // ASSIGNMENT_H