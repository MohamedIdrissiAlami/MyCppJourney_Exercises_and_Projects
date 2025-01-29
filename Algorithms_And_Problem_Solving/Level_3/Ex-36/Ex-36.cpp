#include <iostream>
#include <string >
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

short CountEachWordInString(string S1, string Delim = " ")
{
	short WordsCount = 0;
	string sWord = "";
	short Pos = 0;
	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		S1.erase(0, Pos + Delim.length());
		if (sWord != "")
			++WordsCount;
	}
	//to count the last word : 
	if (S1 != "")
	{
		++WordsCount;
	}
	return WordsCount;
}

int main()
{
	string S1 = ReadString("\nPlease enter your string ? ");
	cout << "\nThe number of words in your string is = " << CountEachWordInString(S1) << endl;
	system("pause>0");
	return 0;
}