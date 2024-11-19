#include <iostream >
using namespace std;

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user did'nt input a valid number:
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input ! " << Message;

	}
	return Number;
}
template <typename T>
T ReadPositiveNumber(string Message = "")
{
	T Number = 0;
	do
	{
		Number = ReadNumber<T>(Message);
		if (Number <= 0)
			cout << "\ntry again with a positive number..";
	} while (Number < 0);
	return Number;
}

int SumUntil(short BreakNumber=-99)
{
	int Sum = 0;
	short Number = 0;
	while ((Number = ReadNumber<short>("\n")) != BreakNumber)
	{
		Sum += Number;
	}
	return Sum;
}

int main()
{
	cout << "\nSum = " << SumUntil(-99) << endl;
	system("pause>0");
	return 0;
}
