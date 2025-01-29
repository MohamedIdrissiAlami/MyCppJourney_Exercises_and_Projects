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

bool IsVowel(char Char)
{
	Char = tolower(Char);
	return (Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u');
}

void PrintAllVowels(string S1)
{
	cout << "\nVowels in your string are : \n";
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
		{
			printf("\'%c\' ", S1[i]);
		}
	}
}

int main()
{
	string S1 = ReadString("\nPlease enter your string ? ");
	PrintAllVowels(S1);
	system("pause>0");
	return 0;
}
