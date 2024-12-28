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

void AddArrayElement(short Number, short arr[100], short& arrLength)
{
	arr[arrLength] = Number;
	arrLength++;
}


bool IsNumberExistsInArray(short arr[], short arrLength,short NumberToCheck)
{
	for (short i = 0; i < arrLength; i++)
	{
		if (arr[i] == NumberToCheck)
		{
			return true;
		}
	}
	//if you reached here this means that the number you're looking for doesn't exist
	return false;

}

void CopyDistinctNumbersFromArray(short ArrSource[], short DestinationArr[], short arrSourceLength, short& arrDestinationLength)
{

	for (short i = 0; i < arrSourceLength; i++)
	{
		if (!IsNumberExistsInArray(DestinationArr,arrDestinationLength,ArrSource[i]))
		{
			AddArrayElement(ArrSource[i], DestinationArr, arrDestinationLength);
		}
	}
}

int main()
{


	//seeds the random number generator in C++,called only once.
	srand((unsigned)time(NULL));
	short arr1[100], arr2[100], arr1Length = ReadNumber<short>("\nhow many numbers do you wanna generate : "), arr2Length = 0;
	FillArrayWithRandomNumbers(arr1, arr1Length);
	cout << "\nthe following are array1 elements : \n";
	PrintArray(arr1, arr1Length);
	CopyDistinctNumbersFromArray(arr1, arr2, arr1Length, arr2Length);
	cout << "\nthe following are array2 elements : \n";
	PrintArray(arr2, arr2Length);
	system("pause>0");

	return 0;
}




