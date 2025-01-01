#include <iostream>
#include <cstdlib>
#include<iomanip>
using namespace std;

enum enWinner { enPlayer=1, enComputer, enNoWinner };
enum enGameChoice { eStone=1,eScissor, ePaper};
struct stGameResult
{
	short GameRounds=0;
	short PlayerWonTimes=0;
	short ComputerWonTimes=0;
	short DrawTimes=0;
	enWinner FinalWinner;

};
struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner RoundWinner;
};

template<typename T>
T ReadNumber(string);
template<typename T>
T ReadPositiveNumber(string);
template <typename T>
T ReadNumberBetween(short, short, string);
short RandomNumber(short, short);


void StartGame();
void ResetScreen();
stGameResult RunGame();
stRoundInfo PlayRound(short);
void SetWinnerScreenColor(enWinner);
string WinnerName(enWinner );
enWinner WhoWonTheRound(enGameChoice, enGameChoice);
string ChoiceName(enGameChoice );
enGameChoice ReadPlayerChoice();
void ShowFinalGameResults(stGameResult );
void ShowGameOverScreen();
int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}


void StartGame()
{
	char Answer = 'Y';
	do
	{
		ResetScreen();
		stGameResult GameResult = RunGame();
		ShowGameOverScreen();
		ShowFinalGameResults(GameResult);
		cout << "\nDo you wanna play again ? [Y/N] ";
		cin >> Answer;
	} while (toupper(Answer) == 'Y');
}
void ResetScreen()
{
	system("cls");
	system("color 0f");
}

stGameResult RunGame()
{
	stGameResult GameResult;
	GameResult.GameRounds = ReadNumberBetween<short>(1, 10, "\nHow many rounds to play : [1~10] : ");
	stRoundInfo CurrentRound;
	for (short i = 1; i <= GameResult.GameRounds; i++)
	{
		CurrentRound = PlayRound(i);
		GameResult.ComputerWonTimes += (CurrentRound.RoundWinner == enWinner::enComputer ? 1 : 0);
		GameResult.PlayerWonTimes += (CurrentRound.RoundWinner == enWinner::enPlayer ? 1 : 0);
		GameResult.DrawTimes += (CurrentRound.RoundWinner == enWinner::enNoWinner ? 1 : 0);
	}
	GameResult.FinalWinner = (GameResult.PlayerWonTimes > GameResult.ComputerWonTimes ? enWinner::enPlayer :
		(GameResult.PlayerWonTimes < GameResult.ComputerWonTimes ? enWinner::enComputer : enWinner::enNoWinner));

	return GameResult;
}
stRoundInfo PlayRound(short RoundNumber)
{
	stRoundInfo RoundInfo;
	system("cls");//clear screen
	cout << "\n" << left << setw(15) << "" << "******************** round [" << (RoundInfo.RoundNumber = RoundNumber) << "] ********************";
	RoundInfo.PlayerChoice = ReadPlayerChoice(), RoundInfo.ComputerChoice = (enGameChoice)RandomNumber(1, 3);
	RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo.PlayerChoice, RoundInfo.ComputerChoice);

	cout << "\n" << left << setw(15) << "" << "Round [" << RoundInfo.RoundNumber << "] begins..";
	cout << "\n" << left << setw(15) << "" << "\tPlayer choice  : " << ChoiceName(RoundInfo.PlayerChoice);
	cout << "\n" << left << setw(15) << "" << "\tComputer choice  : " << ChoiceName(RoundInfo.ComputerChoice);
	cout << "\n" << left << setw(15) << "" << "\tRound Winner : " << WinnerName(RoundInfo.RoundWinner);
	SetWinnerScreenColor(RoundInfo.RoundWinner);

	cout << "\n" << left << setw(15) << "" << "*************************************************************\n";
	cout << "\n" << left << setw(15) << "" << "round ends! press any key to continue..";
	system("pause>0");
	return RoundInfo;
}
void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enPlayer:
		system("color 0a");//set screen color to green
		break;
	case enComputer:
		system("color 0c");//set screen color to red
		cout << "\a";//sound a bill
		break;
	case enNoWinner:
		system("color 06");//set screen color to yellow
		break;
	default:
		break;
	}
}
string WinnerName(enWinner Winner)
{
	string WinnerName[] = { "Player","Computer","No Winner" };
	return WinnerName[Winner - 1];
}
enWinner WhoWonTheRound(enGameChoice PlayerChoice, enGameChoice ComputerChoice)
{
	if (PlayerChoice == ComputerChoice)
	{
		return enWinner::enNoWinner;
	}
	switch (PlayerChoice)
	{
	case eStone:
		return ComputerChoice == enGameChoice::eScissor ? enWinner::enPlayer : enWinner::enComputer;
		break;
	case eScissor:
		return ComputerChoice == enGameChoice::ePaper ? enWinner::enPlayer : enWinner::enComputer;
		break;
	case ePaper:
		return ComputerChoice == enGameChoice::eStone ? enWinner::enPlayer : enWinner::enComputer;
		break;
	default:
		break;
	}

}
string ChoiceName(enGameChoice GameChoice)
{
	string Choice[] = { "Stone","Scissor","Paper" };
	return Choice[GameChoice - 1];
}
enGameChoice ReadPlayerChoice()
{
	cout << "\n" << setw(15) << "";
	return (enGameChoice)ReadNumberBetween<short>(1, 3, "Your Choice : [1] stone,[2] scissor,[3] paper ? ");
}
void ShowFinalGameResults(stGameResult GameResult)
{
	cout << "\n" << left << setw(15) << "" << "******************** G A M E  R E S U L T ********************";
	cout << "\n" << left << setw(15) << "" << "Game rounds : " << GameResult.GameRounds;
	cout << "\n" << left << setw(15) << "" << "Player won times : " << GameResult.PlayerWonTimes;
	cout << "\n" << left << setw(15) << "" << "Computer won times : " << GameResult.ComputerWonTimes;
	cout << "\n" << left << setw(15) << "" << "Draw Times : " << GameResult.DrawTimes;
	cout << "\n" << left << setw(15) << "" << "final winner : " << "\'" << WinnerName(GameResult.FinalWinner) << "\'";

	cout << "\n" << left << setw(15) << "" << "***************************************************************\n\n\n";

	cout << "\npress any key...";
	system("pause>0");

}
void ShowGameOverScreen()
{
	system("cls");//clear screen
	system("color 0f");//set screen to default
	cout << "\n\n\n\n\n" << left << setw(10) << "" << "***********************************************************************\n";
	cout << "\n\n" << left << setw(35) << "" << "G A M E  O V E R" << "\n\n";
	cout << "\n" << left << setw(10) << "" << "***********************************************************************\n\n\n";


}

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
template <typename T>
T ReadNumberBetween(short From, short To, string Message = "")
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) > To || Number < From)
			cout << "\nout of range!";

	} while (Number<From || Number>To);
	return Number;
}
short RandomNumber(short From, short To)
{
	return rand() % (To - From) + From;
}
