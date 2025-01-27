#include <iostream >
#include <string >
using namespace std;

string ReadString(string Message = "")
{
	cout << Message;
	string S1 = "";
	getline(cin >> ws, S1);//ignore whitespaces
	return S1;
}

void PrintFirstLetterOfEachWord(string S1)
{
	cout << "\nthe following are the first letters of each word : \n";
	while (S1.find(' ')!=std::string::npos)
	{
		printf("\n%c", S1[0]);
		S1 = S1.substr(S1.find(' ') + 1, S1.length());
	}
	//to print the the first letter of the last word
	if (S1 != "")
	{
		printf("\n%c", S1[0]);
	}
}

int main()
{
	PrintFirstLetterOfEachWord(ReadString("\nPlease enter your string : "));
	system("pause>0");
	return 0;
}