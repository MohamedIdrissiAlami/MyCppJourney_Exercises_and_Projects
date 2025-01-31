#pragma warning (disable : 4996)
#include <ctime>
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

string DateString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

void IncreaseDateByOneDay(stDate& Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Year++;
			Date.Month = 1;
		}
		else
			Date.Month++;
		Date.Day = 1;
	}
	else
		Date.Day++;
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year <= Date2.Year) ? ((Date1.Year < Date2.Year) ? true :
		(Date1.Month <= Date2.Month) ? (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : true : false) : false;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate temp;
	temp.Day = Date1.Day;
	temp.Month = Date1.Month;
	temp.Year = Date1.Year;

	Date1.Day = Date2.Day;
	Date1.Month = Date2.Month;
	Date1.Year = Date2.Year;

	Date2.Day = temp.Day;
	Date2.Month = temp.Month;
	Date2.Year = temp.Year;
}

short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludingEndDate = 0)
{
	short DiffDays = 0;
	short SwapFlagValue = 1;

	if (!IsDate1LessThanDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
	}

	while (IsDate1LessThanDate2(Date1, Date2))
	{
		IncreaseDateByOneDay(Date1);
		DiffDays++;
	}
	return IncludingEndDate ? ++DiffDays * SwapFlagValue : DiffDays * SwapFlagValue;
}

stDate GetSystemDate()
{
	stDate systemDate;
	time_t t = time(0);//get time now 
	tm* now = localtime(&t);

	systemDate.Year = now->tm_year + 1900;
	systemDate.Month = now->tm_mon + 1;
	systemDate.Day = now->tm_mday;
	return systemDate;

}

short GetAgeInDays(stDate BirthDate, stDate ActualDate)
{
	return GetDifferenceInDays(BirthDate, ActualDate, true);
}
int main()
{
	stDate BirthDate = ReadDate("\nPlease enter your date of birth : \n");
	cout << "\nyour age in days is : " << GetAgeInDays(BirthDate, GetSystemDate());
	system("pause>0");
	return 0;
}