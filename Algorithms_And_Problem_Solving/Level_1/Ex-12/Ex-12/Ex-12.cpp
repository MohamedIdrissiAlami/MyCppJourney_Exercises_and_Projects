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

int main()
{
	short Number1 = ReadNumber<short>("\nNumber1 = "), Number2 = ReadNumber<short>("\nNumber2 = ");
	cout << "\n max = " << Max<short>(Number1, Number2) << endl;
	system("pause>0");
	return 0;
}