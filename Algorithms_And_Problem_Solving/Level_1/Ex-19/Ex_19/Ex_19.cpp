#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	while ((cin >> Number).fail())
	cout << Message;
	{
		cin.clear();
		//user didn't input a valid number .
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\ninvalid input " << Message;
	}
	return Number;
}

float CalculateCircularArea(float Diameter)
{
	const float PI = 3.14;
	return (float)pow(Diameter, 2) * PI/4;
}

int main()
{
	float Diameter = ReadNumber<float>("\nCircle Ray = ");
	cout << "\nCircle Area = " << CalculateCircularArea(Diameter) << endl;
	system("pause>0");
	return 0;
}