#include <iostream>
#include <string>
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

void Gess3LetterPassword(string Word)
{
	short TotalTrials = 0;
	for (short i = 0; i < 26; i++)
	{
		for (short j = 0; j < 26; j++)
		{
			for (short k = 0; k < 26; k++)
			{
				if ((char(i + 65) + char(j + 65) + char(k + 65)) == Word)
				{

				}
			}
		}
	}
}