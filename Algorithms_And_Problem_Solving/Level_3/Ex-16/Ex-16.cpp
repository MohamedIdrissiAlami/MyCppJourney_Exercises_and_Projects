#include <iostream>
using namespace std;

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

short CountNumberInMatrix(short Matrix[3][3], short Rows, short Cols, short NumberToCount)
{
	short NumberCount = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == NumberToCount)
			{
				++NumberCount;
			}
		}
	}
	return NumberCount;
}

bool IsSparceMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short MatrixSize = floor((float)Rows * Cols / 2);
	return CountNumberInMatrix(Matrix, Rows, Cols, 0) >= MatrixSize;
}

int main()
{
	short Matrix[3][3] = { {1,5,0},{4,0,0},{5,0,0} };
	cout << "\nMatrix1 : \n";
	PrintMatrix(Matrix, 3, 3);
	cout << "\nMatrix1 is " << (IsSparceMatrix(Matrix,3,3)? "":"not ") << "sparce" << endl;

	system("pause>0");
	return 0;
}