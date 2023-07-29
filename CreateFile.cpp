#include <iostream>
using namespace std;
int main()
{
	string str;
	cout << "Enter name of file with extension e.g abc.cpp : ";
	cin >> str;
	cout << "Creating a file ..";
	str = "touch " + str;
	const char *cmdStr = str.c_str();
	system(cmdStr);
	cout << "\nFile Created!\n";
	return 0;
}
