#include <iostream>
#include <cstdlib>
#include <fstream>
char board[10] = { '0','1','2','3','4','5','6','7','8','9' };
int p1score = 0, p2score = 0;
using namespace std;
fstream score;
void play_game();
void main_menu();
bool player_turn(int p)
{
    p = (p % 2) ? 1 : 2;
    if (p == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool bool_toss(int turn1)
{
    int toss = rand() % 2;
    if (toss == 1 && turn1 == 1)
    {
        return true;
    }
    else if (toss == 0 && turn1 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int winning_condition()
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int draw_condition()
{
    if (board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')
    {
        return 1;
    }
    else
    {
    	return 0;
    }

}
void credits()
{
    cout << "\nCredits:\n\nCreated by 21F-9122, 21F-9198, 21F-9068, 21F-9083\nSec: BSCS(4A) \n\n";
    main_menu();
}
void instructions()
{
    cout << "\nInstructions\n\nThere are one mode of game i.e Player vs Player\n";
    cout << "User will shift turns and one will have X other will have O\n";
    cout << "Vertical, Horizontal or diagonal match of same symbols will make the respective player win!\n";
    cout << "Note : Boxes contain numbers from 1-9. Select within them\n\n";
    main_menu();
}
void end()
{
    cout << "The user ended the program!";
}
void main_menu()
{
    cout << "Input \n1: To play game \n2: For Instructions \n3: For Credits \n4: To exit program\n";
    int c;
    cin >> c;
    while (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)
    {
        cout << "Error! Enter from 1-4 : ";
        cin >> c;
    }
    (c == 1) ? play_game() : (c == 2) ? instructions() : (c == 3) ? credits() : end();
}
void Displayboard()
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;
    cout << "     |     |     " << endl << endl;
}

int checkcontinuity()
{
    if (winning_condition() != 1 && draw_condition() != 1)
    {
        return -1;
    }
    else
    {
    	return 0;
    }
}
void play_game()
{
    cout << endl << "To Play Game : \n\n";
    int choice, box;
    cout << "\nYou selected Player vs Player mode \n";
    cout << "Player 1 (X)  -  Player 2 (O)\n" << endl;
    int player, turn, i;
    char mark;
    cout << "Enter 0/1 for player 1 toss :  ";
    cin >> turn;
    while (turn != 0 && turn != 1)
    {
        cout << "Error! Enter again 0/1";
        cin >> turn;
    }
    if (bool_toss(turn) == true)
    {
        player = 1;
        cout << "You won the toss!";
    }
    else
    {
        player = 2;
        cout << "Player 2 won the toss!";
    }
    do
    {
        Displayboard();
        if (player_turn(player) == true)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }
        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && board[1] == '1')
        { 
            board[1] = mark;
        }
        else if (choice == 2 && board[2] == '2')
        { 
            board[2] = mark;        
        }
        else if (choice == 3 && board[3] == '3')
        { 
            board[3] = mark;
        }
        else if (choice == 4 && board[4] == '4')
        { 
            board[4] = mark;
        }
        else if (choice == 5 && board[5] == '5')
        { 
            board[5] = mark;
        }
        else if (choice == 6 && board[6] == '6')
        { 
            board[6] = mark;
        }
        else if (choice == 7 && board[7] == '7')
        { 
            board[7] = mark;
        }
        else if (choice == 8 && board[8] == '8')
        { 
            board[8] = mark;
        }
        else if (choice == 9 && board[9] == '9')
        {
            board[9] = mark;
        }
        else
        {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        player++;
        system("clear");
    } while (checkcontinuity() == -1);
    Displayboard();
    if (winning_condition() == 1)
    {
        int p = --player;
        cout << "\n\t\t==>\aPlayer " << p << " win \n\n";
    }
    else if (draw_condition() == 1)
    {
        cout << "\t==>\aGame draw";
    }
    cin.ignore();
    cin.get();
}
int main()
{
	system("clear");
    cout << "\n\n\n\t\tTic Tac Toe\n\n\n\n";

    main_menu();
    cout << endl;
    return 0;
}
