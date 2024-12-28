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

float GetFractionPart(float Number)
{
	return (float)(Number - int(Number));
}

short MyRound(float Number)
{
	short IntPart = int(Number);
	float FractionPart = GetFractionPart(Number);

	return (abs(FractionPart) >= .5) ? (Number > 0) ? ++IntPart : IntPart-1 : IntPart;
}

int main()
{

	float Number = ReadNumber<float>("\nEnter a number : ");
	cout << "\nMy round Result : " << MyRound(Number);
	cout << "\nC++ round Result : " << round(Number) << endl;
	system("pause>0");

	return 0;
}