#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/wait.h>
using namespace std;
static float RAM;
float Process[15] = { 0.5,0.6,0.2,0.3,0.4,0.2,0.3,0.3,0.3,0.3,0.3,0.5,0.7,0.3,0.6};
void MainMenu();
void* TicTacToe(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o TTT TicTacToe.cpp && ./TTT; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* TxtEditor(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o TE TXT_editor.cpp && ./TE; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* Calculator(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o Calc Calculator.cpp && ./Calc; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* PlayMusic(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o PM PlayMusic.cpp && ./PM; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* PlayVideo(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o PV PlayVideo.cpp && ./PV; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* OpenBrowser(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o OB OpenBrowser.cpp && ./OB; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* Clock(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o Cl Clock.cpp && ./Cl; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* Createfile(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o CrF CreateFile.cpp && ./CrF; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* Openfile(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o OF OpenFile.cpp && ./OF; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* Deletefile(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o DF DeleteFile.cpp && ./DF; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* Copyfile(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o CpF CopyFile.cpp && ./CpF; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* BattleShip(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o BS BattleShip.cpp && ./BS; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* CandyCrush(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o CC candycrush.cpp && ./CC; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* Calendar(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o Cald Calendar.cpp && ./Cald; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* LibrarySystem(void* arg)
{
	string cmd;
	cmd = "gnome-terminal -- /bin/bash -c 'g++ -o LS LibSystem.cpp && ./LS; exec bash'";
	system(cmd.c_str());
	return NULL;
}
void* Kernel(void* arg)
{
	system("clear");
	string choice;
	string id;
	cout << "\n\n\t\tKernel Mode\n\n";
	do
	{
		system("pgrep -f gnome-terminal | xargs -I {} sh -c 'test \"$(readlink \"/proc/{}/cwd\")\" = \"$(pwd)\" && echo {}'");
		cout << "Enter an ID to end that process : ";
		cin >> id;
		string str = "kill " + id;
		system(str.c_str());
		cout << "Select from choices below\n1 if you want to delete more processes\n2 for going to MainMenu\nany other for exit and kill all the remaining processes\nEnter choice : ";
		cin >> choice;
	} while (choice == "1");
	if (choice == "2")
	{
		MainMenu();
	}
	else
	{
		system("pkill - f \"$(pwd)\"");
	}
	return NULL;
}
void MainMenu()
{
	cout << "\t\t********************\n";
	cout << "\t\t**** MAIN MENU *****\n";
	cout << "\t\t********************\n\n";
	string cmd, choice;
	pthread_t th[15];
	do
	{
		system("clear");
		cout << "Available RAM : " << RAM << endl << endl;
		cout << "Select your choice number from below options\n\n";
		cout << "1  : Tic Tac Toe\n";
		cout << "2  : Text Editor\n";
		cout << "3  : Calculator\n";
		cout << "4  : Play Music\n";
		cout << "5  : Play video\n";
		cout << "6  : Open a web browser\n";
		cout << "7  : Clock\n";
		cout << "8  : Create a file\n";
		cout << "9  : Open a file\n";
		cout << "10 : Delete a file\n";
		cout << "11 : Copy a file\n";
		cout << "12 : BattleShip\n";
		cout << "13 : Candy Crush\n";
		cout << "14 : Calendar\n";
		cout << "15 : Library Management\n";
		cout << "16 : Kernel Mode\n";
		cout << "17 : Scheduling Mode\n";
		cout << "AnyOther For Exit\n";
		cout << "\n\nEnter choice : ";
		cin >> choice;
		if (choice == "1")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[0])
				{
					pthread_create(&th[0], NULL, TicTacToe, NULL);
					pthread_join(th[0], NULL);
					RAM = RAM - Process[0];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "2")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[1])
				{
					pthread_create(&th[1], NULL, TxtEditor, NULL);
					pthread_join(th[1], NULL);
					RAM = RAM - Process[1];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "3")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[2])
				{
					pthread_create(&th[2], NULL, Calculator, NULL);
					pthread_join(th[2], NULL);
					RAM = RAM - Process[2];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "4")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[3])
				{
					pthread_create(&th[3], NULL, PlayMusic, NULL);
					pthread_join(th[3], NULL);
					RAM = RAM - Process[3];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "5")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[4])
				{
					pthread_create(&th[4], NULL, PlayVideo, NULL);
					pthread_join(th[4], NULL);
					RAM = RAM - Process[4];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "6")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[5])
				{
					pthread_create(&th[5], NULL, OpenBrowser, NULL);
					pthread_join(th[5], NULL);
					RAM = RAM - Process[5];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "7")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[6])
				{
					pthread_create(&th[6], NULL, Clock, NULL);
					pthread_join(th[6], NULL);
					RAM = RAM - Process[6];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "8")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[7])
				{
					pthread_create(&th[7], NULL, Createfile, NULL);
					pthread_join(th[7], NULL);
					RAM = RAM - Process[7];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "9")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[8])
				{
					pthread_create(&th[8], NULL, Openfile, NULL);
					pthread_join(th[8], NULL);
					RAM = RAM - Process[8];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "10")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[9])
				{
					pthread_create(&th[9], NULL, Deletefile, NULL);
					pthread_join(th[9], NULL);
					RAM = RAM - Process[9];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "11")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[10])
				{
					pthread_create(&th[10], NULL, Copyfile, NULL);
					pthread_join(th[10], NULL);
					RAM = RAM - Process[10];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "12")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[11])
				{
					pthread_create(&th[11], NULL, BattleShip, NULL);
					pthread_join(th[11], NULL);
					RAM = RAM - Process[11];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "13")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[12])
				{
					pthread_create(&th[12], NULL, CandyCrush, NULL);
					pthread_join(th[12], NULL);
					RAM = RAM - Process[12];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "14")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[13])
				{
					pthread_create(&th[13], NULL, Calendar, NULL);
					pthread_join(th[13], NULL);
					RAM = RAM - Process[13];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "15")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				if (RAM > Process[14])
				{
					pthread_create(&th[14], NULL, LibrarySystem, NULL);
					pthread_join(th[14], NULL);
					RAM = RAM - Process[14];
					exit(0);
				}
				else
				{
					cout << "\nNot Enough RAM!!\n";
				}
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "16")
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				pthread_create(&th[15], NULL, Kernel, NULL);
				pthread_join(th[15], NULL);
			}
			else if (pid > 0)
			{
				wait(NULL);
			}
		}
		else if (choice == "17")
		{

		}
		else
		{
			cout << "Exiting Program...\n";
			usleep(3000000);
			break;
		}
	} while (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" || choice == "6" || choice == "7" || choice == "8" || choice == "9" || choice == "10" || choice == "11" || choice == "12" || choice == "13" || choice == "14" || choice == "15" || choice == "16" || choice == "17");
}

void* Intro(void* args)
{
	system("clear");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\t\t\t**    *****    *****      *      *****              **      ****    **\n";
	cout << "\t\t\t**    *    *   *         * *     *    *           *    *   **       **\n";
	cout << "\t\t\t**    *     *  ****     *   *    *     *  -----  *      *   ***     **\n";
	cout << "\t\t\t**    *    *   *       *******   *    *           *    *      **    **\n";
	cout << "\t\t\t**    *****    *****  *       *  *****              **     ****     **\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\t\t\t**********************************************************************\n";
	usleep(2000000);      //2000000 microseconds = 2 seconds
	cout << "\n\n\n\n\n\t\t\t\t\t\t\tLOADING\n\t\t\t\t\t";
	for (int i = 0; i < 36; i++)
	{
		cout << '.';
		cout.flush();
		usleep(90000);
	}
	usleep(2000000);
	system("clear");
	cout << "\n\n\n";
	cout << "\t***********************************************\n";
	cout << "\t******      Project Group Members :      ******\n";
	cout << "\t***********************************************\n";
	cout << "\n\n\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\t\t\t******          21F-9122   --   Muhammad Affan Bukhari          ******\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\t\t\t******          21F-9083   --   Muhammad Sameer                 ******\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\t\t\t******          21F-9068   --   Ibraheem Noor                   ******\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\t\t\t******          21F-9198   --   Sadeed Amir                     ******\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\n\n\n\t\t\t\t\t    Press any key to continue";
	cin.get();
	system("clear");
	return 0;
}

int main()
{
	pthread_t T;
	pthread_create(&T, NULL, &Intro, NULL);
	pthread_join(T, NULL);
	cout << "\n\n\tEnter the Ram you want to allocate to your Operating System\n";
	cin >> RAM;
	char choice;
	cout << "Press 1 for MainMenu\nAny Else for exit" << endl;
	cin >> choice;
	if (choice == '1')
	{
		system("clear");
		cout << endl << endl;
		MainMenu();
	}
	pthread_exit(NULL);
	return 0;
}
