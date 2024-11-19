#include <iostream>
using namespace std;

template <typename T>
T ReadNumber(string Message)
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid number .
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\ninvalid input " << Message;

	}
	return Number;
}
template <typename T>
T ReadPositiveNumber(string Message)
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < 0)
			cout << "try again with a positive number..";

	} while (Number < 0);
	return Number;
}
template <typename T>
T ReadNumberInRange(T From, T To, string Message = "")
{
	T Number = 0;
	do
	{
		Number = ReadNumber<T>(Message);
	} while (Number<From || Number>To);
	return Number;
}

enum MonthOfYear { Jan = 1, Feb, Mar, Apr, Mai, Jun, Jul,Aug,Sep,Oct,Nov,Dec };
MonthOfYear ReadMonthOfYear()
{
	return (MonthOfYear)ReadNumberInRange<short>(1, 12, "\nenter month number : ");

}
string GetMonthOfYear(MonthOfYear MonthOfYear)
{
	switch (MonthOfYear)
	{
	case Jan:
		return "January";
	case Feb:
		return "February";
	case Mar:
		return "March";
	case Apr:
		return "April";
	case Mai:
		return "Mai";
	case Jun:
		return "June";
	case Jul:
		return "Jully";
	case Aug:
		return "August";
	case Sep:
		return "September";
	case Oct:
		return "October";
	case Nov:
		return "November";
	case Dec:
		return "December";
	default:
		return "Not a valid month.";
	}
}

int main()
{
	string MonthOfYear = GetMonthOfYear(ReadMonthOfYear());
	cout << "\nit is  " << MonthOfYear << endl;
	system("pause>0");
	return 0;
}