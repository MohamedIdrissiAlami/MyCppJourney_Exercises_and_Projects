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

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumber(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
}

template<typename T>
T GetElementIndexInArray(T arr[], T ElementToCheck, short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		if (arr[i] == ElementToCheck)
		{
			return i;
		}
	}
	return -1;
}

bool IsNumberExistInArray(short arr[], short arrLength, short NumberToCheck)
{
	return GetElementIndexInArray<short>(arr, NumberToCheck, arrLength) != -1;
}

int main()
{
	short arrLength = ReadPositiveNumber<short>("\nEnter Array length : ");
	short* arr = new short[arrLength];
	FillArrayWithRandomNumber(arr, arrLength);
	cout << "\nthe following are array elements : \n";
	PrintArray(arr, arrLength);
	short NumberToCheck = ReadNumber<short>("\nEnter a number to search for : ");

	cout << "\nyou are looking for number  : " << NumberToCheck;
	cout << (IsNumberExistInArray(arr, arrLength, NumberToCheck) ? "\nYes,it's found!" : "\nNo it doesn't found!");

	system("pause>0");
	return 0;

}