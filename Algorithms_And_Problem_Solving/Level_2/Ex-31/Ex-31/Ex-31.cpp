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

void FillArrayWithOrderedNumbers(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		arr[i] = i + 1;
	}
}


void Swap(short &item1, short &item2)
{
	short temp=item1;
	item1 = item2;
	item2 = temp;
}

void ShuffleArray(short arr[], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		Swap(arr[i], arr[RandomNumber(0, arrLength - 1)]);
	}
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
	//seeds the random numbers generator in C++,called only once.
	srand((unsigned)time(NULL));
	short arrLength = ReadPositiveNumber<short>("\nEnter the array's length : ");
	short* arr =new short[arrLength];
	FillArrayWithOrderedNumbers(arr, arrLength);
	cout << "\nArray elements before shuffle : \n";
	PrintArray(arr, arrLength);

	ShuffleArray(arr, arrLength);
	cout << "\nArray elements after shuffle : \n";
	PrintArray(arr, arrLength);


	delete[]arr;
	system("pause>0");
	return 0;
}