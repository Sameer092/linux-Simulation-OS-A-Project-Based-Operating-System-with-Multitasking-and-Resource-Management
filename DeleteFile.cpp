#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	string str1,str;
	char choice;
	cout << "Enter name of file you want to delete (with extension e.g abc.cpp) : ";
	cin >> str1;
	ifstream file(str1);    
	if (file.is_open()) 
	{
        	cout << "File found!" << endl;
        	file.close();
        	cout << "Note: The file will be PERMANENTLY DELETED.\nAre you sure? \nif yes, press 1 else press anyother key : ";
		cin >> choice;
        	if (choice == '1')
		{
			cout << "Deleting file ..";
			str = "rm " + str1;
			const char* cmdStr = str.c_str();
			system(cmdStr);
			cout << "\nFile Deleted permanently\n";
		}
		else
		{
			cout << "File not deleted..\n";
		}
    	} 
    	else 
    	{
        	cout << "Source File not found!" << endl;
    	}
	return 0;
}
