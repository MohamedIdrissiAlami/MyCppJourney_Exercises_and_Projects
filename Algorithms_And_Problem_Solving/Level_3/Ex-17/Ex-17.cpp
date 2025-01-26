#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid number : 
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nWrong input !\ntry again..";
		cin >> Number;
	}
	return Number;
}

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandom(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(short Matrix[3][3], short Rows,short Cols)
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

bool IsNumberExistsInMatrix(short Matrix[3][3], short Rows, short Cols, short NumberToCheck)
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
int main()
{
	//seeds the random numbers generator in C++ ,called only once
	srand((unsigned)time(NULL));
	short Matrix[3][3];
	FillMatrixWithRandom(Matrix, 3, 3);
	cout << "\nthe following is a 3x3 random matrix :\n";
	PrintMatrix(Matrix, 3, 3);
	short NumberToCheck = ReadNumber<short>("\nPlease enter a number to look for : "); 
	cout << "\nnumber \'" << NumberToCheck << "\' " << (IsNumberExistsInMatrix(Matrix, 3, 3, NumberToCheck) ? "is found!" : "doesn't exist!") << endl;

	system("pause>0");
	return 0;
}