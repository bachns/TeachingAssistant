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
* File name: TeachingAssistant/ExamModel.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef EXAMMODEL_H
#define EXAMMODEL_H

#include "Exam.h"
#include <QList>

class ExamModel
{
public:
	ExamModel();
	explicit ExamModel(const Exam& exam);
	~ExamModel();

	bool insert() const;
	bool update() const;
	bool remove() const;
	static QList<Exam> getExams();

private:
	Exam m_exam;
};

#endif // EXAMMODEL_H
