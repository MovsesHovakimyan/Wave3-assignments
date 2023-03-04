#include <iostream>
#include "account.h"

Account::Account (const std::string& name, const std::string& pass)
{
	password = pass;
	userName = name;
	balance = 0;
}

void Account::setUserName (const std::string& name)
{
	userName = name;
}

std::string Account::getUserName ()
{
	return userName;
}

void Account::depositBalance (double money)
{
	balance += money;
}

void Account::withdrawBalance (double money)
{
	balance -= money;
}

double Account::getBalance () 
{
	return balance;
}
