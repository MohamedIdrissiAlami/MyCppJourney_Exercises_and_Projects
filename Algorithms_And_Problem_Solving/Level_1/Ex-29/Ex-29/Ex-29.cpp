#include <iostream >
using namespace std;

template<typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid number.
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input! " << Message;
	}
	return Number;
}
template<typename T>
T ReadPositiveNumber(string Message = "")
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < 0)
			cout << "\nTry again with a positive..";
	} while (Number < 0);
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
short SumEvenNumbersFrom1ToN(short Number)
{
	short Sum = 0;
	while (Number > 0)
	{
		if (IsEven(Number))
			Sum += Number;
		--Number;
	}
	return Sum;
}

int main()
{
	short Sum = SumEvenNumbersFrom1ToN(ReadPositiveNumber<short>("\nEnter a number : "));
	cout << "\nSum = " << Sum << endl;;
	system("pause>0");
	return 0;
}