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

vector<string> SplitString(string S1, string Delim = " ")
{
	vector<string> vSplit;
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
	//to store the last word : 
	if (S1 != "")
	{
		vSplit.push_back(S1);
	}
	return vSplit;
}

int main()
{
	string S1 = ReadString("\nPlease enter your string ? ");
	vector<string>vStringTokens = SplitString(S1);
	cout << "\nTokens = " << vStringTokens.size();
	for (string& Token : vStringTokens)
	{
		cout << "\n" << Token;
	}

	system("pause>0");
	return 0;
}