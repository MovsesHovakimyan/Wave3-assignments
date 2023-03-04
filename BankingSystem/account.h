#include <iostream>
#include <string>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
 public:
	 Account (const std::string&, const std::string&);
	 void setUserName (const std::string&);
	 std::string getUserName ();
	 void depositBalance (double);
	 void withdrawBalance (double);
	 double getBalance ();


 private:
	 std::string password;
	 std::string userName;
	 double balance;
};

#endif // account.h
