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
* File name: TeachingAssistant/AssignmentModel.h
* Date created: September 24, 2019
* Written by Bach Nguyen Sy
*/
#ifndef ASSIGNMENTMODEL_H
#define ASSIGNMENTMODEL_H

#include "Assignment.h"
#include <QList>
#include <QPair>
#include <QString>

class AssignmentModel
{
public:
	AssignmentModel();
	explicit AssignmentModel(const Assignment& assignment);
	~AssignmentModel();

	bool insert() const;
	static bool removeAll();
	static QList<QPair<QString,QString>> getAssignmentNames();

private:
	Assignment m_assignment;
};

#endif // ASSIGNMENTMODEL_H
