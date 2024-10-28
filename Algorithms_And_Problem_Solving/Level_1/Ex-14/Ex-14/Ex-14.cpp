#include <iostream>
using namespace std;

template <typename T>
T ReadNumber(string Message)
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
template <typename T>
void Swap(T &A, T &B)
{
	T temp = A;
	A = B;
	B = temp;
}


int main()
{
	short Number1 = ReadNumber<short>("\nNumber1 = "), Number2 = ReadNumber<short>("\nNumber2 = ");
	cout << "\nbefore swapping : Number1 = " << Number1 << " , Number2 = " << Number2;
	Swap<short>(Number1, Number2);
	cout << "\nafter swapping : Number1 = " << Number1 << " , Number2 = " << Number2 << endl;
	system("pause>0");
	return 0;
}