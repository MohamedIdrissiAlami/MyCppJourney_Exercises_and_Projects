#include <iostream>
using namespace std;

template<typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't enter a valid number ...
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input try again ..";
		cin >> Number;
	}
	return Number;
}

template <typename T>
T ReadPositiveNumber(string Message = "\nEnter a positive Number : ")
{
	T Number = 0;
	while ((Number = ReadNumber<T>(Message)) < 0)
	{
		cout << "\nyou have entered a negative number try again with a positive input!";
	}
	return Number;
}

void PrintNumberPattern(short Number)
{
	for (short i = 1; i <= Number; i++)
	{
		for (short j = 1; j <= i; j++)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}

int main()
{
	PrintNumberPattern(ReadPositiveNumber<short>());
	system("pause>0");
	return 0;
}