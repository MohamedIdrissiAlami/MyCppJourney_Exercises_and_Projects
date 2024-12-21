#include <iostream>
#include <cstdlib>
using namespace std;

#include <iostream>
using namespace std;

template<typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't enter a valid number ...
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input try again ..";
		cin >> Number;
	}
	return Number;
}

template <typename T>
T ReadPositiveNumber(string Message = "\nEnter a positive Number : ")
{
	T Number = 0;
	while ((Number = ReadNumber<T>(Message)) < 0)
	{
		cout << "\nyou have entered a negative number try again with a positive input!";
	}
	return Number;
}


int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;;
}

enum enCharType { enDigit, enLowerLetter, enCapitalLetter, enSpecialCharacter };
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
		return char(RandomNumber(33, 47));
		break;
	default:
		break;
	}
}

string GenerateWord()
{
	string Word = "";
	Word += GenerateRandomChar(enCharType::enCapitalLetter);
	Word += GenerateRandomChar(enCharType::enCapitalLetter);
	Word += GenerateRandomChar(enCharType::enCapitalLetter);
	Word += GenerateRandomChar(enCharType::enCapitalLetter);
	return Word;

}

string GenerateKey()
{
	string Key = "";
	Key += GenerateWord() + '-';
	Key += GenerateWord() + '-';
	Key += GenerateWord() + '-';
	Key += GenerateWord();
	return Key;

}

void GenerarateKeys(short HowManyKeys)
{
	for (short i = 1; i <= HowManyKeys; i++)
	{
		cout << "\n" << "KEY[" << i << "] " << GenerateKey();
	}
}

int main()
{
	//seeds the random number generator in C++,called only once.
	srand((unsigned)time(NULL));
	GenerarateKeys(ReadPositiveNumber<short>("\nHow many keys do you wanna generate ? "));
	system("pause>0");
	return 0;
}