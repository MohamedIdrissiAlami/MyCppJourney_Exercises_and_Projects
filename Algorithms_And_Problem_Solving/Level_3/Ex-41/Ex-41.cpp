#include <iostream>
#include <string >
#include <vector>
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

vector <string>SplitString(string S1, string Delim = "")
{
	vector<string>vSplit;
	string sWord = "";
	short Pos = 0;
	while ((Pos = S1.find(Delim))!=std::string::npos)
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

string ReverseWordsString(string S1, string  Delim = " ")
{
	vector<string >vSplit = SplitString(S1, Delim);
	string S2 = "";
	vector<string>::iterator iter=vSplit.end();
	while (iter != vSplit.begin())
	{
		S2 += *--iter + Delim;
	}

	return S2.substr(0, S2.length() - Delim.length());
}

int main()
{
	string S1 = ReadString("\nenter a string to reverse its words : ");
	cout << "\nyour original string : " << S1;
	cout << "\nafter reversing their words, your string becomes : " << ReverseWordsString(S1, " ");
	system("pause>0");
	return 0;
}
