#include <iostream>
#include <cmath>
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

float CalculateRectangleArea(float Width, float Diagonal)
{
	return Width * sqrt(pow(Diagonal,2) - pow(Width,2));
}

int main()
{
	float Width = ReadNumber<float>("\nRectangle's width = "), Diagonal = ReadNumber<float>("\nRectangle's diagonal = ");
	cout << "\n area = " << CalculateRectangleArea(Width, Diagonal);
	system("pause>0");
	return 0;
}