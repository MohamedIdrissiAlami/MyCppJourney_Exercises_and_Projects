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

float CalculateCircularArea(float Ray)
{
	const float PI = 3.14;
	return (float)pow(Ray, 2) * PI;
}

int main()
{
	float Ray = ReadNumber<float>("\nCircle Ray = ");
	cout << "\nCircle Area = " << CalculateCircularArea(Ray) << endl;
	system("pause>0");
	return 0;
}