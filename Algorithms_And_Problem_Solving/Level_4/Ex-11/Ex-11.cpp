#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct stDate
{
	short Day = 1;
	short Month = 1;
	short Year = 2000;
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
			cout << "\ntry again..";
			cin >> Number;
		}
	} while (Number < 0);
	return Number;
}

short ReadNumberInRange(short From,short To ,string Message = "")
{
	short Number=0;
	do
	{
		cout << Message;
		cin >> Number;
		while (cin.fail())
		{
			//user didn't input a valid  number ; 
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\ninvalid input ,try again ..";
			cin >> Number;
		}
	} while (Number<From||Number>To);
	return Number;
}

short NumberOfDaysInAMonth(short , short );

stDate ReadDate(string Message)
{
	stDate Date;
	Date.Year = ReadPositiveNumber("\nPlease enter a Year : ");
	Date.Month = ReadNumberInRange(1,12,"\nPlease enter a month : ");
	Date.Day = ReadNumberInRange(1,NumberOfDaysInAMonth(Date.Year,Date.Month), "\nPlease enter a day : ");
	return Date;
}

short DayOrderOfWeek(short Day, short Month, short Year)
{
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
}

string DayShortName(short DayOrderOfWeek)
{
	string DayName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return DayName[DayOrderOfWeek];
}

bool IsLeapYear(short Year)
{
	/*all years whick are perfectly divisible by 4 are leap years,
	exept for centry years(Years ending with 00),which are leap years only if they are perfectly divisible by 400*/
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;
	short MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return IsLeapYear(Year) ? ((Month == 2) ? 29 : MonthDays[Month - 1]) : MonthDays[Month - 1];
}

stDate DateFromDayOrderInYear(short Year,short dayOrderYear)
{
	short RemainingDays = dayOrderYear;
	stDate sDate;
	sDate.Year = Year;
	for (short i = 1; i <= 12; i++)
	{
		sDate.Month = i;
		if (RemainingDays >= NumberOfDaysInAMonth(Year, i))
		{
			
			RemainingDays -= NumberOfDaysInAMonth(Year, i);

		}
		else
		{
			sDate.Day = RemainingDays;
			break;
		}
	}
	return sDate;
}

short DaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
	short YearDays = 0;
	for (short i = 1; i < Month; i++)
	{
		YearDays += NumberOfDaysInAMonth(Year, i);
	}
	return YearDays + Day;
}

short DaysFromTheBeginningOfTheYear(stDate Date)
{
	return DaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
}

string DateString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
	stDate Date = ReadDate("\n");
	short YearDays = DaysFromTheBeginningOfTheYear(Date);
	cout << "\nNumber of days from the beginning of the year : " << YearDays;
	cout << "\ndate for [" << YearDays << "] is : " << DateString(DateFromDayOrderInYear(Date.Year, YearDays));


	system("pause>0");
	return 0;
}
