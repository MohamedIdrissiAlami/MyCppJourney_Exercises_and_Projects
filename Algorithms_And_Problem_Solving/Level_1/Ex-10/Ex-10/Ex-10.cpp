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

template <typename T>
T Sum(T Number1, T Number2, T Number3)
{
	return Number1 + Number2 + Number3;
}


float AverageOf3Marks(short Mark1, short Mark2, short Mark3)
{
	return (float)Sum<short>(Mark1, Mark2, Mark3) / 3;
}

int main()
{
	cout << "\nEnter 3 markes : ";
	short Mark1 = ReadNumberInRange<short>(0, 100, "\nNumber 1 = "), Mark2 = ReadNumberInRange<short>(0, 100, "\nNumber 2 = "), Mark3 = ReadNumberInRange<short>(0, 100, "\nNumber 3 = ");
	cout << "\nAverage = " << AverageOf3Marks(Mark1, Mark2, Mark3) << endl;
	system("pause>0");
	return 0;
}
