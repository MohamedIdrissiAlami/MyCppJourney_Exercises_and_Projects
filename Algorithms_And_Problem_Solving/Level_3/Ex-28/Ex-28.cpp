#include <iostream>
#include <string >
#include <cctype>
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);//ignore whitespaces
	return S1;
}

char InvertLetterCase(char Char1)
{
	return Char1 == tolower(Char1) ? toupper(Char1) : tolower(Char1);
}

string  InvertAllLetterCase(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
	}
	return S1;
}

int main()
{
	string S1 = ReadString("\nPlease enter your string : ");
	cout << "\nstring after inverting all letters case : \"" << InvertAllLetterCase(S1) << "\".";
	system("pause>0");
	return 0;
}