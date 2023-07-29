#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
int main()
{
	string str;
	cout << "Clock will display in few seconds : \nNote: Pressing ctrl+c together will close the clock\n\n";
	usleep(5000000);
    	str = "watch -t -n 1 date +\"%T\"";
	const char* cmdStr = str.c_str();
	system(cmdStr);
	return 0;
}
