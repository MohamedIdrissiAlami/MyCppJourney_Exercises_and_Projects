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

bool IsPrime(short Number)
{
	short Counter = 2;
	while (Counter <= Number / 2)
	{
		if (Number % Counter++ == 0)
			return false;
	}

	return Number == 1 ? false : true;
}

int main()
{
	cout << "\n" << (IsPrime(ReadNumber<short>("Enter a number : "))? "prime" : "not prime") << endl;

	system("pause>0");
	return 0;
}