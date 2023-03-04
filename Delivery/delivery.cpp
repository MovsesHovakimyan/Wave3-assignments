#include "delivery.h"
#include <iostream>

int Delivery::m_UserID = 0;
int Delivery::m_ResID = 0;

void Delivery::addUser (User& user)
{
	m_User.push_back(user);
	m_UserMap[user.getName()] = m_UserID;
	++m_UserID;
}

void Delivery::addRestaurant (Restaurant& res)
{
	m_Res.push_back(res);
	m_ResMap[res.getName()] = m_ResID;
	++m_ResID;
}

void Delivery::order (const std::string& foodName, User& user, Restaurant& res)
{
	int userID = m_UserMap[user.getName()];
	int resID = m_ResMap[res.getName()];
	
	m_Res[resID].order(foodName);
	m_ResReceipt = m_Res[resID].getReceipt();

	if (m_ResReceipt)
	{
		m_price = m_Res[resID].getPrice(foodName);
		m_User[userID].withdrawBalance(m_price);
		m_UserReceipt = m_User[userID].getReceipt();

		if (m_UserReceipt)
		{
			m_Res[resID].addBalance(m_price);
			std::cout << "Your order is accepted, our courier will contact you:" << std::endl;
		}
	}
	else
	{
		std::cout << "We don't have any of this dish:" << std::endl;
	}
}
