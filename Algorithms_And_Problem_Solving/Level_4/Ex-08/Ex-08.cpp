#include <iostream>
#include <cstdio>
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

short DayOrderOfWeek(short Day, short Month, short Year)
{
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;
	return (Day + y+ (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
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

string MonthShortName(short Month)
{
	string MonthName[12] = { "Jan","Feb","Mar","Apr","Mai","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return MonthName[Month - 1];
}

void PrintMonthCalendar(short Year, short  Month)
{
	short Current = DayOrderOfWeek(1, Month, Year);
	short MonthDays = NumberOfDaysInAMonth(Year, Month);
	//print  column : 

	printf("\n________________________%s_________________________\n",MonthShortName(Month).c_str());
	cout << "    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n";
	short i = 0;
	for (i = 0; i < Current; i++)
	{
		printf("       ");
	}
	for (short j = 1; j <= MonthDays; j++)
	{
		printf("%7d",j);
		if (++i == 7)
		{
			cout << endl<<endl;
			i = 0;
		}
	}
	printf("\n____________________________________________________\n");


}

int main()
{
	short Month = ReadPositiveNumber("\nenter a month number : ");
	PrintMonthCalendar(2024,Month);
	system("pause>0");
	return 0;
}
