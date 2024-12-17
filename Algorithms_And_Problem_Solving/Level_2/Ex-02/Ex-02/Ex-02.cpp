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
	while ((Number=ReadNumber<T>(Message)) < 0)
	{
		cout << "\nyou have entered a negative number try again with a positive input!";
	}
	return Number;
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
	return (Number==1)? false:true;
}

void PrintAllPrimeNumbers(short From,short To)
{
	for (short i = From; i <= To; i++)
	{
		if (IsPrime(i))
		{
			cout << " " << i << " ";
		}
	}

}

int main()
{
	short Number = ReadPositiveNumber<short>();
	cout << "\nThe following are the prime number from 1 to : " << Number<<endl;
	PrintAllPrimeNumbers(1,Number);

	system("pause>0");
	return 0;
}