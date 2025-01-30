#include <iostream>
#include <string>
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

string  ReplaceWordsUsingbuiltInFunction(string S1, string WordToReplace, string ReplaceTo)
{
	short Pos = S1.find(WordToReplace);
	while (Pos != std::string::npos)
	{
		S1.replace(Pos, WordToReplace.length(), ReplaceTo);
		Pos = S1.find(WordToReplace);
	}

	return S1;


}

string ReplaceWordsUsingBuiltInFunction(string S1, string WordToReplace, string ReplaceTo)
{
	short Pos = S1.find(WordToReplace);
	while (Pos != std::string::npos)
	{
		S1.replace(Pos, WordToReplace.length(), ReplaceTo);
		Pos = S1.find(WordToReplace);
	}

	return S1;
}

int main()
{
	string  S1 = "\nWelcom to jordan , jordan is a nice country.";
	cout << "\nOriginal String : " << S1;
	cout << "\nstring after replace : " << ReplaceWordsUsingBuiltInFunction(S1, "jordan", "Morocco");
	system("pause>0");
	return 0;
}
