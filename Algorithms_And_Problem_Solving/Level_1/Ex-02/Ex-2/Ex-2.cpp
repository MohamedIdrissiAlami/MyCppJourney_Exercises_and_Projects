#include <iostream>
#include <string >
using namespace std;

string ReadString(string Message = "")
{
	cout << Message;
	string S1;
	getline(cin >> ws, S1);
	return S1;
}
int main()
{
	string Name = ReadString("\nEnter Your Name : ");
	cout << "\n Your name is : " << Name << endl;
	system("pause>0");
	return 0;
}
