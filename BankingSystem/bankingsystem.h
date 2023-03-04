#include <iostream>
#include "account.h"
#include <vector>
#include <map>
#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

class BankingSystem
{
 public:
	BankingSystem (const std::string&, const std::string&);
	void deposit (const std::string&, double);
	void withdraw (const std::string&, double);
	int getUserID (const std::string&);
	double getUserBalance (const std::string&);

 private:
	 std::map<std::string, int> security;
	 static int id;
	 int userID;
	 std::vector <Account> user;
	 
};

#endif // BankingSystem.h
