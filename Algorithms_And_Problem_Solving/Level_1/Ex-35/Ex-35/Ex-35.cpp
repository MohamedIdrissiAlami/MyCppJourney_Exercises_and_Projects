#include <iostream >
using namespace std;

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user did'nt input a valid number:
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input ! " << Message;

	}
	return Number;
}
template <typename T>
T ReadPositiveNumber(string Message = "")
{
	T Number = 0;
	do
	{
		Number = ReadNumber<T>(Message);
		if (Number <= 0)
			cout << "\ntry again with a positive number..";
	} while (Number < 0);
	return Number;
}
template <typename T>
T ReadNumberInRange(T From,T To,string Message)
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < From || Number > To)
			cout << "\nout of range! ";
	} while (Number<From||Number>To);
	return Number;
}

char ReadOperationType()
{
	char Optypt[] = { '+','-','*','/' };
	cout << "\nchoose operation type : ";
	cout << "\n[1] for add (+).";
	cout << "\n[2] for subtract (-).";
	cout << "\n[3] for multiply (*).";
	cout << "\n[4] for division (/).";
	return Optypt[ReadNumberInRange<short>(1, 4, "\nyour choice [1~4]? ") - 1];
}

float PerformCalculation(char OpType,float Number1, short Number2 )
{
	float Result = 0;
	switch (OpType)
	{
	case '+':
		Result = Number1 + Number2;
		break;
	case '-':
		Result = Number1 - Number2;
		break;
	case '*':
		Result = Number1 * Number2;
		break;
	case '/':
		Result = Number1 / Number2;
		break;
	default:
		break;
	}
	return Result;
}

int main()
{
	float Number1 = ReadNumber<float>("\nNumber 1 = "), Number2 = ReadNumber<float>("\nNumber 2 = ");
	char OpType = ReadOperationType();
	cout << "\n" << Number1 << " " << OpType << " " << Number2 << " = " << PerformCalculation(OpType, Number1, Number2) << endl;

	system("pause>0");
	return 0;
}