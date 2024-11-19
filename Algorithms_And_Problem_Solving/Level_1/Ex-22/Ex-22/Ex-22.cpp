#include <iostream >
#include <cmath>
using namespace std;

template<typename T>
T ReadNumber(string Message)
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid number.
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input! " << Message;

	}
	return Number;
}
template<typename T>
T ReadPositiveNumber(string Message)
{
	T Number = 0;
	do
	{
		Number = ReadNumber<T>(Message);
		if (Number < 0)
			cout << "\ntry again with a positive number..";
	} while (Number < 0);
	return Number;
}

float CircleAreaInscribedInIsoscelesTriangle(float Side,float Base)
{
	const float PI = 3.14;
	return (float)(PI*(pow(Base,2)/4)*((2*Side-Base)/(2*Side+Base)));
}
int main()
{
	float Side= ReadPositiveNumber<float>("\nEnter the Isosceles Triangle's side : ");
	float Base = ReadPositiveNumber<float>("\nEnter the Isosceles Triangle's base : ");

	cout << "\nArea = " << CircleAreaInscribedInIsoscelesTriangle(Side,Base) << endl;
	system("pause>0");
	return 0;

}


