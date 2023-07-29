#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;
int main()
{
	cout << "\nOpening Fireox Browser\n";
	string str;
	usleep(2000000);
	str = "firefox";
	const char* cmdStr = str.c_str();
	system(cmdStr);
	cout << "\nBrowser Opened\n";
	return 0;
}
