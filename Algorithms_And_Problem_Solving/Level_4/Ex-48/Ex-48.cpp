#pragma warning (disable : 4996)
#include<iostream>
#include <string >
#include <ctime>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
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

stPeriod ReadPeriod(string StartDateMessage = "", string EndDateMessage = "")
{
	stPeriod Period;
	Period.StartDate = ReadDate(StartDateMessage);
	Period.EndDate = ReadDate(EndDateMessage);
	return Period;
}

short DayOrderOfWeek(short Day, short Month, short Year)
{
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
}

short DayOrderOfWeek(stDate Date)
{
	return DayOrderOfWeek(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOrderOfWeek)
{
	string DayName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return DayName[DayOrderOfWeek];
}

string DateString(stDate Date)
{
	return DayShortName(DayOrderOfWeek(Date)) + " " + to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

bool IsDateBeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year <= Date2.Year) ? ((Date1.Year < Date2.Year) ? true :
		(Date1.Month <= Date2.Month) ? (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : true : false) : false;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !(IsDateBeforeDate2(Date1, Date2) || IsDate1EqualDate2(Date1, Date2));
}

enum enCompareResult{eBefore=-1,eEquals=0,eAfter=1};

enCompareResult CompareDates(stDate Date1, stDate Date2)
{
	return IsDateBeforeDate2(Date1, Date2) ? enCompareResult::eBefore : IsDate1EqualDate2(Date1, Date2) ? enCompareResult::eEquals: enCompareResult::eAfter;
}

int  main()
{
	stDate Date1 = ReadDate("\nEnter Date 2 :\n"), Date2 = ReadDate("\nEnter Date 1 : \n");

	switch (CompareDates(Date1,Date2))
	{
	case enCompareResult::eBefore:
		cout << "\nDate 1 is before Date 2.";
		break;
	case enCompareResult::eEquals:
		cout << "\nDate 1 equals date 2.";
		break;
	case enCompareResult::eAfter:
		cout << "\nDate 1 is after Date 2.";
		break;
	default:
		break;
	}
	system("pause>0");
	return 0;
}
