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
	if (arrLength == 0)
	{
		cout << "\nempty array!";
		return;
	}
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

bool IsPrime(short Number)
{
	short HalfOfNumber = ceil(Number / 2);//The greatest common divisor of a number ,is always greater or equal its'half 
	for (short i = 2; i <= HalfOfNumber; i++)
	{
		if (Number % i == 0)
			return false;
	}
	//if you reached here this means that the number you're looking for is prime if it is not a '1';
	return (Number == 1) ? false : true;
}

void CopyPrimeNumbers(short OriginalArr[], short DestinationArr[], short arrLength,short &DestinationArrLength)
{
	DestinationArrLength = 0;
	for (short i = 0; i < arrLength; i++)
	{
		if (IsPrime(OriginalArr[i]))
		{
			DestinationArr[DestinationArrLength++] = OriginalArr[i];
			
		}
	}
}

int main()
{
	//seeds the random number generator in C++,called only once.
	srand((unsigned)time(NULL));
	short arrLength = ReadPositiveNumber<short>("\nHow many numbers do you wanna generate : "), DestinationArrLength=0;
	short* OriginalArray = new short[arrLength], * DestinationArray = new short[arrLength];
	FillArrayWithRandomNumbers(OriginalArray, arrLength);
	cout << "\narray elements are : ";
	PrintArray(OriginalArray, arrLength);

	CopyPrimeNumbers(OriginalArray, DestinationArray, arrLength, DestinationArrLength);
	cout << "\narray 2 elements after copy prime numbers only from array 1 : ";
	PrintArray(DestinationArray, DestinationArrLength);
	delete[]OriginalArray;
	delete[]DestinationArray;



	system("pause>0");

	return 0;
}