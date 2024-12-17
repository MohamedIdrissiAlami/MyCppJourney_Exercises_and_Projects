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
	short DigitFrequency = 0;
	while (Number > 0)
	{
		if (Number % 10 == DigitToCheck)
		{
			DigitFrequency++;
		}
		Number /= 10;
	}
	return DigitFrequency;
}

void PrintAllDigitsFrequencies(int Number)
{
	short CurrentDigitFreq = 0;
	for (short i = 0; i < 10; i++)
	{
		if ((CurrentDigitFreq = CalculateDigitFrequency(i, Number)) > 0)
		{
			cout << "\nDigit " << i << " Frequency is " << CurrentDigitFreq << " time(s)";
		}
	}
}

int main()
{
	PrintAllDigitsFrequencies(ReadPositiveNumber<int>("\nEnter A number : "));
	system("pause>0");
	return 0;
}