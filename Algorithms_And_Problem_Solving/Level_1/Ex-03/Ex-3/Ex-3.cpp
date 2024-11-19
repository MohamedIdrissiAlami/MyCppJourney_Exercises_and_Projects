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

	} while (Number<0);
	return Number;
}

bool IsOdd(short Number)
{
	return (Number % 2) != 0;
}
bool IsEven(short Number)
{
	return !IsOdd(Number);
}

int main()
{
	printf(IsOdd(ReadNumber<short>("\nPlease Enter a number : ")) ? "Odd" : "Even");
	system("pause>0");
	return 0;
}