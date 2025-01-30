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
	} while (Number<0);
	return Number;
}

bool IsLeapYear(short Year)
{
	/*all years which are perfectly divisible by 4 are leap years,
	except for century years(Years ending with 00),which are leap years only if they are perfectly divisible by 400*/
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short  Year)
{
	return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}

int main()
{
	short Year = 2024;

	cout << "\nDays : " << NumberOfDaysInAYear(Year);
	cout << "\nHours : " << NumberOfHoursInYear(Year);
	cout << "\nMinutes : " << NumberOfMinutesInYear(Year);
	cout << "\nSeconds : " << NumberOfSecondsInYear(Year);
	system("pause>0");
	return 0;
}
