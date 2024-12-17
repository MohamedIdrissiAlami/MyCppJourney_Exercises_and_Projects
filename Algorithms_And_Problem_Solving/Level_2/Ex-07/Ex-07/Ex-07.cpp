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

int ReverseNumber(int Number)
{
	int RevNumber = 0;
	while (Number > 0)
	{
		RevNumber = RevNumber * 10 + Number % 10;
		Number /= 10;

	}
	return RevNumber;
}

int main()
{
	int Number = ReadPositiveNumber<int >("\nEnter a number : ");
	cout << "\nhere is your number in a reverse order : " << ReverseNumber(Number) << endl;
	system("pause>0");
	return 0;
}