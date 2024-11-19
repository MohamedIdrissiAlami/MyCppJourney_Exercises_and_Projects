#include <iostream>
using namespace std;

void PrintLettersFromAToZ()
{
	for (short i = 65; i <= 90; i++)
	{
		cout << "\n" << char(i);
	}
}

int main()
{
	PrintLettersFromAToZ();
	system("pause>0");
	return 0;
}