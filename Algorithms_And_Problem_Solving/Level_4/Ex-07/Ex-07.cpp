#include <iostream>
using namespace std;

short DayOrderOfWeek(short Day, short Month, short Year)
{
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;
	return (Day + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
}

string DayShortName(short DayOrderOfWeek)
{
	string DayName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return DayName[DayOrderOfWeek];
}

int main()
{
	cout << "\nI was born on a " << DayShortName(DayOrderOfWeek(24, 9, 2002));

	system("pause>0");
	return 0;
}
