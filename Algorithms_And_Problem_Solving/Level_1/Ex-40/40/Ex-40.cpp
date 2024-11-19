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

float ConvertHoursToDays(short Hours)
{
	return (float)Hours / 24;
}
float ConvertHoursToWeeks(short Hours)
{
	return (float) ConvertHoursToDays(Hours) / 7;
}
int main()
{
	short Hours = ReadPositiveNumber<short >("\n Hours = ");
	cout << "\n = " << ConvertHoursToWeeks(Hours)<<" weeks";
	cout << "\n = " << ConvertHoursToDays(Hours) <<" Days"<< endl;
	system("pause>0");
	return 0;
}
