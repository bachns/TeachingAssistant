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
* File name: TeachingAssistant/HomeWidget.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include "ui_HomeWidget.h"

class HomeWidget final : public QWidget, Ui::HomeWidget
{
	Q_OBJECT

public:
	explicit HomeWidget(QWidget *parent = Q_NULLPTR);
	~HomeWidget();
	void refresh() const;

private:
	void createConnections();
	void generateMatching();
	
};


#endif // HOMEWIDGET_H
