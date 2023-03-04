#include <string>
#ifndef DATE_H
#define DATE_H

class Date
{
 public:
	 Date ();
	 Date (const std::string&);
	 void setDay (int);
	 void setMonth (int);
	 void setYear (int);
	 int getDay ();
	 int getMonth ();
	 int getYear ();

 private:
	 int m_day;
	 int m_month;
	 int m_year;
};

#endif // date.h
