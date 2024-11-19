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

float CircleAreaDescribedAroundTriangle(float Side1,float Side2,float Side3)
{
	const float PI = 3.14;
	float P = (float)((Side1+ Side2+ Side3) / 2);
	float Area= (float)
		(PI*pow(((Side1*Side2*Side3)
			/
			(4*
				sqrt(P*(P-Side1)*(P-Side2)*(P-Side3))
			)), 2));

	return Area;
}
int main()
{
	float Side1= ReadPositiveNumber<float>("\nEnter triangle side 1 : ");
	float Side2 = ReadPositiveNumber<float>("\nEnter triangle side 2 : ");
	float Side3 = ReadPositiveNumber<float>("\nEnter triangle side 3 : ");

	cout << "\nCircle Area = " << CircleAreaDescribedAroundTriangle(Side1,Side2,Side3) << endl;
	system("pause>0");
	return 0;

}


