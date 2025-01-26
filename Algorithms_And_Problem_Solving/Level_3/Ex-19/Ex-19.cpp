#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*hd  ", 2, Matrix[i][j]);
		}
		printf("\n");
	}
}

short MinInMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short Min = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] < Min)
			{
				Min = Matrix[i][j];
			}
		}
	}
	return Min;
}
short MaxMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short Max = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] > Max)
			{
				Max = Matrix[i][j];
			}
		}
	}
	return Max;
}

int main()
{
	//seeds the random numbers generator in C++,called only once.
	srand((unsigned)time(NULL));
	short Matrix[3][3];
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "\nthe following is a 3x3 random matrix: \n";
	PrintMatrix(Matrix, 3, 3);
	cout << "\nMin = " << MinInMatrix(Matrix, 3, 3);
	cout << "\nMax = " << MaxMatrix(Matrix, 3, 3);
	system("pause>0");
	return 0;
}