#include <iostream>
#include <string>
#ifndef USER_H
#define USER_H

class User
{
 public:
	 User (const std::string& name, const std::string& pass);
	 void changeName (const std::string& name);
	 std::string getName ();
	 void depositeBalance (double money);
	 void withdrawBalance (double money);
	 double getBalance ();
	 bool getReceipt ();
	 void updateReceipt (); 

 private:
	 std::string m_userName;
	 std::string m_password;
	 double m_balance;
	 bool m_receipt;
};

#endif // user.h
