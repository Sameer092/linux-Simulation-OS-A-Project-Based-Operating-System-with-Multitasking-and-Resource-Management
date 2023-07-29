#include<iostream>
#include<cmath>
using namespace std;
void Calculator(float x, float y, char choice)
{
	if (choice == '1')
	{
		cout << "Addition\n\nx + y = " << x + y << endl;
	}
	else if (choice == '2')
	{
		cout << "Subtraction\n\nx - y = " << x - y << endl;
	}
	else if (choice == '3')
	{
		cout << "Multiplication\n\nx * y = " << x * y << endl;
	}
	else if (choice == '4')
	{
		cout << "Division\n\nx / y = " << x / y << endl;
	}
	else if (choice == '5')
	{
		cout << "Power\n\nx ^ y = " << pow(x,y) << endl;
	}
}
int main()
{
	system("clear");
	cout << "\n\n\t\t********************\n";
	cout << "\t\t**** Calculator ****\n";
	cout << "\t\t********************\n\n";
	float x, y;
	char choice;
	cout << "1: Addition\n";
	cout << "2: Subtraction\n";
	cout << "3: Multiplication\n";
	cout << "4: Division\n";
	cout << "5: Power\n";
	cout << "Input your choice from above : ";
	cin >> choice;
	if (choice >= '1' && choice <= '5')
	{
		cout << "Enter number x : ";
		cin >> x;
		cout << "Enter number y : ";
		cin >> y;
		Calculator(x, y, choice);
	}
	else
	{
		cout << "Invalid Input!";
	}
}
