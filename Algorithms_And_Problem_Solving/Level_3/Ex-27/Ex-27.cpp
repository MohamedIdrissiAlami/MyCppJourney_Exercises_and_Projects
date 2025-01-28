#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
char ReadChar(string Message = "")
{
	char Char = ' ';
	cout << Message;
	cin >> Char;
	return Char;
}

char InvertLetterCase(char Char1)
{
	return Char1 == tolower(Char1) ? toupper(Char1) : tolower(Char1);
}

int main()
{
	char Char1 = ReadChar("\nEnter a character : ");
	cout << "\nyour character after inverting case is : \'" << InvertLetterCase(Char1) << "\' \n";
	system("pause>0");
	return 0;
}