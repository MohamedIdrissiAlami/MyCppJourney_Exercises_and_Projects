#include <iostream >
#include <cstdlib>
using namespace std;

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void Fill3x3MatrixWithRandomNumbers(short arr[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			arr[i][j] = RandomNumber(1, 99);
		}
	}
}

void Print3x3Matrix(short arr[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			//cout << arr[i][j]<<" ";
			printf("%0*d ",2, arr[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	//seeds the random numbers generator in C++, called only once .
	srand((unsigned)time(NULL));
	short arr[3][3];
	Fill3x3MatrixWithRandomNumbers(arr);
	cout << "\nthe following is a 3x3 random matrix \n";
	Print3x3Matrix(arr);
	system("pause>0");
	return 0;
}