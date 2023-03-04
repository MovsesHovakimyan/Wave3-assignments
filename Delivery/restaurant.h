#include "food.h"
#ifndef RESTAURANT_H
#define RESTAURANT_H

class Restaurant
{
 public:
	 Restaurant (const std::string& name,const std::string& address);
	 void changeName (const std::string& name);
	 void addSweetMenu (const std::string& name, double price);
	 void addHotDishMenu (const std::string& name, double price);
	 void addSaladMenu (const std::string& name, double price);
	 std::string getName ();
	 void changeAddress (const std::string& address);
	 std::string getAddress (); 
	 void printHotDishMenu ();
	 void printSweetMenu ();
	 void printSaladMenu ();
	 void printAllMenu ();
	 bool getReceipt ();
	 double getPrice (const std::string& name);
	 void order (const std::string& name);
	 void addBalance (double money);
	 void updateReceipt ();
	 
 private:
	 std::string m_name;
	 std::string m_address;
	 Food m_food;
	 double m_balance;
	 bool m_receipt;

};

#endif // restaurant.h
