#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	string str;
	cout << "Enter name of file you want to open (with extension e.g abc.cpp) : ";
	cin >> str;
	ifstream file(str);    
	if (file.is_open()) 
	{
        	cout << "File found!" << endl;
        	file.close();
        	int n;
        	cout << "Select from options below : \n1: Opn in nano mode\n2: Open in text editor\n\nEnter your choice";
		cin >> n;
		if (n == 1)
		{
			cout << "Opening a file ..";
			str = "nano " + str;
			const char* cmdStr = str.c_str();
			system(cmdStr);
			cout << "\nFile Opened!\n";
		}
		else if (n == 2)
		{
			cout << "Opening a file ..";
			str = "xdg-open " + str;
			const char* cmdStr = str.c_str();
			system(cmdStr);
			cout << "\nFile Opened!\n";
		}
    	} 
    	else 
    	{
        	cout << "File not found!" << endl;
    	}
	return 0;
}
