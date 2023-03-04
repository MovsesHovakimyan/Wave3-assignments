#include "food.h"

void Food::addSweet (const std::string& name, double price)
{
	m_sweet[name] = price;
}

void Food::removeSweet (const std::string& name)
{
	m_sweet[name] = 0;
}

void Food::addHotDish (const std::string& name, double price)
{
	m_hotDish[name] = price;
}

void Food::removeHotDish (const std::string& name)
{
	m_hotDish[name] = 0;
}

void Food::addSalad (const std::string& name, double price)
{
	m_salad[name] = price;
}

void Food::removeSalad (const std::string& name)
{
	m_salad[name] = 0;
}

void Food::printSweetMenu ()
{
	std::cout << "Menu Sweets:" << std::endl;
	for (std::map<std::string, double>::iterator it = m_sweet.begin(); it != m_sweet.end(); ++it)
	{
		std::cout << it->first << " - " << it->second << " AMD." << std::endl;
	}

}
void Food::printHotDishMenu ()
{
	std::cout << "Menu Hot Dishes:" << std::endl;
	for (std::map<std::string, double>::iterator it = m_hotDish.begin(); it != m_hotDish.end(); ++it)
	{
		std::cout << it->first << " - " << it->second << " AMD." << std::endl;
	}
}
void Food::printSaladMenu ()
{
	std::cout << "Menu Salads:" << std::endl;
	for (std::map<std::string, double>::iterator it = m_salad.begin(); it != m_salad.end(); ++it)
	{
		std::cout << it->first << " - " << it->second << " AMD." << std::endl;
	}
}

void Food::printAllMenu ()
{
	printSaladMenu();
	printHotDishMenu();
	printSaladMenu();
}

double Food::getPrice (const std::string& name)
{
	if (m_sweet[name])
	{
		return m_sweet[name];
	}
	else if (m_hotDish[name])
	{
		return m_hotDish[name];
	}
	else if (m_salad[name])
	{
		return m_salad[name];
	}
}

bool Food::getReceipt (const std::string& name)
{
	if (m_sweet[name])
	{
		return true;
	}
	else if (m_hotDish[name])
	{
		return true;
	}
	else if (m_salad[name])
	{
		return true;
	}

	return false;

}

void Food::updateReceipt ()
{
	m_receipt = false;
}
