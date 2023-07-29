#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	string str1,str2,str;
	cout << "Enter name of file you want to copy (with extension e.g abc.cpp) : ";
	cin >> str1;
	ifstream file(str1);    
	if (file.is_open()) 
	{
        	cout << "Source File found!" << endl;
        	file.close();
        	cout << "Enter Destination file name (with extension e.g abc.cpp) in which you want to copy : ";
		cin >> str2;
		int n;
        	cout << "Select from options below : \n1: Copy and overwrite content (if any)\n2: Copy and append (if any)\n\nEnter your choice";
		cin >> n;
		if (n == 1)
		{
			cout << "Copying file ..";
			str = "cp " + str1 + " " + str2;
			const char* cmdStr = str.c_str();
			system(cmdStr);
			cout << "\nFile Copied!\n";
		}
		else if (n == 2)
		{
			cout << "Copying file ..";
			str = "cat " + str1 + " >> " + str2;
			const char* cmdStr = str.c_str();
			system(cmdStr);
			cout << "\nFile Copied!\n";
		}
    	} 
    	else 
    	{
        	cout << "Source File not found!" << endl;
    	}
	return 0;
}
