#include "cell.h"
#include <exception>

Cell::Cell ()
{
	m_value = " ";
	m_color = Color::White;
}

Cell::Cell (const std::string& value, Color& color)
{
	m_value = value;
	m_color = color;
}

void Cell::setValue (const std::string& value)
{
	m_value = value;
}

void Cell::setColor (Color& color)
{
	m_color = color;
}

std::string Cell::getValue () const
{
	return m_value;
}

Color Cell::getColor ()
{
	return m_color;
}

int Cell::toInt ()
{
	for (int i = 0; i < m_value.size(); ++i)
	{
		if (m_value[i] < '0' || m_value[i] > '9')
		{
			throw std::invalid_argument ("!Inconsistent parameter:");
			return -1;
		}
	}

	return std::stoi(m_value);
}

double Cell::toDouble ()
{
	int count = 0;

	for (int i = 0; i < m_value.size(); ++i)
	{
		if (m_value[i] < '0' || m_value[i] > '9')
		{
			++count;

			if (m_value[i] != '.')
			{
				 throw std::invalid_argument ("!Inconsistent parameter:");
                        	 return -1;
			}

			else if (count > 1)
			{
				 throw std::invalid_argument ("!Inconsistent parameter:");
                        	 return -1;
			}
		}
	}

	return std::stod(m_value);
}

Date Cell::toDate ()
{
	Date d(m_value);

	return d;
}

void Cell::reset ()
{
	m_value = " ";
	m_color = Color::White;
}
