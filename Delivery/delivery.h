#include <iostream>
#include "restaurant.h"
#include "user.h"
#include <vector>
#include <map>
#ifndef DELIVERY_H
#define DELIVERY_H

class Delivery 
{
 public:
	 void addUser (User& user);
	 void addRestaurant (Restaurant& res);
	 void order (const std::string& foodName, User& user, Restaurant& res);

 private:
	 std::vector <User> m_User;
	 static int m_UserID;
	 std::map <std::string, int> m_UserMap;
	 std::vector <Restaurant> m_Res;
	 static int m_ResID;
	 std::map <std::string, int> m_ResMap;
	 bool m_ResReceipt;
	 bool m_UserReceipt;
	 double m_price;
	 
	 
};

#endif // delivery.h
