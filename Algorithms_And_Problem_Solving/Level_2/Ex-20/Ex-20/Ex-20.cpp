#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;;
}

enum enCharType{enDigit,enLowerLetter,enCapitalLetter,enSpecialCharacter};
char GenerateRandomChar(enCharType CharType)
{
	switch (CharType)
	{
	case enDigit:
		return char(RandomNumber(48, 57));
		break;
	case enLowerLetter:
		char(RandomNumber(97, 122));
		break;
	case enCapitalLetter:
		return char(RandomNumber(65, 90));
		break;
	case enSpecialCharacter:
		return char(RandomNumber(33,47));
		break;
	default:
		break;
	}
}

int main()
{
	//seeds the random number generator in C++,called only once.
	srand((unsigned)time(NULL));
	cout <<"\n"<< GenerateRandomChar(enCharType::enLowerLetter);
	cout << "\n" << GenerateRandomChar(enCharType::enCapitalLetter);
	cout << "\n" << GenerateRandomChar(enCharType::enSpecialCharacter);
	cout << "\n" << GenerateRandomChar(enCharType::enDigit);

	system("pause>0");
	return 0;
}