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
* File name: TeachingAssistant/DatabaseConnection.h
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>

class DatabaseConnection
{
public:
	DatabaseConnection();
	explicit DatabaseConnection(QString databaseName);
	~DatabaseConnection();

	void setDatabase(const QString& databaseName);
	QString databaseName() const;
	
	bool connect();
	void disconnect();

private:
	QString m_databaseName;
	QSqlDatabase m_database;
};

#endif // DATABASECONNECTION_H
