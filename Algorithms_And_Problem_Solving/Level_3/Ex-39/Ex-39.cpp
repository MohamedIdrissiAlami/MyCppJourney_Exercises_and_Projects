#include <iostream >
#include <string >
#include <vector>
using namespace std;

string ReadString(string Message = "")
{
	cout << Message;
	string S1="";
	getline(cin >> ws, S1);
	return  S1;
}

string TrimRight(string S1)
{
	for (short i =S1.length()-1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0,i+1);
		}
	}
	return "";
}


vector<string>SplitString(string S1, string Delim = " ")
{
	string sWord = "";
	short Pos = 0;
	vector<string>vSplit;
	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != "")
			vSplit.push_back(sWord);
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
		S1 += sWord+Delim;
	}
	return S1;
}

int main()
{
	string S1 = ReadString("\nenter your string : ");
	cout << "\nvector after join : " << JoinString(SplitString(S1));
}
