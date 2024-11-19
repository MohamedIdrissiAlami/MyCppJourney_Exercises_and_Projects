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

enum enDayOfWeek{eSun=1,eMon,eTue,eWed,eThu,eFri,eSat};
enDayOfWeek ReadDayOfWeek()
{
	return (enDayOfWeek)ReadNumberInRange<short>(1, 7, "\nenter day number : 1 sunday,2 monday,3 tuesday,4 wednesday,5 thursday,6 friday,7 saturday : ");

}
string GetDayOfWeek(enDayOfWeek DayOfWeek)
{
	switch (DayOfWeek)
	{
	case eSun:
		return "Sunday";
		break;
	case eMon:
		return "Monday";
		break;
	case eTue:
		return "Tuesday";
		break;
	case eWed:
		return "Wednesday";
		break;
	case eThu:
		return "Thursday";
		break;
	case eFri:
		return "Friday";
		break;
	case eSat:
		return "Saturday";
		break;
	default:
		return "Not a valid day";
		break;
	}
}

int main()
{
	string DayName = GetDayOfWeek(ReadDayOfWeek());
	cout << "\nit is  " << DayName << endl;
	system("pause>0");
	return 0;
}