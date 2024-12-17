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
short CalculateDigitFrequency(short DigitToCheck, int Number)
{
	short DigitFreqency = 0;
	while (Number > 0)
	{
		if (Number % 10 == DigitToCheck)
			DigitFreqency++;
		Number /= 10;
	}
	return DigitFreqency;
}

int main()
{
	int Number = ReadPositiveNumber<int>("\nPlease Enter a number : ");
	short DigitToCheck = ReadPositiveNumber<short>("\nEnter a digit To check : ");
	cout << "\ndigit " << DigitToCheck << " Frequency is " << CalculateDigitFrequency(DigitToCheck, Number) << " time(s)\n";
	system("pause>0");
	return 0;
}