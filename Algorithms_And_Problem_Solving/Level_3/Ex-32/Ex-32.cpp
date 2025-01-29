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
	return (Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o')||(Char=='u');
}

int main()
{
	char Ch1 = ReadChar("\nplease enter a character : ");
	if (IsVowel(Ch1))
		cout << "\nyes, vowel";
	else
		cout << "\nno it is not vowel.";
	system("pause>0");
	return 0;
}
