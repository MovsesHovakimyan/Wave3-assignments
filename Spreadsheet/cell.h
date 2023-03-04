#include <string>
#include "date.h"
#include "color.h"
#ifndef CELL_H
#define CELL_H

class Cell 
{
 public:
	Cell ();
	Cell (const std::string&, Color&);
	void setValue (const std::string&);
	void setColor (Color&);
	std::string getValue () const;
	Color getColor ();
	int toInt ();
	double toDouble ();
	Date toDate ();
	void reset ();

 private:
	 std::string m_value;
	 Color m_color;
};

#endif // cell.h
