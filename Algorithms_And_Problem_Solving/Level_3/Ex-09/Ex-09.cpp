#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void Fill3x3MatrixWithRandomNumbers(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void Print3x3Matrix(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*hd   ", 2, arr[i][j]);
		}
		printf("\n");
	}
}

void PrintRowOf3x3Matrix(short arr[3][3], short Cols,short RowToPrint)
{
	for (short j = 0; j < Cols; j++)
	{
		printf("%0*hd  ", 2, arr[RowToPrint-1][j]);
	}
}

void PrintColumnOf3x3Matrix(short arr[3][3], short Rows, short ColToPrint)
{
	for (short i = 0; i < Rows; i++)
	{
		printf("%0*hd  ", 2, arr[i][ColToPrint-1]);
	}
}

int main()
{
	//seeds the random numbers generator in C++,called only once
	srand((unsigned)time(NULL));
	short arr[3][3];
	Fill3x3MatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nfollowing is a 3x3 random matrix : \n";
	Print3x3Matrix(arr, 3, 3);
	cout << "\nMiddle Row is : \n";
	PrintRowOf3x3Matrix(arr, 3, 2);
	cout << "\nMiddle col is : \n";
	PrintColumnOf3x3Matrix(arr, 3, 2);

	system("pause>0");
	return 0;
}