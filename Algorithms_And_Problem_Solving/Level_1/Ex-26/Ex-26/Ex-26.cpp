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

void PrintNumbersFrom1ToN(short Number)
{
	cout << "\n";
	for (short i = 1; i <= Number; i++)
	{
		cout << i << " ";

	}
}

int main()
{
	PrintNumbersFrom1ToN(ReadPositiveNumber<short>("\nEnter a number : "));
	system("pause>0");
	return 0;
}