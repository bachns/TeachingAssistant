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
* File name: TeachingAssistant/StudentExamModel.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef STUDENTEXAMMODEL_H
#define STUDENTEXAMMODEL_H

#include "StudentExam.h"

class StudentExamModel
{
public:
	StudentExamModel();
	explicit StudentExamModel(const StudentExam& studentExam);
	~StudentExamModel();

private:
	StudentExam m_studentExam;
};

#endif // STUDENTEXAMMODEL_H