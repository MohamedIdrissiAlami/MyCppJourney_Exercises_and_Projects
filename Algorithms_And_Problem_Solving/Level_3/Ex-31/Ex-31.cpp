#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string Message = "")
{
	cout << Message;
	string S1 = "";
	getline(cin >> ws, S1);
	return S1;
}

char ReadChar(string Message = "")
{
	cout << Message;
	char Ch;
	cin >> Ch;
	return Ch;

}

short CountLetter(string S1, char Ch)
{
	short LetterCount = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Ch)
			++LetterCount;
	}
	return LetterCount;
}
short CountLetterMatchCase(string S1, char Ch)
{
	short LetterCount = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (tolower(S1[i]) == tolower(Ch))
			++LetterCount;
	}
	return LetterCount;

}

int main()
{
	string S1 = ReadString("\nPlease enter your string ? ");
	char Ch = ReadChar("\nPlease enter a character ? ");
	cout << "\nLetter \'" << Ch << "\' count = " << CountLetter(S1, Ch) << endl;
	cout << "\nLetter \'" << char(tolower(Ch)) << "\' or \'"<<char(toupper(tolower(Ch))) <<"\' count = " << CountLetterMatchCase(S1, Ch) << endl;
	system("pause>0");
	return 0;
}