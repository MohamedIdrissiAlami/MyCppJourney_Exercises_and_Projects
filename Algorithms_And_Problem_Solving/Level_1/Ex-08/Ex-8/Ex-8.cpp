#include <iostream>
using namespace std;

template <typename T>
T ReadNumber(string Message)
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid number .
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\ninvalid input " << Message;

	}
	return Number;
}
template <typename T>
T ReadPositiveNumber(string Message)
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < 0)
			cout << "try again with a positive number..";

	} while (Number < 0);
	return Number;
}
template <typename T>
T ReadNumberInRange(T From, T To, string Message = "")
{
	T Number = 0;
	do
	{
		Number = ReadNumber<T>(Message);
	} while (Number<From || Number>To);
	return Number;
}

bool IsPass(float Mark)
{
	return Mark >= 50;
}

int main()
{
	cout << "\n" << (IsPass(ReadNumberInRange(0, 100, "\nEnter your mark : ")) ? "\nPass." : "\nFail.");
	system("pause>0");
	return 0;
}