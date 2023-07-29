#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
int main()
{
	string str;
	cout << "Enter name of Music file : ";
	cin >> str;
	str = str+".mp3";
       	ifstream file(str.c_str());
    	if (file.good())
    	{
		cout << "Now Music is about to start\nTo stop it, Press q key aand to just pause it, Press space key\n\n";
		usleep(3000000);
    	    	str = "mpg123 " + str;
		const char* cmdStr = str.c_str();
		system(cmdStr);
    	} 
    	else 
    	{
        	cout << "File not found\n";
    	}
	return 0;
}
