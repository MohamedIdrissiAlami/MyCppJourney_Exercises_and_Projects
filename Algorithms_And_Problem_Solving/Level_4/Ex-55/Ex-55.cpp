#pragma warning (disable:4996)
#include <iostream >
#include <ctime>
using namespace std;

struct stDate
{
	short Year = 2000;
	short Month = 1;
	short Day = 1;

};

short ReadPositiveNumber(string Message = "")
{
	short Number = 0;
	do
	{
		cout << Message;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n you 've entered a wrong input ,try again..";
			cin >> Number;
		}
	} while (Number<0);
	return Number;
}

short ReadNumberInRange(short From,short To,string Message = "")
{
	short Number = 0;
	do
	{
		cout << Message;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n you 've entered a wrong input ,try again..";
			cin >> Number;
		}
	} while (Number <From||Number>To);
	return Number;
}

bool IsLeapYear(short Year)
{
	return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return -1;
	short MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? IsLeapYear(Year)? 29:28 : MonthDays[Month - 1];
}

stDate  ReadDate(string  Message = "")
{
	stDate Date;
	cout << Message;
	Date.Year = ReadPositiveNumber("\nEnter a year : ");
	Date.Month = ReadNumberInRange(1, 12, "\nEnter a month : ");
	Date.Day = ReadNumberInRange(1, NumberOfDaysInAMonth(Date.Year, Date.Month),"\nEnter a Day : ");
	return Date;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate Temp;
	Temp.Day = Date1.Day;
	Temp.Month = Date1.Month;
	Temp.Year = Date1.Year;

	Date1.Day = Date2.Day;
	Date1.Month = Date2.Month;
	Date1.Year = Date2.Year;

	Date2.Day = Temp.Day;
	Date2.Month = Temp.Month;
	Date2.Year = Temp.Year;
}

bool IsDateBeforeDate2(stDate Date1, stDate Date2)
{
	return ((Date1.Year <= Date2.Year) ? ((Date1.Year<Date2.Year)? true: ((Date1.Month<=Date2.Month)? ((Date1.Month<Date2.Month)? true:(Date1.Day<Date2.Day) ) : false)) : false);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month);
}

void IncreaseDateByOneDay(stDate &Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			++Date.Year;
			Date.Month = 1;
		}
		else
		{
			++Date.Month;
		}
		Date.Day = 1;
	}
	else
		++Date.Day;
}

short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay)
{
	short TotalDays = 0;
	short SwapFlagValue = 1;
	if (!IsDateBeforeDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
	}
	while (IsDateBeforeDate2(Date1, Date2))
	{
		IncreaseDateByOneDay(Date1);
		++TotalDays;
	}
	return IncludeEndDay ? SwapFlagValue * TotalDays : ++TotalDays * SwapFlagValue;
}

short GetAgeInDays(stDate BirthDate, stDate SystemDate)
{
	return GetDifferenceInDays(BirthDate, SystemDate, true);
}

int GetAgeInSeconds(stDate BirthDate, stDate SystemDate)
{
	return 24 * 3600 * GetAgeInDays(BirthDate, SystemDate);
}

stDate GetSystemDate()
{
	time_t t = time(0);//get time now.
	tm* now = localtime(&t);
	stDate Date;
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	
	return Date;
}

int main()
{
	stDate BirthDate = ReadDate("\nPlease enter birth date : \n");
	stDate SystemDate = GetSystemDate();
	cout << "\nYour age in days is : " << GetAgeInDays(BirthDate, SystemDate);
	cout << "\nyour age in seconds is : " << GetAgeInSeconds(BirthDate, SystemDate);
	system("pause>0");
	return 0;
}


//the end.
//Dev.Mohammed Idrissi-Alami