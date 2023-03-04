#include "user.h"
#include <iostream>

User::User (const std::string& name, const std::string& pass)
{
	m_userName = name;
	m_password = pass;
	m_balance = 0;
	m_receipt = false;
}

void User::changeName (const std::string& name)
{
	m_userName = name;
}

std::string User::getName ()
{
	return m_userName;
}

void User::depositeBalance (double money)
{
	if (money > 0)
	{
		m_balance += money;
	}
	else 
	{
		std::cout << "Invalid Value:" << std::endl;
	}
}

void User::withdrawBalance (double money)
{
	if (m_balance >= money)
	{
		m_balance -= money;
		m_receipt = true;
	}
	else
	{
		std::cout << "Insufficient account balance:" << std::cout;
		m_receipt = false;
	}
}

double User::getBalance ()
{
	return m_balance;
}

bool User::getReceipt ()
{
	return m_receipt;
}

void User::updateReceipt ()
{

	m_receipt = false;
}
