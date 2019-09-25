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
* File name: TeachingAssistant/StudentExam.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef STUDENTEXAM_H
#define STUDENTEXAM_H

class StudentExam
{
public:
	StudentExam();
	StudentExam(const StudentExam& studentExam);
	StudentExam(int idStudent, int idExam);
	~StudentExam();

	void setIdStudent(int id);
	void setIdExam(int id);

	int idStudent() const;
	int idExam() const;

private:
	int m_idStudent;
	int m_idExam;
};

#endif // STUDENTEXAM_H