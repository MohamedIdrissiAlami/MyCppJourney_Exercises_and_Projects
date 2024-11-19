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

float TriangleArea(float Base, float High)
{
	return (float)(Base * High) / 2;
}

int main()
{
	float Base = ReadNumber<float>("\nTriangle Base = "),High=ReadNumber<float>("\nTriangle high = ");
	cout << "\n triangle area = " << TriangleArea(Base, High) << endl;
	system("pause>0");
	return 0;
}