#include <iostream>
#include <string>
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
T ReadPositiveNumber(string Message)
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < 0)
			cout << "try again with a positive number..";

	} while (Number < 0);
	return Number;
}

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

bool Login()
{
	string PinCode = "";
	do
	{
		if((PinCode=ReadString("\nPinCode = "))=="1234")
		{
			return true;
		}
		else
		{	
			system("color 4f");//turn screen to red
			cout << "\nWrong Password!";
		}
	} while (PinCode!="1234");
}

int main()
{
	if (Login())
	{
		system("color 2f");//turn screen to green .
		cout << "\nyour balance is " << 7500 << endl;
	}
	system("pause>0");
	return 0;
}