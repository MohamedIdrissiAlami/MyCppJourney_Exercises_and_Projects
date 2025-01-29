#include <iostream >
#include <string >
#include <vector>
using namespace std;

string ReadString(string Message = "")
{
	cout << Message;
	string S1 = "";
	getline(cin >> ws, S1);
	return  S1;
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
		S1 += sWord + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string ArrString[], short ArrLength,string Delim = " ")
{
	string S1 = "";

	for (short i = 0; i < ArrLength; i++)
	{
		S1 += ArrString[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	string ArrString[] = { "Mohamed","Fadi","Ali","Maher" };
	cout << "\nArray after join : " << JoinString(ArrString, 4, " ") << endl;
	system("pause>0");
	return 0;

}
