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


short MyFloor(float Number)
{
	short IntPart = int(Number);
	return Number >= 0 ? IntPart : --IntPart;
}

int main()
{

	float Number = ReadNumber<float>("\nEnter a number : ");
	cout << "\nMy floor Result : " << MyFloor(Number);
	cout << "\nC++ floor Result : " << floor(Number) << endl;
	system("pause>0");

	return 0;
}