#include <iostream>
#include <cstdlib>
using namespace std;

enum enWinner { enUser, enComputer, enNoWinner };
enum enGameChoice { eScissor, ePaper, eStone };
struct stGameResult
{
	short GameRounds;
	short PlayerWonTimes;
	short ComputerWonTimes;
	short DrawTimes;
	enWinner FinalWinner;

};


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

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void StartGame()
{
	char Answer = 'Y';
	do
	{
		ResetScreen();
		stGameResult GameResult = RunGame();
		ShowFinanlResult(GameResult);
		cout << "\nDo you wanna play again ? [Y/N] ";
		cin >> Answer;
	} while (toupper(Answer) == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}