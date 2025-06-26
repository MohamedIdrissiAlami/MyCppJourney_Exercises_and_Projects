#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid input
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout << "\ninvalid input try again..";
	}
	return Number;
}
template <typename T>
T ReadPositiveNumber(string Message = "")
{
	T Number = 0;
	do
	{
		if ((Number=ReadNumber<T>(Message)) < 0)
		{
			cout << "\ntry again with a positive number ..";
		}
	} while (Number<0);
	return Number;
}
template <typename T>
T ReadNumberBetween(T From, T To, string Message = "")
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < From || Number > To)
			cout << "\nout of range! try again..";
	} while (Number<From||Number>To);
	return Number;
}
short RandomNumber(short From, short To)
{
	return rand() % (To-From+1) + From;
}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

enum enQuestionsLevel{eEasy=1,eMedium,eHard,eMix};
enum enOperationType{eAdd=1,eSubtract,eMultiply,eDivid,eMixOp};
struct stQuestion
{
	short  Number1 = 0;
	short Number2 = 0;
	short PlayerAnswer = 0;
	short RightAnswer = 0;
	enQuestionsLevel QuestionLevel;
	enOperationType OpType;
};
struct stQuiz
{
	short NumberOfQuestions = 0;
	stQuestion* QuestionsList = nullptr;
	enQuestionsLevel QuestionsLevel;
	enOperationType OpType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;
};
    
enQuestionsLevel ReadQuestionsLevel()
{
	string Message = "\nEnter Questions level : ";
	Message += "\n\t[1] easy,";
	Message += "\n\t[2] Medium,";
	Message += "\n\t[3] Hard,";
	Message += "\n\t[4] Mix ..";
	return (enQuestionsLevel)ReadNumberBetween<short>(1, 4, Message);
}

enOperationType ReadOperationType()
{
	string Message = "\nEnter Operation type : ";
	Message += "\n\t[1] Add,";
	Message += "\n\t[2] Subtract,";
	Message += "\n\t[3] Multiply,";
	Message += "\n\t[4] Divide,";
	Message += "\n\t[5] Mix..";
	return (enOperationType)ReadNumberBetween<short>(1, 5, Message);
}

stQuestion GenerateQuestion(enOperationType OpType, enQuestionsLevel Level)
{
	stQuestion Question;
	if (Level == enQuestionsLevel::eMix)
		Level = (enQuestionsLevel)RandomNumber(1, 3);
	if (OpType == enOperationType::eMixOp)
		OpType = (enOperationType)RandomNumber(1, 4);
	switch (Level)
	{
	case enQuestionsLevel::eEasy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		break;
	case enQuestionsLevel::eMedium:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		break;
	case enQuestionsLevel::eHard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		break;
	}
	Question.QuestionLevel = Level;
	Question.OpType = OpType;
	return Question;
}

void GenerateQuestionsList(stQuiz& Quiz)
{
	for (short Question = 0; Question < Quiz.NumberOfQuestions; Question++)
	{
		Quiz.QuestionsList[Question] = GenerateQuestion(Quiz.OpType, Quiz.QuestionsLevel);
	}
}

char OperationTypeSymbole(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::eAdd:
		return '+';
	case enOperationType::eSubtract:
		return '-';
	case enOperationType::eMultiply:
		return '*';
	case enOperationType::eDivid:
		return '/';
	default:
		return '+';
	}
}

void  PrintTheQuestion(stQuestion& Question,short QuestionNumber)
{
	cout << "\nQuestion [" << QuestionNumber << "] : ";
	cout << "\n\t" << Question.Number1;
	cout << "\n" << OperationTypeSymbole(Question.OpType);
	cout << "\n" << Question.Number2;
	cout << "\n_________\n";
}

void SetScreenColor(bool IsTrue)
{
	if (IsTrue)
	{
		system("color 0a");//green
	}
	else
	{
		system("color 0c");//red
		cout << "\a";
	}
}

short SimpleCalculator(short Number1, short Number2,enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::eAdd:
		return Number1 + Number2;
	case enOperationType::eSubtract:
		return Number1 - Number2;
	case enOperationType::eMultiply:
		return Number1 * Number2;
	case enOperationType::eDivid:
		return Number1 / (Number2!=0? Number2:1);
	default:
		return Number1 + Number2;
	}
}

void CorrectUserAnswer(stQuiz& Quiz,short QuestionNumber)
{
	if (Quiz.QuestionsList[QuestionNumber].RightAnswer == Quiz.QuestionsList[QuestionNumber].PlayerAnswer)
	{
		cout << "\nRight Answer :-)\n";
		Quiz.NumberOfRightAnswers++;
		SetScreenColor(true);
	}
	else
	{
		cout << "\nWrong Answer :-(";
		cout << "\nThe Right answer is : " << Quiz.QuestionsList[QuestionNumber].RightAnswer << endl;
		Quiz.NumberOfWrongAnswers++;
		SetScreenColor(false);
	}
}

void AskUserAndCorrectAnswer(stQuiz& Quiz)
{
	for (short Question = 0; Question < Quiz.NumberOfQuestions; Question++)
	{
		PrintTheQuestion(Quiz.QuestionsList[Question],Question);
		Quiz.QuestionsList[Question].PlayerAnswer = ReadNumber<short>("\n");
		Quiz.QuestionsList[Question].RightAnswer = 
													SimpleCalculator(
														Quiz.QuestionsList[Question].Number1,
														Quiz.QuestionsList[Question].Number2,
														Quiz.QuestionsList[Question].OpType
													);
		CorrectUserAnswer(Quiz,Question);
	}
	Quiz.IsPass = Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers;
	SetScreenColor(Quiz.IsPass);
}

string GetQuizResultName(bool IsPass)
{
	return IsPass ? "pass" : "fail";
}

string  GetQuestionsLevelName(enQuestionsLevel Level)
{
	switch (Level)
	{
	case enQuestionsLevel::eEasy:
		return "Easy";
	case enQuestionsLevel::eMedium:
		return "Medium";
	case enQuestionsLevel::eHard:
		return "Hard";
	default:
		return "Mix";
	}
}

string GetOperationTypeName(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::eAdd:
		return "Add";
	case enOperationType::eSubtract:
		return "Subtract";
	case enOperationType::eMultiply:
		return "Multiply";
	case enOperationType::eDivid:
		return "Divide";
	default:
		return "Mix";
	}
}

void PrintFinalQuizResults(stQuiz Quiz)
{
	cout << "\n________________________";
	cout << "\nfinal result is : " << GetQuizResultName(Quiz.IsPass);
	cout << "\n________________________";
	cout << "\nNumber of questions : " << Quiz.NumberOfQuestions;
	cout << "\nQuestions level : " << GetQuestionsLevelName(Quiz.QuestionsLevel);
	cout << "\nOperation type : " << GetOperationTypeName(Quiz.OpType);
	cout << "\nNumber of right answers : " << Quiz.NumberOfRightAnswers;
	cout << "\nNumber of wrong answers : " << Quiz.NumberOfWrongAnswers;
	cout << "\n________________________";

}

void PlayMathGame()
{
	stQuiz Quiz;
	Quiz.NumberOfQuestions = ReadNumberBetween<short>(1, 10, "\nHow  many questions do you want to answer [1~10] : ");
	Quiz.QuestionsLevel = ReadQuestionsLevel();
	Quiz.OpType = ReadOperationType();

	Quiz.QuestionsList = new stQuestion[Quiz.NumberOfQuestions];

	GenerateQuestionsList(Quiz);
	AskUserAndCorrectAnswer(Quiz);
	PrintFinalQuizResults(Quiz);
	delete[]Quiz.QuestionsList;
}

void StartGame()
{
	char PlayAgain = 'y';
	do
	{
		ResetScreen();
		PlayMathGame();
		cout << "\nDo you want  to play again [Y/N]..";
		cin >> PlayAgain;
	} while (tolower(PlayAgain)=='y');
}

int main()
{
	StartGame();
	return 0;
}