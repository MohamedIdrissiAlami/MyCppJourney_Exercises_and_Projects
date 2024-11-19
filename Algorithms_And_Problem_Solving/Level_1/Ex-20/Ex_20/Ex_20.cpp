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
		cin.clear();
		//user didn't input a valid number .
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\ninvalid input " << Message;
	}
	return Number;
}

float CalculateCircleAreaInscribedInSquare(float Side)
{
	const float PI = 3.14;
	return (float)((pow(Side, 2) * PI) / 4);
}

int main()
{
	float Diameter = ReadNumber<float>("\nSquare Side = ");
	cout << "\nCircle Area = " << CalculateCircleAreaInscribedInSquare(Diameter) << endl;
	system("pause>0");
	return 0;
}