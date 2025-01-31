#include<iostream>
#include <string >
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid number 
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\ninvalid input ! try again with a valid number ...";
		cin >> Number;
	}
	return Number;

}

template <typename T>
T ReadPositiveNumber(string Message = "")
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < 0)
			cout << "\nout of range! try again..";
	} while (Number < 0);
	return Number;
}


template <typename T>
T ReadNumberBetween(T From, T To, string Message = "")
{
	T Number = 0;
	cout << Message;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < From || Number > To)
			cout << "\nout of range! try again..";
	} while (Number<From || Number>To);
	return Number;
}

bool IsLeapYear(short Year)
{
	return Year % 100 == 0 ? Year % 400 == 0 : Year % 4 == 0;
}


short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;
	short MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthDays[Month - 1];
}
bool IsValidYear(short Year)
{
	return Year > 1000 && Year < 3000;
}

bool IsValidMonth(short Month)
{
	return Month > 0 && Month <= 12;
}

bool IsValidDay(short Year, short Month, short Day)
{
	return Day >= 0 && Day <= NumberOfDaysInMonth(Year, Month);
}

bool IsValidDate(stDate Date)
{
	return IsValidYear(Date.Year) && IsValidMonth(Date.Month) && IsValidDay(Date.Year, Date.Month, Date.Day);
}

short ReadYear()
{
	short Year = 0;
	while (!IsValidYear(Year = ReadNumber<short>("\nEnter Year ? ")))
	{
		cout << "\ninvalid Year! try again..";
	}
	return Year;
}

short ReadMonth()
{
	short Year = 0;
	while (!IsValidMonth(Year = ReadNumber<short>("\nEnter Month ? ")))
		cout << "\ninvalid month! try again..";
	return Year;
}

short ReadDay(short Year, short Month)
{
	short Day = 0;
	while (!IsValidDay(Year, Month, Day = ReadNumber<short>("\nEnter Day ? ")))
		cout << "\ninvalid day! try again..";
	return Day;
}

stDate ReadDate(string Message = "")
{
	cout << Message;
	stDate Date;
	Date.Year = ReadYear();
	Date.Month = ReadMonth();
	Date.Day = ReadDay(Date.Year, Date.Month);
	return Date;

}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(stDate Date)
{
	return Date.Month == 12;
}



int main()
{
	stDate Date = ReadDate();
	IsLastMonthInYear(Date) ? cout << "\nyes,month is the last month in year ." : cout << "\nNo,month is not the last month in year.";
	IsLastDayInMonth(Date) ? cout << "\nyes,day is the last day in month ." : cout << "\nNo,day is not the last day in month.";

	system("pause>0");
	return 0;
}