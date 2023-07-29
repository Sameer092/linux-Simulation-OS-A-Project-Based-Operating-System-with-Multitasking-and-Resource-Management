#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main() 
{
	int n;
	string str,year,month;
       	cout << "Select from options below : \n1: Display Whole Calendar\n2: Display A specific month\n\nEnter your choice";
	cin >> n;
	if (n == 1)
	{
		cout << "Enter Year (YYYY): ";
		cin >> year;
		cout << "\nOpening Calendar\n";
		usleep(2000000);
		str = "cal " + year;
		const char* cmdStr = str.c_str();
		system(cmdStr);
	}
	else if (n == 2)
	{
		cout << "Enter Year YYYY: ";
		cin >> year;	
		cout << "Enter Month MM: ";
		cin >> month;
		cout << "\nOpening Calendar\n";
		usleep(2000000);
		str = "cal " + month + " " + year;
		const char* cmdStr = str.c_str();
		system(cmdStr);
	}
    	return 0;
}
