#include <iostream >
using namespace std;

template<typename T>
T ReadNumber(string Message="")
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
		if ((Number=ReadNumber<T>(Message)) < 0)
			cout << "\nTry again with a positive..";
	} while (Number<0);
	return Number;
}

bool IsValidAge(short Age)
{
	return (Age >= 18 && Age <= 45);
}

int main()
{
	short Age = ReadPositiveNumber<short>("\nHow old are you ? ");
	cout << (IsValidAge(Age) ? "\nvalid age" : "\nInvalid age");
	system("pause>0");
	return 0;
}