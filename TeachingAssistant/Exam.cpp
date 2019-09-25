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
* File name: TeachingAssistant/Exam.cpp
* Date created: September 23, 2019
* Written by Bach Nguyen Sy
*/

#include "Exam.h"
#include <utility>
#include <QString>

Exam::Exam() : m_id(0)
{
}

Exam::Exam(const int id, QString name)
	: m_id(id), m_name(std::move(name))
{
}

Exam::Exam(const Exam& ex)
{
	m_id = ex.m_id;
	m_name = ex.m_name;
}

Exam::~Exam() = default;

void Exam::setId(const int id)
{
	m_id = id;
}

void Exam::setName(const QString& name)
{
	m_name = name;
}

int Exam::id() const
{
	return m_id;
}

QString Exam::name() const
{
	return m_name;
}
