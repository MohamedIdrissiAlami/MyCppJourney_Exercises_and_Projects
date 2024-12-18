#include<iostream>
using namespace std;

void PrintAllWordsFromAAAToZZZ()
{
	for (short i = 0; i < 26; i++)
	{
		for (short j = 0; j < 26; j++)
		{
			for (short k = 0; k < 26; k++)
			{
				cout << "\n" << char(i + 65) << " " << char(j+ 65)  << " " << char(k+ 65) ;
			}
		}
	}
}

int main()
{
	PrintAllWordsFromAAAToZZZ();
	system("pause>0");
	return 0;
}