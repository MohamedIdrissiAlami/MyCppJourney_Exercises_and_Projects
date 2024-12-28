#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't enter a valid number ...
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input try again ..";
		cin >> Number;
	}
	return Number;
}


short MySqrt(float Number)
{
	return pow(Number, .5);
}

int main()
{

	float Number = ReadNumber<float>("\nEnter a number : ");
	cout << "\nMy sqrt Result : " << MySqrt(Number);
	cout << "\nC++ sqrt Result : " << sqrt(Number) << endl;
	system("pause>0");

	return 0;
}