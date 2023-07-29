#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
int main()
{
	string str;
	cout << "Enter name of Music file : ";
	cin >> str;
	str = str + ".mp4";
	ifstream file(str.c_str());
	if (file.good())
	{
		cout << "Now Video is about to start\n\n";
		usleep(3000000);
		str = "mpv " + str;
		const char* cmdStr = str.c_str();
		system(cmdStr);
	}
	else
	{
		cout << "File not found\n";
	}
	return 0;
}
