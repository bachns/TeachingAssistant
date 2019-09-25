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
* File name: TeachingAssistant/DatabaseConnection.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/
#include <QDebug>
#include <QFile>
#include "DatabaseConnection.h"
#include <QSqlQuery>
#include <QSqlError>

DatabaseConnection::DatabaseConnection()
	: m_databaseName(QString())
	, m_database(QSqlDatabase::addDatabase("QSQLITE"))
{
	
}

DatabaseConnection::DatabaseConnection(QString databaseName)
	: m_databaseName(std::move(databaseName))
	, m_database(QSqlDatabase::addDatabase("QSQLITE"))
{
}

DatabaseConnection::~DatabaseConnection() = default;

void DatabaseConnection::setDatabase(const QString& databaseName)
{
	m_databaseName = databaseName;
}

QString DatabaseConnection::databaseName() const
{
	return m_databaseName;
}

bool DatabaseConnection::connect()
{
	if (!QFile::exists(m_databaseName))
	{
		qDebug() << "Cannot find " << m_databaseName;
		return false;
	}

	m_database.setDatabaseName(m_databaseName);
	if (!m_database.open())
	{
		qDebug() << "Cannot connect to database ";
		return false;
	}

	QSqlQuery query;
	if (!query.exec("PRAGMA foreign_keys = ON"))
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}

void DatabaseConnection::disconnect()
{
	m_database.close();
}