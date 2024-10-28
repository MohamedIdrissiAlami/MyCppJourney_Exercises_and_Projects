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
T Max(T Number1, T Number2)
{
	return (Number1 >= Number2) ? Number1 : Number2;
}
template <typename T>
T Max(T Number1, T Number2, T Number3)
{
	T Max1 = 0;
	return ((Max1 = Max(Number1, Number2)) >= Number3) ? Max1 : Number3;
}

int main()
{
	short Number1 = ReadNumber<short>("\nNumber1 = "), Number2 = ReadNumber<short>("\nNumber2 = ")
		, Number3 = ReadNumber<short>("\nNumber3 = ");
	cout << "\n max = " << Max<short>(Number1, Number2,Number3) << endl;
	system("pause>0");
	return 0;
}