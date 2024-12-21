#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;;
}

int main()
{
	//seeds the random number generator in C++,called only once.
	srand((unsigned)time(NULL));
	cout << "\nthe follwing are 3 random numbers from 1 to 10 : "<<endl;
	cout << RandomNumber(1, 10) <<endl<<
		RandomNumber(1, 10) <<endl<<
		RandomNumber(1, 10) << endl;

	system("pause>0");
	return 0;
}