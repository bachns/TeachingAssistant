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
* File name: TeachingAssistant/StudentExamModel.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "StudentExamModel.h"

StudentExamModel::StudentExamModel() = default;

StudentExamModel::StudentExamModel(const StudentExam& studentExam)
	: m_studentExam(studentExam)
{
}

StudentExamModel::~StudentExamModel() = default;
