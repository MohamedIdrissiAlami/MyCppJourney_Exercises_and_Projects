#include <iostream>
using namespace std;

void PrintMultiplicationTable(short From = 1, short To = 10)
{
	for (short i = From; i <= To; i++)
	{
		cout << "\n**************" << i << "**************";
		for (short j = From; j <= To; j++)
		{
			cout << "\n" << i << " * " << j << " = " << i * j;
		}

	}
}

int main()
{
	PrintMultiplicationTable();
	system("pause>0");
	return 0;
}