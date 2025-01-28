#include <iostream>
#include <string >
#include <cctype>
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

short CountStringUpperLetters(string S1)
{
	short UpperCaseCounter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			UpperCaseCounter++;
		}
	}
	return UpperCaseCounter;
}

short CountStringLowerLetters(string S1)
{
	short LowerCaseCounter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			LowerCaseCounter++;
		}
	}
	return LowerCaseCounter;
}

int main()
{
	string S1 = ReadString("\nPlease enter your string ? ");
	cout << "\nstring length = " << S1.length();
	cout << "\nCapital letters count = " << CountStringUpperLetters(S1);
	cout << "\nlower letters count = " << CountStringLowerLetters(S1);

	system("pause>0");
	return 0;
}

