#include <iostream>
#include "spreadsheet.h"

int main ()
{
	Spreadsheet sp(5, 6);
	sp.setCellAt(1,1,"11-09-200");
	Cell cl = sp.getCellAt(1,1);
	//	Date d = cl.toDate();	
	std::cout << cl.getValue() ;
}
