#pragma warning (disable : 4996)
#include<iostream>
#include <string >
#include <ctime>
#include <vector>
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

string DateToString(stDate Date)
{
	return DayShortName(DayOrderOfWeek(Date)) + " " + to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

vector<string>SplitString(string S1, string Delim = " ")
{
	string sWord = "";
	short Pos = 0;
	vector<string>vSplit;
	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != "")
			vSplit.push_back(sWord);
		S1.erase(0, Pos + Delim.length());
	}
	if (S1 != "")
	{
		vSplit.push_back(S1);
	}
	return vSplit;
}

stDate StringToDate(string DateString)
{
	stDate Date;
	vector <string> vDate;
	vDate = SplitString(DateString, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);
	return Date;
}

string ReadString(string Message = "")
{
	cout << Message;
	string S1;
	getline(cin >> ws, S1);
	return S1;
}

int main()
{
	string sDate = ReadString("\nPlease enter date dd/mm/yyyy? ");
	stDate Date = StringToDate(sDate);
	cout << "\nDay : " << Date.Day;
	cout << "\nMonth : " << Date.Month;
	cout << "\nYear : " << Date.Year;
	cout << "\nyou entered : " << DateToString(Date) << endl;
	system("pause>0");
	return 0;
}
