#include "restaurant.h"

Restaurant::Restaurant (const std::string& name,const std::string& address)
{
	m_name = name;
	m_address = address;
	m_balance = 0;
	m_receipt = false;
	m_food;
}

void Restaurant::changeName (const std::string& name)
{
	m_name = name;	
}

void Restaurant::addSweetMenu (const std::string& name, double price)
{
	m_food.addSweet(name, price);
}

void Restaurant::addHotDishMenu (const std::string& name, double price)
{
	m_food.addHotDish(name, price);
}

void Restaurant::addSaladMenu (const std::string& name, double price)
{
	m_food.addSalad(name, price);
}

std::string Restaurant::getName ()
{
	return m_name;
}

void Restaurant::changeAddress (const std::string& address)
{
	m_address = address;
}

std::string Restaurant::getAddress ()
{
	return m_address;
}

void Restaurant::printHotDishMenu ()
{
	m_food.printHotDishMenu();
}

void Restaurant::printSweetMenu ()
{
	m_food.printSweetMenu();
}

void Restaurant::printSaladMenu ()
{
	m_food.printSaladMenu();
}

void Restaurant::printAllMenu ()
{
	m_food.printAllMenu();
}

bool Restaurant::getReceipt ()
{
	return m_receipt;
}

double Restaurant::getPrice (const std::string& name)
{
	m_food.getPrice(name);
}

void Restaurant::updateReceipt ()
{
	m_receipt = false;
	m_food.updateReceipt();
}

void Restaurant::order (const std::string& name)
{
	if (m_food.getReceipt(name))
	{
		m_receipt = true;
	}
}
void Restaurant::addBalance (double money)
{
	m_balance += money;
}
