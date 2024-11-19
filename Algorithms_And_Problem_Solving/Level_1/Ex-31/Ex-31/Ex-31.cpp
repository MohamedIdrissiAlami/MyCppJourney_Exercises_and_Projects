#include <iostream >
#include <cmath>
using namespace std;

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user did'nt input a valid number:
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input ! " << Message;

	}
	return Number;
}
template <typename T>
T ReadPositiveNumber(string Message = "")
{
	T Number = 0;
	do
	{
		Number = ReadNumber<T>(Message);
		if (Number <= 0)
			cout << "\ntry again with a positive number..";
	} while (Number<0);
	return Number;
}

int NPowerToM(short PowerTo,short Base)
{
	return pow(Base, PowerTo);
}

int main()
{
	short PowerTo = 0,Base=0;
	int Power = NPowerToM((PowerTo = ReadNumber<short>("\nPowerTo : ")),(Base= ReadNumber<short>("\nEnter The base : ")));
	cout << "\n" << Base << " ^ " << PowerTo << " = " << Power<<endl;
	system("pause>0");
	return 0;
}