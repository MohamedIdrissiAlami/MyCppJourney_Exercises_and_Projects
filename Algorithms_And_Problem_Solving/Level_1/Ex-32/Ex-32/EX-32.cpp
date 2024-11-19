#include <iostream >
#include <cmath>
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
T ReadNumberInRange(T From, T To,string Message="")
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < From || Number > To)
			cout << "\nout of range! ";
	} while (Number<From||Number>To);
	return Number;
}

short ReadStudentGrade()
{
	return ReadNumberInRange<short>(0,100,"\nEnter Student Grade : ");
}
 
char GetStudentGrade(short Grade)
{
	return Grade < 50 ? 'F' : Grade <= 59 ? 'E' : Grade <= 69 ? 'D' : Grade <= 79 ? 'C' : Grade <= 89 ? 'B' : 'A';
}

int main()
{
	short Grade = ReadStudentGrade();
	cout << "\n you obtained : \'" << GetStudentGrade(Grade) << "\'\n";
	system("pause>0");
	return 0;
}