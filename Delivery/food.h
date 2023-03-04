#include <iostream>
#include <string>
#include <map>
#ifndef FOOD_H
#define FOOD_H

class Food 
{
 public:
	void addSweet (const std::string& name, double price);
	void removeSweet (const std::string& name);
	void addHotDish (const std::string& name, double price);
	void removeHotDish (const std::string& name);
	void addSalad (const std::string& name, double price);
	void removeSalad (const std::string& name);
	void printSweetMenu ();
	void printHotDishMenu ();
	void printSaladMenu ();
	void printAllMenu ();
	double getPrice (const std::string& name);
	bool getReceipt (const std::string& name);
	void updateReceipt ();
	
 private:
 	std::map<std::string, double> m_sweet;
	std::map<std::string, double> m_hotDish;
	std::map<std::string, double> m_salad;
	bool m_receipt;
};

#endif // food.h
