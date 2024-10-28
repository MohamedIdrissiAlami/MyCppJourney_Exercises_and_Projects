#include <iostream>
using namespace std;

template <typename T>


T ReadNumber(string Message = "")
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

float RectangleArea(float Length, float Width)
{
	return Length * Width;
}

int main()
{
	float Length = ReadNumber<float>("\nEnter rectangle's length : "), Width = ReadNumber<float>("\nEnter rectangle's width : ");
	cout << "\nArea = " << RectangleArea(Length, Width);

	system("pause>0");
	return 0;
}