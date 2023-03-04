#include "bankingsystem.h"

int BankingSystem::id = 0;

BankingSystem::BankingSystem (const std::string& userName, const std::string& new_password)
{
	Account account(userName, new_password);
	user.push_back(account);
	security[new_password] = id;
	++id;
}

void BankingSystem::deposit (const std::string& pass, double money)
{
	userID = security[pass];
	if (money > 0)
	{
		user[userID].depositBalance(money);
	}
	else
	{
		std::cout << "Invalid Value:" << std::endl;
	}
}

void BankingSystem::withdraw (const std::string& pass, double money)
{
	userID = security[pass];
	if (user[userID].getBalance() >= money)
	{
		user[userID].withdrawBalance(money);
	}
	else
	{
		std::cout << "Insufficient account balance:" << std::endl;
	}
}


int BankingSystem::getUserID (const std::string& pass)
{
	return security[pass];
}

double BankingSystem::getUserBalance (const std::string& pass)
{
	userID = security[pass];	
	return user[userID].getBalance();
}
