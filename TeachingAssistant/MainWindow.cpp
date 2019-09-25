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
* File name: TeachingAssistant/MainWindow.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include "MainWindow.h"
#include "DatabaseConnection.h"
#include "Vietnamese.h"
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	DatabaseConnection connector("StudentDB.db");
	if (!connector.connect())
	{
		QMessageBox::critical(this, Vietnamese::str(L"Lỗi kết nối"),
			Vietnamese::str(L"Không thể kết nối đến cơ sở dữ liệu."));
		QTimer::singleShot(0, [=] { close(); });
	}
	setupUi(this);
	createConnections();
}

void MainWindow::createConnections()
{
	connect(homeBtn, &QPushButton::clicked, [=] { stackedWidget->setCurrentWidget(homeWidget); });
	connect(stuBtn, &QPushButton::clicked, [=] {stackedWidget->setCurrentWidget(studentWidget); });
	connect(examBtn, &QPushButton::clicked, [=] {stackedWidget->setCurrentWidget(examWidget); });
}
