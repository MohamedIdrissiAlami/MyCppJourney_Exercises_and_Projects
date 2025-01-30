#include <iostream>
using namespace std;

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
	return IsLeapYear(Year) ? ((Month==2)? 29: MonthDays[Month-1]) : MonthDays[Month-1];
}

short NumberOfHoursInAMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
	return NumberOfMinutesInAMonth(Year, Month) * 60;
}

int main()
{

	short Year = ReadPositiveNumber("\nEnter A year : ");
	short Month = ReadPositiveNumber("\nEnter A month : ");
	cout << "\nDays : " << NumberOfDaysInAMonth(Year, Month);
	cout << "\nHours : " << NumberOfHoursInAMonth(Year, Month);
	cout << "\nMinutes : " << NumberOfMinutesInAMonth(Year, Month);
	cout << "\nSeconds : " << NumberOfSecondsInAMonth(Year, Month);
	system("pause>0");
	return 0;
}
