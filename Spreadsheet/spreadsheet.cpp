#include "spreadsheet.h"
#include <iostream>
#include <exception>

Spreadsheet::Spreadsheet()
: m_row (0), m_col(0), m_cells (nullptr)
{
}

Spreadsheet::Spreadsheet(int row, int col)
{
	if (row <= 0 || col <= 0)
	{
		throw std::invalid_argument("!Inconsistent parameter:");
	}
	else
	{
		m_row = row;
		m_col = col;
		m_cells = new Cell* [m_row];

		for (int i = 0; i < m_row; ++i)
		{
			m_cells[i] = new Cell [m_col];
		}
	}
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
: Spreadsheet (src.m_row, src.m_col)
{

	for (int i = 0; i < m_row; ++i)
	{
		for (int j = 0; j < m_col; ++j)
		{
			m_cells[i][j] = src.m_cells[i][j];
		}
	}
}

Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
{
	moveFrom(src);
}

Spreadsheet::~Spreadsheet ()
{
	for (int i = 0; i < m_row; ++i)
	{
		delete[] m_cells[i];
	}

	delete[] m_cells;
	m_cells = nullptr;
	m_row = 0;
	m_col = 0;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	Spreadsheet tmp (rhs);
	swap(tmp);
	return *this;
}

void Spreadsheet::swap(Spreadsheet& other) noexcept
{
	int tmpRow = this->m_row;
	this->m_row = other.m_row;
	other.m_row = tmpRow;

	int tmpCol = this->m_col;
	this->m_col = other.m_col;
	other.m_col = tmpCol;

	Cell** tmpCells = this->m_cells;
	this->m_cells = other.m_cells;
	other.m_cells = tmpCells;
}

void Spreadsheet::cleanup() noexcept 
{
	for (int i = 0; i < m_row; ++i)
	{
		delete[] m_cells[i];
	}
	delete[] m_cells;
	m_cells = nullptr;
	m_row = 0;
	m_col = 0;
}

void Spreadsheet::moveFrom(Spreadsheet& src) noexcept
{
	m_cells = src.m_cells;
	m_row = src.m_row;
	m_col = src.m_col;

	src.cleanup();

}

void Spreadsheet::verifyCoordinate(int row, int col) const
{
	verifyRow(row);
	verifyCol(col);
}

void Spreadsheet::verifyRow (int row) const
{
	if (row > m_row || row < 0)
	{
		throw std::invalid_argument("!Inconsistent parameter:");
	}
}

void Spreadsheet::verifyCol (int col) const
{
	if (col > m_col || col < 0)
	{
		throw std::invalid_argument("!Inconsistent parameter:");
	}
}

void Spreadsheet::setCellAt (int row, int col, const std::string& value)
{
	verifyCoordinate(row, col);
	m_cells[row][col].setValue(value);
}

void Spreadsheet::setCellAt (int row, int col, const Cell& cell)
{	
	verifyCoordinate(row, col);
	m_cells[row][col] = cell;
}

Cell Spreadsheet::getCellAt (int row, int col)
{
	verifyCoordinate(row, col);
	return m_cells[row][col];
}

void Spreadsheet::addRow (int row)
{
	verifyRow(row);
	++m_row;
	Spreadsheet tmp(m_row, m_col);
		
	for (int i = 0; i < m_row; ++i)
	{
		for (int j = 0; j < m_col; ++i)
		{
			if (i < row)
			{
				tmp.setCellAt(i, j, m_cells[i][j]);
			}
			else if (i > row)
			{
				tmp.setCellAt(i, j, m_cells[i - 1][j]);
			}
			
		}
	}

	this->cleanup();
	this->moveFrom(tmp);
}

void Spreadsheet::removeRow (int row)
{
	verifyRow(row);
	--m_row;
	Spreadsheet tmp(m_row, m_col);
	
	for (int i = 0; i < m_row; ++i)
        {
		for (int j = 0; j < m_col; ++i)
                {
                        if (i < row)
                        {
                                tmp.setCellAt(i, j, m_cells[i][j]);
                        }
                        else if (i > row)
                        {
                                tmp.setCellAt(i, j, m_cells[i + 1][j]);
                        }
		}
       	 }
	
	this->cleanup();
	this->moveFrom(tmp);
}

void Spreadsheet::swapRows (int row_1, int row_2)
{
	verifyRow(row_1);
	verifyRow(row_2);

	for (int i = 0; i < m_col; ++i)
	{
		Cell tmp = m_cells[row_1][i];
		m_cells[row_1][i] = m_cells[row_2][i];
		m_cells[row_2][i] = tmp;
	}
}

void Spreadsheet::addColumn (int col)
{
	verifyCol(col);
	++m_col;
       	Spreadsheet tmp(m_row, m_col);

       	for (int i = 0; i < m_row; ++i)
       	{
       	        for (int j = 0; j < m_col; ++i)
       	        {
       	                if (j < col)
       	                {
        	                tmp.setCellAt(i, j, m_cells[i][j]);
               	        }
               	        else if (j > col)
               	        {
               	                tmp.setCellAt(i, j, m_cells[i][j - 1]);
               	        }

		}
	}

	this->cleanup();
        this->moveFrom(tmp);
}

void Spreadsheet::removeColumn (int col)
{
	verifyCol(col);
	--m_col;
        Spreadsheet tmp(m_row, m_col);
	
        for (int i = 0; i < m_row; ++i)
        {
                for (int j = 0; j < m_col; ++i)
                {
                        if (j < col)
                        {
                                tmp.setCellAt(i, j, m_cells[i][j]);
                        }
                        else if (j > col)
                        {
                                tmp.setCellAt(i, j, m_cells[i][j + 1]);
                        }	
		}
        }
	
        this->cleanup();
        this->moveFrom(tmp);
}

void Spreadsheet::swapColumns (int col_1, int col_2)
{
	verifyCol(col_1);
	verifyCol(col_2);

	for (int i = 0; i < m_row; ++i)
        {
                Cell tmp = m_cells[i][col_1];
                m_cells[i][col_1] = m_cells[i][col_2];
                m_cells[i][col_2] = tmp;
        }
}
