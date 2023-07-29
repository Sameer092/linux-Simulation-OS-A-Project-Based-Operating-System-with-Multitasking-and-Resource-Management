#include<iostream>
#include<ctime>
#include<iomanip>
#include<unistd.h>
#include<cstring>
#include<string>
#include<cstdlib>
#include<fstream>
//#include <Windows.h>

int moves = 15, score;

using namespace std;

int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

//to add delay by using loop
void delay()
{
	for (int i = 0; i < 100000; )
	{
		i++;
	}

}

//score function
void scorer(char alpha)
{
	if (alpha == 'R' || alpha == '%')
	{
		score += 30;
	}
	else if (alpha == 'Y' || alpha == '?')
	{
		score += 30;
	}
	else if (alpha == 'G' || alpha == '#')
	{
		score += 40;
	}
	else if (alpha == 'B' || alpha == '&')
	{
		score += 50;
	}
	else if (alpha == 'O' || alpha == '*')
	{
		score += 60;
	}
	else
	{
		score += 70;
	}

}

char ranch()
{
	int alpha;
	do
	{
		alpha = rand() % 25 + 65;
	} while (alpha != 'R' && alpha != 'Y' && alpha != 'G' && alpha != 'B' && alpha != 'O');

	return alpha;
}


void start()
{
	cout << "              *             " << endl;
	cout << "             * *            " << endl;
	cout << "            *  *            " << endl;
	cout << "           *   *            " << endl;
	cout << "          *    *            " << endl;
	cout << "         *     *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "               *            " << endl;
	cout << "       * * * * * * * * *    " << endl;
	cout << "       * * * * * * * * *    " << endl;

}

void start2()
{
	cout << "           * * * * * * *    " << endl;
	cout << "         *               *  " << endl;
	cout << "       *                   *  " << endl;
	cout << "      *                      * " << endl;
	cout << "      *                       *" << endl;
	cout << "                              *" << endl;
	cout << "                             *" << endl;
	cout << "                           *" << endl;
	cout << "                         *" << endl;
	cout << "                       *" << endl;
	cout << "                     *" << endl;
	cout << "                   *" << endl;
	cout << "                 *" << endl;
	cout << "               *" << endl;
	cout << "             *" << endl;
	cout << "           *" << endl;
	cout << "         *" << endl;
	cout << "       *" << endl;
	cout << "     * * * * * * * * * * * * * *" << endl;
	

}

void start3()
{
	cout << "       * * * * * *          " << endl;
	cout << "     *             *        " << endl;
	cout << "   *                 *      " << endl;
	cout << "                      *     " << endl;
	cout << "                      *    " << endl;
	cout << "                      *    " << endl;
	cout << "                    *       " << endl;
	cout << "                  *         " << endl;
	cout << "                *           " << endl;
	cout << "    * * * * * *             " << endl;
	cout << "                *           " << endl;
	cout << "                  *         " << endl;
	cout << "                    *       " << endl;
	cout << "                      *     " << endl;
	cout << "                      *     " << endl;
	cout << "                      *     " << endl;
	cout << "   *                 *      " << endl;
	cout << "     *             *        " << endl;
	cout << "       * * * * * *          " << endl;





}


void start4()
{
	cout << endl << endl << endl << endl;
	cout << " *         * * *   * * * * *    * * * *     " << endl;
	cout << " *         *           *        *           " << endl;
	cout << " *         * * *       *        * * * *     " << endl;
	cout << " *         *           *              *     " << endl;
	cout << " * * * *   * * *       *        * * * *     " << endl;
	cout << "                                            " << endl;
	cout << "                                            " << endl;
	cout << "                                         *  " << endl;
	cout << "  * * *    *             *       *   *   *  " << endl;
	cout << "  *    *   *            * *       * *    *  " << endl;
	cout << "  * * *    *           * * *       *     *  " << endl;
	cout << "  *        *          *     *      *        " << endl;
	cout << "  *        * * * *   *       *     *     *  " << endl;
	cout << "                                            " << endl;

}

char packetchar(char alpha)
{
	if (alpha == 'R')
	{
		return '%';
	}
	else if (alpha == 'Y')
	{
		return '?';
	}
	else if (alpha == 'G')
	{
		return '#';
	}
	else if (alpha == 'B')
	{
		return '&';
	}
	else if (alpha == 'O')
	{
		return '*';
	}
	else
	{
	    return ' ';
	}

}

bool packetchecker(char alpha)
{
	if (alpha == '*')
		return 1;
	else if (alpha == '&')
		return 1;
	else if (alpha == '#')
		return 1;
	else if (alpha == '?')
		return 1;
	else if (alpha == '%')
		return 1;
	else
		return 0;


}

void startval1(char arr[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			do
			{
				arr[i][j] = ranch();

			} while (((arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]) || (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])) || ((arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j]) || (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2])));

		}
	}

}

void startval2(char arr[][9])
{
	ifstream infile, inner;
	infile.open("SAVE.txt");
	inner.open("MOVES.txt");
	if (infile.is_open() && inner.is_open())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				infile >> arr[i][j];
			}
		}
		inner >> moves;
		infile.close();
		inner.close();
	}
	else
	{
		cout << "\n\nNO SAVE FILE FOUND!";
		cout << "\n\nSTARTING NEW GAME!";
		usleep(1500000);
		startval1(arr);

	}
}


void display(char arr[9][9])
{
	cout << "======================================== CANDY CRUSH ========================================\n\n";
	cout << "\t\tMOVES REMAINING  :  " << moves << "    SCORE  :  " << score << endl;
	cout << "\t\tSpecial Characters Description :-  \n";
	cout << "\t\t1) Small Letter means Strip Candy of Same Captital Letter\n";
	cout << "\t\t2) For Packet Candies Following are the Special Characters :- \n";
	//cout << "\t\t% = R\t* = O\t& = B\t? = Y\t# = G\n\n\n";
	cout << "\t\t%\t$\t&\t?\t#\n\n\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 'R')
			{
				cout << setw(8) << '%';
			}
			else if (arr[i][j] == 'O')
			{
				cout << setw(8) << '$';
			}
			else if (arr[i][j] == 'B')
			{
				cout << setw(8) << '&';
			}
			else if (arr[i][j] == 'Y')
			{
				cout << setw(8) << '?';
			}
			else if (arr[i][j] == 'G')
			{
				cout << setw(8) << '#';
			}
		}
		cout << endl << endl;
	}

}

void display(char arr[9][9], int row, int col)//For Swapping Display + sign
{
	cout << "======================================== CANDY CRUSH ========================================\n\n";
	cout << "\t\tMOVES REMAINING  :  " << moves << "    SCORE  :  " << score << endl;
	cout << "\t\tSpecial Characters Description :-  \n";
	cout << "\t\t1) Small Letter means Strip Candy of Same Captital Letter\n";
	cout << "\t\t2) For Packet Candies Following are the Special Characters :- \n";
	//cout << "\t\t% = R\t* = O\t& = B\t? = Y\t# = G\n\n\n";
	cout << "\t\t%\t$\t&\t?\t#\n\n\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == row && j == col)
			{
				if (arr[i][j] == 'R')
				{
					cout << setw(8) << '+' << '%';
				}
				else if (arr[i][j] == 'O')
				{
					cout << setw(8) << '+' << '$';
				}
				else if (arr[i][j] == 'B')
				{
					cout << setw(8) << '+' << '&';
				}
				else if (arr[i][j] == 'Y')
				{
					cout << setw(8) << '+' << '?';
				}
				else if (arr[i][j] == 'G')
				{
					cout << setw(8) << '+' << '#';
				}
			}
			else
			{
				if (arr[i][j] == 'R')
				{
					cout << setw(8) << '%';
				}
				else if (arr[i][j] == 'O')
				{
					cout << setw(8) << '$';
				}
				else if (arr[i][j] == 'B')
				{
					cout << setw(8) << '&';
				}
				else if (arr[i][j] == 'Y')
				{
					cout << setw(8) << '?';
				}
				else if (arr[i][j] == 'G')
				{
					cout << setw(8) << '#';
				}
			}
		}
		cout << endl << endl;
	}

}

void stripexecute3(char arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] >= 97 && arr[i][j] <= 122)
			{
				//for rowss
				if (arr[i][j] == arr[i + 1][j] - 32 && arr[i][j] == arr[i - 1][j] - 32)
				{
					for (int k = 0; k < 9; k++)
					{
						arr[i][k] = '0';
					}
					arr[i][j] = '0';
					arr[i + 1][j] = '0';
					arr[i - 1][j] = '0';
					scorer(arr[i][j]);
				}

				else if (arr[i][j] == arr[i + 1][j] - 32 && arr[i][j] == arr[i + 2][j] - 32)
				{
					for (int k = 0; k < 9; k++)
					{
						arr[i][k] = '0';
					}
					arr[i][j] = '0';
					arr[i + 2][j] = '0';
					arr[i + 1][j] = '0';
					scorer(arr[i][j]);
				}

				else if (arr[i][j] == arr[i - 1][j] - 32 && arr[i][j] == arr[i - 2][j] - 32)
				{
					for (int k = 0; k < 9; k++)
					{
						arr[i][k] = '0';
					}
					arr[i][j] = '0';
					arr[i - 1][j] = '0';
					arr[i - 2][j] = '0';
					scorer(arr[i][j]);
				}




				//for columns
				else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1] - 32)
				{
					for (int k = 0; k < 9; k++)
					{
						arr[i][k] = '0';
					}
					arr[i][j] = '0';
					arr[i][j + 1] = '0';
					arr[i][j - 1] = '0';
					scorer(arr[i][j]);
				}

				else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] - 32)
				{
					for (int k = 0; k < 9; k++)
					{
						arr[i][k] = '0';
					}
					arr[i][j] = '0';
					arr[i][j + 1] = '0';
					arr[i][j + 2] = '0';
					scorer(arr[i][j]);
				}

				else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2] - 32)
				{
					for (int k = 0; k < 9; k++)
					{
						arr[i][k] = '0';
					}
					arr[i][j] = '0';
					arr[i][j - 1] = '0';
					arr[i][j - 2] = '0';
					scorer(arr[i][j]);
				}

			}
		}
	}
}


void packetexecute3(char arr[][9])
{
	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			flag = packetchecker(arr[i][j]);
			if (flag == 1)
			{
				if (arr[i][j] == '#')
				{
					if (arr[i + 1][j] == 'G' && arr[i - 1][j] == 'G')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}



					else if (arr[i][j + 1] == 'G' && arr[i][j - 1] == 'G')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i][j + 1] == 'G' && arr[i][j + 2] == 'G')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i + 1][j] == 'G' && arr[i + 2][j] == 'G')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i][j - 1] == 'G' && arr[i][j - 2] == 'G')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i - 1][j] == 'G' && arr[i - 2][j] == 'G')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}


				}

				if (arr[i][j] == '%')
				{
					if (arr[i + 1][j] == 'R' && arr[i - 1][j] == 'R')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}



					else if (arr[i][j + 1] == 'R' && arr[i][j - 1] == 'R')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i][j + 1] == 'R' && arr[i][j + 2] == 'R')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i + 1][j] == 'R' && arr[i + 2][j] == 'R')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i][j - 1] == 'R' && arr[i][j - 2] == 'R')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i - 1][j] == 'R' && arr[i - 2][j] == 'R')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}


				}

				if (arr[i][j] == '?')
				{
					if (arr[i + 1][j] == 'Y' && arr[i - 1][j] == 'Y')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}



					else if (arr[i][j + 1] == 'Y' && arr[i][j - 1] == 'Y')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i][j + 1] == 'Y' && arr[i][j + 2] == 'Y')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i + 1][j] == 'Y' && arr[i + 2][j] == 'Y')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i][j - 1] == 'Y' && arr[i][j - 2] == 'Y')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}

					else if (arr[i - 1][j] == 'Y' && arr[i - 2][j] == 'Y')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}


				}

				if (arr[i][j] == '&')
				{
					if (arr[i + 1][j] == 'B' && arr[i - 1][j] == 'B')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);

					}



					else if (arr[i][j + 1] == 'B' && arr[i][j - 1] == 'B')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}

					else if (arr[i][j + 1] == 'B' && arr[i][j + 2] == 'B')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}

					else if (arr[i + 1][j] == 'B' && arr[i + 2][j] == 'B')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}

					else if (arr[i][j - 1] == 'B' && arr[i][j - 2] == 'B')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}

					else if (arr[i - 1][j] == 'B' && arr[i - 2][j] == 'B')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}


				}

				if (arr[i][j] == '*')
				{
					if (arr[i + 1][j] == 'O' && arr[i - 1][j] == 'O')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}



					else if (arr[i][j + 1] == 'O' && arr[i][j - 1] == 'O')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}

					else if (arr[i][j + 1] == 'O' && arr[i][j + 2] == 'O')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}

					else if (arr[i + 1][j] == 'O' && arr[i + 2][j] == 'O')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}

					else if (arr[i][j - 1] == 'O' && arr[i][j - 2] == 'O')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}

					else if (arr[i - 1][j] == 'O' && arr[i - 2][j] == 'O')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = '0';
						arr[i - 1][j + 1] = '0';
						arr[i][j + 1] = '0';
						arr[i + 1][j + 1] = '0';
						arr[i + 1][j] = '0';
						arr[i + 1][j - 1] = '0';
						arr[i][j - 1] = '0';
						arr[i - 1][j - 1] = '0';
						scorer(arr[i][j]);
					}


				}



			}
		}
	}
}


void sel1(char arr[9][9])
{
	int i = 0, j = 0;
	char input;
	do
	{
		cout << "Instructions :-\n";
		cout << "Enter W to Up\nEnter D to Right\nEnter S to Down\nEnter A to Left\n\n";
		cout << "Select the First CANDY to Swap \nPress Enter Key After Every Input\nEnter SPACE to Select :- \n\n";
		cout << "\n\nENTER  :  ";

		input = getchar();
		if (input == 'A' || input == 'a')
		{
			if (j - 1 < 0)
			{
				j = 8;
			}
			else
			{
				j--;
			}
		}
		else if (input == 'S' || input == 's')
		{
			if (i + 1 >= 9)
			{
				i = 0;
			}
			else
			{
				i++;
			}
		}
		else if (input == 'D' || input == 'd')
		{
			if (j + 1 >= 9)
			{
				j = 0;
			}
			else
			{
				j++;
			}
		}
		else if (input == 'W' || input == 'w')
		{
			if (i - 1 < 0)
			{
				i = 8;
			}
			else
			{
				i--;
			}
		}
		system("clear");
		display(arr, i, j);

	} while (input != 32);
	row1 = i; col1 = j;
}



void sel3()
{
	char input;
	cout << "Instructions :-\n";
	cout << "Enter W to Up\nEnter D to Right\nEnter S to Down\nEnter A to Left\n\n";
	cout << "\n\nENTER  :  ";
	cin.ignore();
	input = getchar();

	bool flag = 1;
	do
	{
		if (input == 'W' || input == 'w')
		{
			row2 = row1 - 1;
			flag = 1;
		}
		else if (input == 'S' || input == 's')
		{
			row2 = row1 + 1;
			flag = 1;
		}
		else if (input == 'A' || input == 'a')
		{
			col2 = col1 - 1;
			flag = 1;
		}
		else if (input == 'D' || input == 'd')
		{
			row2 = row1 + 1;
			flag = 1;
		}
		else
		{
			cout << "\n\nINVALID INPUT\n\n";
			flag = 0;
		}
	} while (flag == 0);

}


void sel2(char arr[9][9])
{
	int i = row1, j = col1;
	char input;

	cout << "Instructions :-\n";
	cout << "Enter W to Up\nEnter D to Right\nEnter S to Down\nEnter A to Left\n\n";
	cout << "Select the SECOND CANDY to Swap \nPress Enter Key After Every Input\nEnter SPACE to Select :- \n\n";
	cin.ignore();
	input = getchar();

	if (input == 'A' || input == 'a')
	{
		if (j - 1 < 0)
		{
			j = 8;
		}
		else
		{
			j--;
		}
	}
	else if (input == 'S' || input == 's')
	{
		if (i + 1 >= 9)
		{
			i = 0;
		}
		else
		{
			i++;
		}
	}
	else if (input == 'D' || input == 'd')
	{
		if (j + 1 >= 9)
		{
			j = 0;
		}
		else
		{
			j++;
		}
	}
	else if (input == 'W' || input == 'w')
	{
		if (i - 1 < 0)
		{
			i = 8;
		}
		else
		{
			i--;
		}
	}
	system("clear");
	display(arr, i, j);
	row2 = i; col2 = j;
}

void fifercheck(char arr[][9], char alpha1, char alpha2)
{
	if (alpha1 == '@')
	{
		scorer(alpha1);
		alpha1 == '0';
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (arr[i][j] == alpha2);
				{
					arr[i][j] = '0';
				}
			}
		}

	}
	else if (alpha2 == '@')
	{
		scorer(alpha2);
		alpha2 == '0';
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (arr[i][j] == alpha1);
				{
					arr[i][j] = '0';
				}
			}
		}
	}
}
void swap(char arr[9][9])
{
	char temp;
	sel1(arr);
	sel2(arr);
	temp = arr[row1][col1];
	arr[row1][col1] = arr[row2][col2];
	arr[row2][col2] = temp;
	if (arr[row2][col2] == '@' && arr[row1][col1] == '@')
	{

		scorer(arr[row2][col2]);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				arr[i][j] = 0;
			}
		}
	}
	else if (arr[row2][col2] == '@' || arr[row1][col1] == '@')
	{
		fifercheck(arr, arr[row2][col2], arr[row1][col1]);
	}
	else if (arr[row2][col2] <= 97 && arr[row1][col1] <= 122)
		moves--;
	system("clear");
	cout << "AFTER SWAPPING :-\n\n";
	display(arr);

}

void check3(char arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			packetexecute3(arr);
			stripexecute3(arr);

			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i - 1][j])
			{
				scorer(arr[i][j]);

				arr[i][j] = '0';
				arr[i + 1][j] = '0';
				arr[i - 1][j] = '0';

			}

			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				scorer(arr[i][j]);
				arr[i][j] = '0';
				arr[i + 1][j] = '0';
				arr[i + 2][j] = '0';
			}

			else if (arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i - 1][j])
			{
				scorer(arr[i][j]);
				arr[i][j] = '0';
				arr[i + 1][j] = '0';
				arr[i - 1][j] = '0';
			}


			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1])
			{
				scorer(arr[i][j]);
				arr[i][j] = '0';
				arr[i][j + 1] = '0';
				arr[i][j - 1] = '0';
			}

			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = '0';
				arr[i][j + 1] = '0';
				arr[i][j - 1] = '0';
			}

			else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = '0';
				arr[i][j + 1] = '0';
				arr[i][j - 1] = '0';
			}


		}
	}


	system("clear");
	display(arr);
}


void check4(char arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j])
			{
				scorer(arr[i][j]);
				arr[i][j] = arr[i][j] + 32;
				arr[i + 1][j] = '0';
				arr[i - 1][j] = '0';
				arr[i - 2][j] = '0';
			}

			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i + 2][j])
			{
				scorer(arr[i][j]);
				arr[i][j] = arr[i][j] + 32;
				arr[i + 1][j] = '0';
				arr[i - 1][j] = '0';
				arr[i + 2][j] = '0';
			}


			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 3][j] && arr[i][j] == arr[i + 2][j])
			{
				scorer(arr[i][j]);
				arr[i][j] = arr[i][j] + 32;
				arr[i + 1][j] = '0';
				arr[i + 3][j] = '0';
				arr[i + 2][j] = '0';
			}


			else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 3][j] && arr[i][j] == arr[i - 2][j])
			{
				scorer(arr[i][j]);
				arr[i][j] = arr[i][j] + 32;
				arr[i - 1][j] = '0';
				arr[i - 3][j] = '0';
				arr[i - 2][j] = '0';
			}


			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j + 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = arr[i][j] + 32;
				arr[j + 1][j] = '0';
				arr[j - 1][j] = '0';
				arr[j + 2][j] = '0';
			}


			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = arr[i][j] + 32;
				arr[j + 1][j] = '0';
				arr[j - 1][j] = '0';
				arr[j - 2][j] = '0';
			}

			else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2] && arr[i][j] == arr[i][j - 3])
			{
				scorer(arr[i][j]);
				arr[i][j] = arr[i][j] + 32;
				arr[j - 1][j] = '0';
				arr[j - 2][j] = '0';
				arr[j - 3][j] = '0';
			}

			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
			{
				scorer(arr[i][j]);
				arr[i][j] = arr[i][j] + 32;
				arr[j + 1][j] = '0';
				arr[j + 2][j] = '0';
				arr[j + 3][j] = '0';
			}


		}
	}


	system("clear");
	display(arr);
}

void down(char arr[][9])
{
	char temp;
	bool flag = 1;
	do
	{
		flag = 1;
		for (int i = 0; i < 9 && flag == 1; i++)
		{
			for (int j = 0; j < 9 && flag == 1; j++)
			{
				if (arr[i][j] != 0)
				{
					flag = 1;
				}
				else
				{
					flag = 0;
				}
			}
		}
		if (flag == 1)
		{
			break;
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (arr[i][j] == '0' && i != 0)
				{
					temp = arr[i][j];
					arr[i][j] = arr[i - 1][j];
					arr[i - 1][j] = temp;
				}
				if (arr[0][j] == '0')
				{
					flag = 0;
				}
			}
		}



	} while (flag != 0);

}

void newch(char arr[][9])
{
	down(arr);


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == '0')
			{
				arr[i][j] = ranch();
			}
		}
	}


	system("clear");

	display(arr);
}

void check5(char arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i + 2][j])
			{
				scorer(arr[i][j]);
				arr[i][j] = '@';
				arr[i + 1][j] = '0';
				arr[i - 1][j] = '0';
				arr[i - 2][j] = '0';
				arr[i + 2][j] = '0';
			}

			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2] && arr[i][j] == arr[i][j + 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = '@';
				arr[i][j + 1] = '0';
				arr[i][j - 1] = '0';
				arr[i][j - 2] = '0';
				arr[i][j + 2] = '0';
			}
		}
	}


	system("clear");
	display(arr);
}


void checkpack(char arr[][9]) //Check to Create Packet Candy
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i][j + 1] && arr[i][j + 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = packetchar(arr[i][j]);
				arr[i + 2][j] = '0';
				arr[i + 1][j] = '0';
				arr[i][j + 1] = '0';
				arr[i][j + 2] = '0';


			}


			else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i][j + 1] && arr[i][j + 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = packetchar(arr[i][j]);
				arr[i - 2][j] = '0';
				arr[i - 1][j] = '0';
				arr[i][j + 1] = '0';
				arr[i][j + 2] = '0';


			}

			else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i][j - 1] && arr[i][j - 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = packetchar(arr[i][j]);
				arr[i - 2][j] = '0';
				arr[i - 1][j] = '0';
				arr[i][j - 1] = '0';
				arr[i][j - 2] = '0';

			}
			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i][j - 1] && arr[i][j - 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = packetchar(arr[i][j]);
				arr[i - 2][j] = '0';
				arr[i - 1][j] = '0';
				arr[i][j - 1] = '0';
				arr[i][j - 2] = '0';

			}

			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i][j + 1] && arr[i][j - 1])
			{
				scorer(arr[i][j]);
				arr[i][j] = packetchar(arr[i][j]);
				arr[i + 2][j] = '0';
				arr[i + 1][j] = '0';
				arr[i][j + 1] = '0';
				arr[i][j - 1] = '0';

			}

			else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i][j + 1] && arr[i][j - 1])
			{
				scorer(arr[i][j]);
				arr[i][j] = packetchar(arr[i][j]);
				arr[i - 2][j] = '0';
				arr[i - 1][j] = '0';
				arr[i][j + 1] = '0';
				arr[i][j - 1] = '0';

			}

			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j + 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = packetchar(arr[i][j]);
				arr[i - 1][j] = '0';
				arr[i + 1][j] = '0';
				arr[i][j + 1] = '0';
				arr[i][j + 2] = '0';

			}

			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1] && arr[i][j - 2])
			{
				scorer(arr[i][j]);
				arr[i][j] = packetchar(arr[i][j]);
				arr[i - 1][j] = '0';
				arr[i + 1][j] = '0';
				arr[i][j - 1] = '0';
				arr[i][j - 2] = '0';

			}

		}

	}



}

bool checker(char arr[][9])
{
	int i, j;
	bool flag = 0;

	for (i = 0; i < 9 && flag == 0; i++)
	{
		for (j = 0; j < 9 && flag == 0; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i - 1][j])
			{
				flag = 1;
			}


			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1])
			{
				flag = 1;
			}
		}
	}

	return flag;
}


void combcheck(char arr[][9])
{
	bool flag;
	do
	{
		flag = checker(arr);
		if (flag == 1)
		{
			check5(arr);
			check4(arr);
			check3(arr);
			newch(arr);
		}

	} while (flag == 1);
	system("clear");
	display(arr);
}


int main()
{
	system("clear");
	srand(time(0));
	const int RSIZE = 9, CSIZE = 9;
	char arr[RSIZE][CSIZE];

	cout << "----------WELCOME TO THE CANDY CRUSH GAME!----------\n\n";
	cout << "--------JUST FOLLOW THE INSTRUCTIONS GIVEN BELOW--------\n\n";
	cout << "1.  Enter 1 to START The Game\n";
	cout << "2.  Enter 2 to EXIT\n";
	cout << "3.  Enter 3 for CREDITS\n";
	cout << "4.  Enter 4 to Load The Last Game\n";

	cout << "ENTER  :  ";


	int input1, input2;
	cin >> input1;

	ifstream infile, inner;
	ofstream outfile, outer;
	if (input1 == 1)
	{
		startval1(arr);
	}
	else if (input1 == 4)
	{
		startval2(arr);
		input1 = 1;

	}

	if (input1 == 1)
	{
		system("clear");
		usleep(1500000);
		start3();
		usleep(1500000);
		system("clear");
		start2();
		usleep(1500000);
		system("clear");
		start();
		usleep(1500000);
		system("clear");
		start4();
		usleep(1500000);
		system("clear");






		system("clear");
		display(arr);
		do
		{

			swap(arr);
			check5(arr);
			checkpack(arr);
			check4(arr);
			check3(arr);
			newch(arr);
			combcheck(arr);

			cout << endl << endl << endl;
			cout << "Enter 0 to Exit the Game Without Saving\n";
			cout << "Enter 1 To Continue the Game\n";
			cout << "Enter 2 to Exit By Saving Game\n";

			cout << "\n\nEnter  :  ";
			cin >> input2;
			if (input2 == 2)
			{
				outfile.open("SAVE.txt");
				outer.open("MOVES.txt");
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						outfile << arr[i][j];
					}
				}
				outer << moves;
				outfile.close();
				outer.close();
			}
		} while (input2 == 1 && moves > 0);

		if (moves == 0)
		{
			system("clear");
			cout << "================ END OF THE GAME ================";
			cout << "\n\nYOUR SCORE IS  :  " << score;
		}
	}
	else if (input1 == 2)
	{
		system("clear");
		cout << "You ENTERD 2 \n\n---------------GAME ENDED---------------";
		return 0;
	}
	else if (input1 == 3)
	{
		system("clear");
		cout << "============ MEMBERS ============\n\n";
		cout << "Talha Bilal     \n\n\n";
		cout << "============ Roll no ============\n\n";
		cout << "  21F-9453          \n\n\n";
		cout << "============ PROJECT ============\n\n";
		cout << "     PF CANDY CRUSH PROJECT      \n\n\n";
		cout << "=========== FEATURES ===========\n\n";
		cout << "=> CONSOLE BASE CANDY CRUSH \n";
		cout << "=> SAVE/LOAD FEATURE AVAILABLE\n";
		cout << "=> ALSO HAVE SPECIAL CANDIES\n\n\n";
		cout << "====== THANKS FOR VISITING ======\n\n\n";
	}
	else
	{
		system("clear");
		cout << "You ENTERD INVALID NUMBER \n\n--------------GAME ENDED--------------";
		return 0;

	}


	cin.get();
	return 0;

}
