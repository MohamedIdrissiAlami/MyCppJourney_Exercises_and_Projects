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
bool IsPerfect(short Number)
{
	short SumOfDivisors = 0, HalfOfNumber = ceil(Number / 2);
	for (short i = 1; i <= HalfOfNumber; i++)
	{
		if (Number % i == 0)
		{
			SumOfDivisors += i;
		}
	}
	return (Number == SumOfDivisors) ? true : false;
}

void PrintPerfectNumbers(short Number)
{
	for (short i = 1; i <= Number; i++)
	{
		if (IsPerfect(i))
			cout << " " << i << " ";
	}
}

int main()
{
	short Number = ReadPositiveNumber<short>("\nEnter a number : ");
	cout << "\n the following are the perfect numbers less or equal to " << Number << "\n";
	PrintPerfectNumbers(Number);
	system("pause>0");
	return 0;

}