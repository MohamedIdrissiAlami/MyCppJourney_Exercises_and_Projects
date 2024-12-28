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

void AddArrayElement(short Number, short arr[100], unsigned short& arrLength)
{
	arr[arrLength++] = Number;
}

void AddElementsToArray(short arr[100], unsigned short& arrLength)
{
	char Answer= 'n';
	do
	{
		 
		AddArrayElement(ReadNumber<short>("\nenter a number : "),arr,arrLength)	;
		cout << "\ndo you want to enter more numbers ? [Y/N] ";
		cin >> Answer;
	} while (tolower(Answer)=='y');
}

void PrintArray(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	unsigned short arrLength = 0;
	short arr[100];
	AddElementsToArray(arr, arrLength);
	cout << "\narray length : " << arrLength << endl;
	cout << "\narray elements : ";
	PrintArray(arr, arrLength);
	system("pause>0");
	return 0;
}