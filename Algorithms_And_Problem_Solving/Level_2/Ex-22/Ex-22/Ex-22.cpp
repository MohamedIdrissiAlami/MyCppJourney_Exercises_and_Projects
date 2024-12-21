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

void ReadArrayElements(short arr[], short arrLength)
{
	cout << "\ninsert array elements : ";
	for (short i = 0; i < arrLength; i++)
	{
		cout << "\nElement [" << i + 1 << "] : ";
		arr[i] = ReadNumber<short>("");
	}
}

void PrintArray(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
}

short TimesRepeated(short NumberToCheck, short arr[], short arrLength)
{
	short Counter = 0;
	for (short i = 0; i < arrLength; i++)
	{
		if (arr[i] == NumberToCheck)
			++Counter;
	}
	return Counter;
}

int main()
{
	short arrLength = ReadPositiveNumber<short>("\nHow many numbers do you wanna insert in array ? ");
	short *arr=new short[arrLength];
	ReadArrayElements(arr, arrLength);
	short NumberToCheck = ReadNumber<short>("\nEnter The number you want to check : ");
	cout << "\nOriginal array : ";
	PrintArray(arr, arrLength);
	cout << "\n" << NumberToCheck << " is repeated " << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)\n";


	delete []arr;
	system("pause>0");
	return 0;
}