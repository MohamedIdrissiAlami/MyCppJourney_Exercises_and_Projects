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

void PrintNumbersFromNTo1(short Number)
{
	cout << "\n";
	while (Number > 0)
	{
		cout << Number-- << " ";
	}
}

int main()
{
	PrintNumbersFromNTo1(ReadPositiveNumber<short>("\nEnter a number : "));
	system("pause>0");
	return 0;
}