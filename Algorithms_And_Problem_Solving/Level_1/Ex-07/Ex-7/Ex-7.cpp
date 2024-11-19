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
T HalfNumber(T Number)
{
	return (float)Number / 2;
}

int main()
{
	float Number = ReadNumber<float>("\nenter number : ");
	cout << "\nhalf number is : " << HalfNumber<float>(Number) << endl;

	system("pause>0");
	return 0;
}