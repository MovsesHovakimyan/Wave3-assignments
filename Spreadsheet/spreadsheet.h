#include "cell.h"
#include <iostream>
#ifndef SPREADSHEET_H
#define SPREADSHEET_H

class Spreadsheet 
{
 public:
	Spreadsheet ();
	Spreadsheet (int, int);
	Spreadsheet (const Spreadsheet&);
	Spreadsheet (Spreadsheet&&) noexcept;
	~Spreadsheet ();
	Spreadsheet& operator= (const Spreadsheet&);
	void setCellAt (int, int, const std::string&);
	void setCellAt (int, int, const Cell&);
	Cell getCellAt (int, int);
	void addRow (int);
	void removeRow (int);
	void swapRows (int, int);
	void addColumn (int);
	void removeColumn (int);
	void swapColumns (int, int);
 
 private:
	 Cell** m_cells;
	 int m_row;
	 int m_col;
	 void swap (Spreadsheet&) noexcept;
	 void cleanup() noexcept;
	 void moveFrom(Spreadsheet& src) noexcept;
	 void verifyCoordinate (int, int) const;
	 void verifyRow (int) const;
	 void verifyCol (int) const;
};

#endif // spreadsheet.h
