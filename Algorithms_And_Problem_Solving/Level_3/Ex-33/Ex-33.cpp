#include <iostream>
#include <string >
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

char ReadChar(string Message = "")
{
	char Ch1 = ' ';
	cout << Message;
	cin >> Ch1;
	return Ch1;
}

bool IsVowel(char Char)
{
	Char = tolower(Char);
	return (Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u');
}

short CountVowels(string S1)
{
	short VowelsCount = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			++VowelsCount;
	}
	return VowelsCount;
}

int main()
{
	string S1 = ReadString("\nPlease enter your string ? ");
	cout << "\nYour string contains : " << CountVowels(S1) << " Vowel(s)" << endl;
	system("pause>0");
	return 0;
}
