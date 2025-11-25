#pragma once
#include<string>
#include <stdexcept>
using namespace std;

class Date
{

private:
	short year;
	short month;
	short day;

	//Pre-condition: year (private) > 0
	//Post-condition return true if year is leap else false
	bool isLeapYear()
	{
		return  ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}

public:
	
	//Default (no-argument) Constructor
	Date() :year(1), month(1), day(1)
	{ }

	//Argument Constructor
	Date(short y, short m, short d)
	{
		setYear(y);
		setMonth(m);
		setDay(d);
	}


	//Pre-condition: y > 0
	//Post-condition set year (private)
	void setYear(short y)
	{
		if (y < 1  || y > 9999)
			throw runtime_error("Exception ERROR: Year is not within range from 1 to 9999.\n");
		else
			year = y;
	}

	//Pre-condition: NA
	//Post-condition return year (private)
	short getYear() const
	{
		return year;
	}

	//Pre-condition: m > 0
	//Post-condition set month (private)
	void setMonth(short m)
	{
		if (m < 1  || m > 12)
			throw runtime_error("Exception ERROR: Month is not within range from 1 to 12.\n");
		else
			month = m;
	}

	//Pre-condition: NA
	//Post-condition return month (private)
	short getMonth() const
	{
		return month;
	}

	//Pre-condition: d > 0
	//Post-condition set day (private)
	void setDay(short d)
	{
		short maxDaysInMonth[12] = {31, 28, 31,30,31,30,31,31,30,31,30,31 };

		if (d < 1)
			throw runtime_error("Exception ERROR: Day cannot be less than 1.");
		else
		{
			short maxDay = (isLeapYear() && month == 2 ? maxDaysInMonth[month - 1] + 1 : maxDaysInMonth[month - 1]);
			
			if (d > maxDay)
				throw runtime_error("Exception ERROR: Day is not within range from 1 to " + to_string(maxDay) + ".");
			else
				day = d;
			
		}
	}

	//Pre-condition: NA
	//Post-condition return day (private)
	short getDay() const
	{
		return day;
	}

	//Pre-condition: Date right obj
	//Post-condition return true if current obj == right obj, else false
	bool operator==(const Date& obj) const
	{
		//YOU WILL IMPLEMENT TO CHECK if two dates are the same value
		return false;
	}
	
	//Pre-condition: Date right obj
	//Post-condition return true if current obj < right obj, else false
	bool operator<(const Date& obj) const
	{
		//YOU WILL IMPLEMENT TO CHECK if left date value is less than the right date
		return false;
	}

	//Pre-condition: Date right obj
	//Post-condition return string "monthname day, year" 
	friend ostream& operator<<(ostream& out, const Date& obj);

	
};

ostream& operator<<(ostream& out, const Date& obj)
{
	string monthNames[13] = { "unknown", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	
	string order = "th";

	switch (obj.day)
	{
	case 1:
	case 21:
	case 31:
		order = "st";
		break;
	case 2:
	case 22:
		order = "nd";
		break;
	case 3:
	case 23:
		order = "rd";
		break;
	default:
		order = "th";

	}

	out << monthNames[obj.month] << " " << obj.day << order << ", " << obj.year;
	return out;
}

