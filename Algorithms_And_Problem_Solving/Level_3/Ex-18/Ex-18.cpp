#include <iostream >
#include <cstdlib>
using namespace std;

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			Matrix[i][j] = RandomNumber(1, 99);
		}
	}
}

void PrintMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d ", 2, Matrix[i][j]);
		}
		cout << endl;
	}
}

bool IsNumberExistInMatrix(short Matrix[3][3], short Rows, short Cols, short NumberToCheck)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == NumberToCheck)
				return true;
		}
	}
	//if you reached here this means that the number you're looking for doesn't exist
	return false;
}

void PrintInsertedNumberInMatrixes(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
	cout << "\nthe following are the intersected numbers in the two matrixes : \n";
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (IsNumberExistInMatrix(Matrix2, Rows, Cols, Matrix1[i][j]))
			{
				printf("%hd  ", Matrix1[i][j]);
				
			}
		}
	}
}

int main()
{
	//seeds the random numbers generator in C++, called only once .
	srand((unsigned)time(NULL));
	short Matrix1[3][3],Matrix2[3][3];
	FillMatrixWithRandomNumbers(Matrix1,3,3);
	cout << "\nmatrix1 \n";
	PrintMatrix(Matrix1,3,3);
	FillMatrixWithRandomNumbers(Matrix2,3,3);
	cout << "\nmatrix2 \n";
	PrintMatrix(Matrix2,3,3);
	PrintInsertedNumberInMatrixes(Matrix1, Matrix2, 3, 3);

	system("pause>0");
	return 0;
}