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
	for (short i = 0; i < arrLength; i++)
	{
		cout << "\nElement[" << i + 1 << "] : ";
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

bool IsPalindromeArray(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength / 2; i++)
	{
		if (arr[i] != arr[arrLength - 1 - i])
			return false;
	}
	//if you reached here this means that the array is palindrome
	return true;
}

int main()
{
	short arrLength = ReadPositiveNumber<short>("\nenter array length : "), * arr = new short[arrLength];
	cout << "\nInsert Array elements : ";
	ReadArrayElements(arr, arrLength);
	cout << "\nthe following are the array elements : \n";
	PrintArray(arr, arrLength);
	cout << "\n" << (IsPalindromeArray(arr,arrLength)? "Yes,the array is \'Palindrome\'":"No,the array is \'Not\' Palindrome") << endl;
	delete[]arr;
	system("pause>0");
	return 0;
}