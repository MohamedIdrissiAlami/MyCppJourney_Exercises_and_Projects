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

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;;
}

void PrintArray(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
}

void FillArrayWithRandomNumbers(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

short SumOfArrayElements(short arr[], short arrLength)
{
	short Sum = 0;
	for (short i = 0; i < arrLength; i++)
		Sum += arr[i];

	return Sum;
}

float averageOfArrayElements(short arr[], short arrLength)
{
	return (float)SumOfArrayElements(arr, arrLength)/arrLength;
}

int main()
{
	//seeds the random number generator in C++,called only once.
	srand((unsigned)time(NULL));
	short arrLength = ReadPositiveNumber<short>("\nHow many numbers do you wanna generate : ");
	short* arr = new short[arrLength];
	FillArrayWithRandomNumbers(arr, arrLength);
	PrintArray(arr, arrLength);
	cout << "\nthe average of all array elements is  : " << averageOfArrayElements(arr, arrLength);


	delete[]arr;

	system("pause>0");

	return 0;
}