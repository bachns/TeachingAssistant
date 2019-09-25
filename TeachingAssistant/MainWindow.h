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
* File name: TeachingAssistant/MainWindow.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

class MainWindow final : public QMainWindow, Ui::MainWindowClass
{
Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = Q_NULLPTR);

private:
	void createConnections();
};

#endif // MAINWINDOW_H
