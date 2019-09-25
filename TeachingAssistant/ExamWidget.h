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
* File name: TeachingAssistant/ExamWidget.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef EXAMWIDGET_H
#define EXAMWIDGET_H

#include "ui_ExamWidget.h"
#include "Exam.h"

class ExamWidget final : public QWidget, Ui::ExamWidget
{
	Q_OBJECT

public:
	enum CurrentAction
	{
		NONE,
		ADD,
		EDIT
	};

	enum PushMessageType
	{
		PMT_INFO,
		PMT_ERROR
	};
	
	explicit ExamWidget(QWidget *parent = Q_NULLPTR);
	~ExamWidget();

	void refresh() const;
	void add();
	void edit();
	void remove();
	void load();
	void clear() const;

private slots:
	void showItem(QTableWidgetItem* item);

private:
	void createConnections();
	void pushMessage(PushMessageType type, const wchar_t* actionName,
		const wchar_t* message, bool freeze);
	void apply();
	CurrentAction m_currentAction;
	Exam m_exam;
};

#endif // EXAMWIDGET_H