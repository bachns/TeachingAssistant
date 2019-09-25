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
* File name: TeachingAssistant/Exam.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/
#ifndef EXAM_H
#define EXAM_H

#include <QString>

class Exam
{
public:
	Exam();
	Exam(int id, QString name);
	Exam(const Exam& ex);
	~Exam();

	void setId(int id);
	void setName(const QString& name);

	int id() const;
	QString name() const;

private:
	int m_id;
	QString m_name;
};

#endif // EXAM_H
