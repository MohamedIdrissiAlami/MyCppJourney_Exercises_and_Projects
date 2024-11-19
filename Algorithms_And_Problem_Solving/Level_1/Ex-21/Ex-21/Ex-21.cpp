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
	} while (Number<0);
	return Number;
}

float CircleAreaThroughCircumference(float Circumference)
{
	const float PI = 3.14;
	return (float)(pow(Circumference, 2) / 4 * PI);
}
int main()
{
	float Circumference = ReadPositiveNumber<float>("\nEnter circle Circumference : ");
	cout << "\nArea = " << CircleAreaThroughCircumference(Circumference) << endl;
	system("pause>0");
	return 0;

}




