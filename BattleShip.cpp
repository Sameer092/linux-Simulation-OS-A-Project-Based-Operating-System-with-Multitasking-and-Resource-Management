#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

void main_menu(), Play_game(), Credits(), Rules(), Score(), easy_PvP(), medium_PvP(), hard_PvP();
void attack_PvP(int size, char grid_p1[][15], char grid_p2[][15], char attack_P1[][15], char attack_P2[][15]);
int P1score = 0, P2score = 0;
int main()
{
	system("clear");
	cout << "\n\n\t\t\t\t     **********WELCOME TO BATTLE SHIP**********" << endl << endl << endl;
	cout << "        MAIN MENU" << endl << endl;
	main_menu();
}

bool winning_condition(int size, char grid[][15], char attack[][15])
{
	for (int i = 0; i < size; i++)
	{
		for (int c = 0; c < size; c++)
		{
			if (grid[i][c] == 'C' || grid[i][c] == 'c' || grid[i][c] == 'D' || grid[i][c] == 'B' || grid[i][c] == 'S')
			{
				if (attack[i][c] != 'H')
				{
					return false;
				}
			}
		}
	}
	return true;
}
void main_menu() // Main menu to choose Game play, Credits, Rules or Score
{
	int choice;
	cout << "    Press 1 to PLAY GAME" << endl;
	cout << "    Press 2 for CREDITS" << endl;
	cout << "    Press 3 for RULES" << endl;
	cout << "    Any other for PROGRAM TERMINATION" << endl;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case(1):
	{
		Play_game();
		break;
	}
	case(2):
	{
		Credits();
		break;
	}
	case(3):
	{
		Rules();
		break;
	}
	default:
	{
		cout << "Program is terminated!";
		break;
	}
	}
}


void DisplayArray(char arr[][15], int size) // Dispalying the array
{
	system("clear");
	cout << "\t\t\t\t";
	for (int k = 0; k < size; k++)
	{
		cout << k + 1 << " " << setw(4);
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "\t\t\t" << i + 1 << "\t";
		for (int c = 0; c < size; c++)
		{
			cout << arr[i][c] << "    ";
		}
		cout << endl;
	}
}


void checkcondition(char grid_P[][15], int N, int TS, char ch, int numofships, char fill) // Checking if the ship can be placed there or not for player
{
	int x, y;
	int count = 1;
	while (count <= numofships)
	{
		cout << "For number :" << count << endl;
		if (ch == 'h' || ch == 'H')
		{
			cout << "Enter column number\n";
			cin >> y;
			while (y > (TS - N) + 1)
			{
				cout << "Invalid input ! Crossed the size of array.\nInput again\n";
				cin >> y;
			}
			cout << "Enter row number : \n";
			cin >> x;
			for (int i = 0; i < N; i++)
			{
				for (int j = y; j <= (y + N) - 1; j++)
				{
					grid_P[x - 1][j - 1] = fill;
				}
			}
		}
		else if (ch == 'v' || ch == 'V')
		{
			cout << "Enter row number\n";
			cin >> x;
			while (x > (TS - N) + 1)
			{
				cout << "Invalid input ! Crossed the size of array.\nInput again\n";
				cin >> x;
			}
			cout << "Enter Column number : \n";
			cin >> y;
			for (int i = 0; i < N; i++)
			{
				for (int j = x; j <= (x + N) - 1; j++)
				{
					grid_P[j - 1][y - 1] = fill;
				}
			}
		}
		count++;
	}
}



void Play_game() // Menu to choose between player vs player or player vs machine
{
	int choice;
	cout << "    PLAYER VS PLAYER" << endl;
	cout << "    Press 1 for EASY mode" << endl;
	cout << "    Press 2 for MEDIUM mode" << endl;
	cout << "    Press 3 for HARD mode" << endl;
	cout << "    Any other for termination" << endl;
	cin >> choice;
	switch (choice)
	{
	case(1):
	{
		easy_PvP();
		break;
	}
	case(2):
	{
		medium_PvP();
		break;
	}
	case(3):
	{
		hard_PvP();
		break;
	}
	default:
	{
		cout << "Invalid Input";
		break;
	}
	}
}

void attack_PvP(int size, char grid_p1[][15], char grid_p2[][15], char attack_P1[][15], char attack_P2[][15]) // Attack of player 1 on player 2 
{
	int x, y;
	while (true)
	{
		cout << "Player 1 turn\n";
		cout << "Enter row number : ";
		cin >> x;
		cout << "Enter column number : ";
		cin >> y;
		while (x > size || y > size)
		{
			cout << endl << "Input again!" << endl;
			cout << "Enter row number : ";
			cin >> x;
			cout << "Enter column number : ";
			cin >> y;
		}
		x = x - 1;
		y = y - 1;
		if (grid_p2[x][y] == 'c' || grid_p2[x][y] == 'S' || grid_p2[x][y] == 'B' || grid_p2[x][y] == 'D' || grid_p2[x][y] == 'C')
		{
			attack_P1[x][y] = 'H';
		}
		else
		{
			attack_P1[x][y] = '*';
		}
		DisplayArray(attack_P1, size);
		if (winning_condition(size, grid_p2, attack_P1) == true)
		{
			cout << "\t\t\tPlayer 1 wins!";
			break;
		}

		cout << "Player 2 turn\n";

		cout << "Enter row number : ";
		cin >> x;
		cout << "Enter column number : ";
		cin >> y;
		while (x > size || y > size)
		{
			cout << endl << "Input again!" << endl;
			cout << "Enter row number : ";
			cin >> x;
			cout << "Enter column number : ";
			cin >> y;
		}
		x = x - 1;
		y = y - 1;
		if (grid_p1[x][y] == 'c' || grid_p1[x][y] == 'S' || grid_p1[x][y] == 'B' || grid_p1[x][y] == 'D' || grid_p1[x][y] == 'C')
		{
			attack_P2[x][y] = 'H';
		}
		else
		{
			attack_P2[x][y] = '*';
		}
		DisplayArray(attack_P2, size);
		if (winning_condition(size, grid_p1, attack_P2) == true)
		{
			cout << "\t\t\tPlayer 2 wins!";
			break;
		}
	}
}

void easy_PvP()
{
	int count, x, y;
	char ch;
	const int size = 15;
	char grid_p1[size][size];
	char grid_p2[size][size];
	//player 1 setting the ships
	for (int i = 0; i < 8; i++) // Making a 8x8 grid
	{
		for (int j = 0; j < 8; j++)
		{
			grid_p1[i][j] = '.';
		}
	}
	DisplayArray(grid_p1, 8);
	cout << "\nPlayer 1\n\n";
	cout << "Enter orientation : (h/v) \n";
	cin >> ch;
	while (ch != 'h' && ch != 'H' && ch != 'v' && ch != 'V')
	{
		cout << "Invalid orientation! \nEnter again (h/v)\n";
		cin >> ch;
	}
	cout << "Enter the cordinates where you want to put (8x1) carrier : \n";
	count = 1;
	while (count <= 2)          // For taking 2 carriers in easy mode
	{
		cout << "For Carrier :" << count << endl;
		if (ch == 'h' || ch == 'H')
		{
			y = 0;
			cout << "Enter row number : \n";
			cin >> x;
			for (int i = 0; i < 8; i++)
			{
				for (int j = y; j < 8; j++)
				{
					grid_p1[x - 1][j] = 'C';
				}
			}
		}
		else if (ch == 'v' || ch == 'V')
		{
			x = 0;
			cout << "Enter Column number : \n";
			cin >> y;
			for (int i = 0; i < 8; i++)
			{
				for (int j = x; j < 8; j++)
				{
					grid_p1[j][y - 1] = 'C';
				}
			}
		}
		count++;
	}
	DisplayArray(grid_p1, 8);
	cout << "Enter the cordinates where you want to put (5x1) battleship : \n";
	checkcondition(grid_p1, 5, 8, ch, 2, 'B');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 8);

	cout << "Enter the cordinates where you want to put (4x1) Cruiser : \n";
	checkcondition(grid_p1, 4, 8, ch, 2, 'c');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 8);

	cout << "Enter the cordinates where you want to put (3x1) Submarine : \n";
	checkcondition(grid_p1, 3, 8, ch, 2, 'S');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 8);

	cout << "Enter the cordinates where you want to put (2x1) Destroyer : \n";
	checkcondition(grid_p1, 2, 8, ch, 2, 'D');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 8);

	//Player 2 setting the ships
	for (int i = 0; i < 8; i++) // Making a 8x8 grid
	{
		for (int j = 0; j < 8; j++)
		{
			grid_p2[i][j] = '.';
		}
	}
	DisplayArray(grid_p2, 8);
	cout << "\nPlayer 2\n\n";
	cout << "Enter orientation : (h/v) \n";
	cin >> ch;
	while (ch != 'h' && ch != 'H' && ch != 'v' && ch != 'V')
	{
		cout << "Invalid orientation! \nEnter again (h/v)\n";
		cin >> ch;
	}
	cout << "Enter the cordinates where you want to put (8x1) carrier : \n";
	count = 1;
	while (count <= 2)          // For taking 2 carriers in easy mode
	{
		cout << "for Carrier :" << count << endl;
		if (ch == 'h' || ch == 'H')
		{
			y = 0;
			cout << "Enter row number : \n";
			cin >> x;
			for (int i = 0; i < 8; i++)
			{
				for (int j = y; j < 8; j++)
				{
					grid_p2[x - 1][j] = 'C';
				}
			}
		}
		else if (ch == 'v' || ch == 'V')
		{
			x = 0;
			cout << "Enter Column number : \n";
			cin >> y;
			for (int i = 0; i < 8; i++)
			{
				for (int j = x; j < 8; j++)
				{
					grid_p2[j][y - 1] = 'C';
				}
			}
		}
		count++;
	}
	DisplayArray(grid_p2, 8);
	cout << "Enter the cordinates where you want to put (5x1) battleship : \n";
	checkcondition(grid_p2, 5, 8, ch, 2, 'B');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 8);

	cout << "Enter the cordinates where you want to put (4x1) Cruiser : \n";
	checkcondition(grid_p2, 4, 8, ch, 2, 'c');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 8);

	cout << "Enter the cordinates where you want to put (3x1) Submarine : \n";
	checkcondition(grid_p2, 3, 8, ch, 2, 'S');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 8);

	cout << "Enter the cordinates where you want to put (2x1) Destroyer : \n";
	checkcondition(grid_p2, 2, 8, ch, 2, 'D');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 8);


	char attack_P1[size][size];
	char attack_P2[size][size];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			attack_P1[i][j] = '.';
			attack_P2[i][j] = '.';
		}
	}
	DisplayArray(attack_P1, 8);
	cout << "ITS TIME TO ATTACK" << endl;
	attack_PvP(8, grid_p1, grid_p2, attack_P1, attack_P2);
}

void medium_PvP()
{
	char ch;
	const int size = 15;
	char grid_p1[size][size];
	char grid_p2[size][size];
	cout << "\t\t\tPlayer 1\n\n";                      //player 1 setting the ships
	for (int i = 0; i < 12; i++) // Making a 8x8 grid
	{
		for (int j = 0; j < 12; j++)
		{
			grid_p1[i][j] = '.';
		}
	}
	DisplayArray(grid_p1, 12);
	cout << "Enter orientation : (h/v) \n";
	cin >> ch;
	while (ch != 'h' && ch != 'H' && ch != 'v' && ch != 'V')
	{
		cout << "Invalid orientation! \nEnter again (h/v)\n";
		cin >> ch;
	}
	cout << "Enter the cordinates where you want to put (8x1) carrier : \n";
	checkcondition(grid_p1, 8, 12, ch, 3, 'C');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 12);

	cout << "Enter the cordinates where you want to put (5x1) battleship : \n";
	checkcondition(grid_p1, 5, 12, ch, 3, 'B');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 12);

	cout << "Enter the cordinates where you want to put (4x1) Cruiser : \n";
	checkcondition(grid_p1, 4, 12, ch, 3, 'c');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 12);

	cout << "Enter the cordinates where you want to put (3x1) Submarine : \n";
	checkcondition(grid_p1, 3, 12, ch, 3, 'S');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 12);

	cout << "Enter the cordinates where you want to put (2x1) Destroyer : \n";
	checkcondition(grid_p1, 2, 12, ch, 3, 'D');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 12);

	cout << "\t\t\tPlayer 2\n\n";                      //Player 2 setting the ships
	for (int i = 0; i < 12; i++) // Making a 8x8 grid
	{
		for (int j = 0; j < 12; j++)
		{
			grid_p2[i][j] = '.';
		}
	}
	DisplayArray(grid_p2, 12);
	cout << "Enter orientation : (h/v) \n";
	cin >> ch;
	while (ch != 'h' && ch != 'H' && ch != 'v' && ch != 'V')
	{
		cout << "Invalid orientation! \nEnter again (h/v)\n";
		cin >> ch;
	}
	cout << "Enter the cordinates where you want to put (8x1) carrier : \n";
	checkcondition(grid_p2, 8, 12, ch, 3, 'C');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 12);

	cout << "Enter the cordinates where you want to put (5x1) battleship : \n";
	checkcondition(grid_p2, 5, 12, ch, 3, 'B');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 12);

	cout << "Enter the cordinates where you want to put (4x1) Cruiser : \n";
	checkcondition(grid_p2, 4, 12, ch, 3, 'c');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 12);

	cout << "Enter the cordinates where you want to put (3x1) Submarine : \n";
	checkcondition(grid_p2, 3, 12, ch, 3, 'S');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 12);

	cout << "Enter the cordinates where you want to put (2x1) Destroyer : \n";
	checkcondition(grid_p2, 2, 12, ch, 3, 'D');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 12);

	char attack_P1[size][size];
	char attack_P2[size][size];
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			attack_P1[i][j] = '.';
			attack_P2[i][j] = '.';
		}
	}
	DisplayArray(attack_P1, 12);
	cout << "ITS TIME TO ATTACK" << endl;
	attack_PvP(12, grid_p1, grid_p2, attack_P1, attack_P2);
}

void hard_PvP()
{
	char ch;
	const int size = 15;
	char grid_p1[size][size];
	char grid_p2[size][size];
	cout << "\t\t\tPlayer 1\n\n";                      //player 1 setting the ships
	for (int i = 0; i < 15; i++) // Making a 8x8 grid
	{
		for (int j = 0; j < 15; j++)
		{
			grid_p1[i][j] = '.';
		}
	}
	DisplayArray(grid_p1, 15);
	cout << "Enter orientation : (h/v) \n";
	cin >> ch;
	while (ch != 'h' && ch != 'H' && ch != 'v' && ch != 'V')
	{
		cout << "Invalid orientation! \nEnter again (h/v)\n";
		cin >> ch;
	}
	cout << "Enter the cordinates where you want to put (8x1) carrier : \n";
	checkcondition(grid_p1, 8, 15, ch, 4, 'C');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 15);

	cout << "Enter the cordinates where you want to put (5x1) battleship : \n";
	checkcondition(grid_p1, 5, 15, ch, 4, 'B');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 15);

	cout << "Enter the cordinates where you want to put (4x1) Cruiser : \n";
	checkcondition(grid_p1, 4, 15, ch, 4, 'c');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 15);

	cout << "Enter the cordinates where you want to put (3x1) Submarine : \n";
	checkcondition(grid_p1, 3, 15, ch, 4, 'S');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 15);

	cout << "Enter the cordinates where you want to put (2x1) Destroyer : \n";
	checkcondition(grid_p1, 2, 15, ch, 4, 'D');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p1, 15);

	cout << "\t\t\tPlayer 2\n\n";                      //Player 2 setting the ships
	for (int i = 0; i < 15; i++) // Making a 8x8 grid
	{
		for (int j = 0; j < 15; j++)
		{
			grid_p2[i][j] = '.';
		}
	}
	DisplayArray(grid_p2, 15);
	cout << "Enter orientation : (h/v) \n";
	cin >> ch;
	while (ch != 'h' && ch != 'H' && ch != 'v' && ch != 'V')
	{
		cout << "Invalid orientation! \nEnter again (h/v)\n";
		cin >> ch;
	}
	cout << "Enter the cordinates where you want to put (8x1) carrier : \n";
	checkcondition(grid_p2, 8, 15, ch, 4, 'C');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 15);

	cout << "Enter the cordinates where you want to put (5x1) battleship : \n";
	checkcondition(grid_p2, 5, 15, ch, 4, 'B');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 15);

	cout << "Enter the cordinates where you want to put (4x1) Cruiser : \n";
	checkcondition(grid_p2, 4, 15, ch, 4, 'c');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 15);

	cout << "Enter the cordinates where you want to put (3x1) Submarine : \n";
	checkcondition(grid_p2, 3, 15, ch, 4, 'S');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 15);

	cout << "Enter the cordinates where you want to put (2x1) Destroyer : \n";
	checkcondition(grid_p2, 2, 15, ch, 4, 'D');
	cout << "The grid becomes : \n\n";
	DisplayArray(grid_p2, 15);
	char attack_P1[size][size];
	char attack_P2[size][size];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			attack_P1[i][j] = '.';
			attack_P2[i][j] = '.';
		}
	}
	DisplayArray(attack_P1, 15);
	cout << "ITS TIME TO ATTACK" << endl;
	attack_PvP(15, grid_p1, grid_p2, attack_P1, attack_P2);
}



void Credits() // Displaying the Credits
{
	cout << "\t\t\t\t\t\t\tCreated by\n";
	cout << "\t\t\t********************************************************************************" << endl;
	cout << "\t\t\t21F-9198\t\t\t 21F-9083\n\t\t\t\t21F-9122\t\t\t\t\t21F-9068\n\t\t\t\t\t\t\tBSCS(4A)" << endl;
	cout << "\t\t\t********************************************************************************" << endl << endl;
	main_menu();
}


void Rules() // Displaying the Rules
{
	cout << "\t************ Rules ************" << endl << endl;
	cout << "1. You have to destroy your opponent's war ships before he destroys yours." << endl;
	cout << "2. The battlefield size is 8x8 grid(EASY MODE),12x12 grid(MEDIUM MODE),15x15 grid(HARD MODE) in which you place your ships." << endl;
	cout << "3. You can place your ships by entering its orientation. For horizontal orientation, type 'h' in the orientation option and type 'v' for vertical." << endl;
	cout << "4. x is the row number and y is the column number." << endl;
	cout << "5. You have 4 battle ships: Carrier (8 units long), Battleship (5 units long),Cruiser (4 units long), Destroyer (2 units long) and Submarine (3 units long)." << endl;
	cout << "6. After placing your ships, you can attack the enemy area. To attack a area, enter its x y coordinate." << endl;
	cout << "7. Attacked point to the enemy ship is denoted by a 'H'." << endl;
	cout << "8. Attack miss is denoted by a '*'." << endl << endl;
	main_menu();
}
