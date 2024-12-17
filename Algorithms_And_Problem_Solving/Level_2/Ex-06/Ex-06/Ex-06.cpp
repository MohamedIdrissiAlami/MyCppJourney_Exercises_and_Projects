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

short SumOfDigits(short Number)
{
	short SumOfDigits = 0;
	while (Number > 0)
	{
		SumOfDigits += Number % 10;
		Number /= 10;
	}
	return SumOfDigits;
}

int main()
{
	short Number = ReadPositiveNumber<short >("\nEnter a number : ");
	cout << "\n sum of its digits : " << SumOfDigits(Number) << endl;
	system("pause>0");
	return 0;

}