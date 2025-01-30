#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

string LowerString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

vector <string>SplitString(string S1, string Delim = " ")
{
	vector<string>vSplit;
	string sWord = "";
	short Pos = 0;
	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != "")
		{
			vSplit.push_back(sWord);
		}
		S1.erase(0, Pos + Delim.length());
	}
	if (S1 != "")
	{
		vSplit.push_back(S1);
	}
	return vSplit;
}

string JoinString(vector<string>vSplit, string Delim = " ")
{
	string S1 = "";
	for (string& sWord : vSplit)
	{
		S1 += sWord + Delim;
	}
	return S1;
}

string ReplaceWords(string S1, string WordToReplace, string ReplaceTo)
{
	vector<string>vSplit = SplitString(S1);
	vector<string>::iterator iter=vSplit.begin();
	while (iter != vSplit.end())
	{
		if (LowerString(*iter) == LowerString(WordToReplace))
		{
			*iter = ReplaceTo;
		}
		iter++;
	}
	return JoinString(vSplit);
}

int main()
{
	string  S1 = "\nWelcome to Jordan , Jordan is a nice country.";
	cout << "\nOriginal String : " << S1;
	cout << "\nstring after replace : " << ReplaceWords(S1, "Jordan", "Morocco");
	system("pause>0");
	return 0;
}
