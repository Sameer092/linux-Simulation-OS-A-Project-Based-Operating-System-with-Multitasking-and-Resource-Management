#include<iostream>
#include<fstream>
#include<unistd.h>
#include<string>

using namespace std;

void Main_Menu();

struct Book
{
	string Title;
	string Author;
	int ISBN;
	int AvailableCopies;
	void GetData()
	{
		cin.ignore();
		cout << "Enter Name of Book : ";
		getline(cin, Title);
		cout << "Enter Name of Author : ";
		getline(cin, Author);
		cout << "Enter ISBN number : ";
		cin >> ISBN;
		cout << "Enter Number of copies Available : ";
		cin >> AvailableCopies;
	}
};

struct node
{
	Book data;
	node* next;
	node()
	{
		next = NULL;
	}
};


class LibraryManagement
{
	node* BookHead;
	fstream fileIn;
public:
	LibraryManagement();
	void InsertBook(Book);
	void Read();
	void UpdateBook();
	void DeleteBook();
};


LibraryManagement::LibraryManagement()
{
	fileIn.open("Books.txt");
	if (fileIn.is_open())
	{
		if (!fileIn.eof())
		{
			node* curr = BookHead;
			while (!fileIn.eof())
			{
				node* temp = new node;
				fileIn >> temp->data.ISBN;
				fileIn.ignore();
				getline(fileIn, temp->data.Title);
				getline(fileIn, temp->data.Author);
				fileIn >> temp->data.AvailableCopies;
				if (temp->data.ISBN > 0)
				{
					if (BookHead == NULL)
					{
						curr = BookHead = temp;
					}
					else
					{
						curr->next = temp;
						curr = curr->next;
					}
				}
			}
		}
	}
	fileIn.close();
}


void LibraryManagement::InsertBook(Book obj)
{
	fileIn.open("Books.txt", ios::app);
	fileIn << endl << endl << obj.ISBN << endl;
	fileIn << obj.Title << endl;
	fileIn << obj.Author << endl;
	fileIn << obj.AvailableCopies;
	fileIn.close();
	node* temp = new node;
	temp->data.ISBN = obj.ISBN;
	temp->data.Title = obj.Title;
	temp->data.Author = obj.Author;
	temp->data.AvailableCopies = obj.AvailableCopies;
	node* curr = BookHead;
	if (curr == NULL)
	{
		curr = BookHead = temp;
	}
	else
	{
		if (BookHead->next != NULL)
		{
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
		}
		curr->next = temp;
	}
	cout << "Note : Data is written in file in following format\nISBN\nTitle\nAuthor\nAvailable copies\n";
}


void LibraryManagement::Read()
{
	int choice;
	cout << "Enter 1 to view all data\nEnter 2 to view specific data\n";
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Invalid Input!Enter again\n";
		cin >> choice;
	}
	if (choice == 1)
	{
		cout << "\nDisplaying data of books : \n\n";
		int c = 1;
		node* curr = BookHead;
		while (curr != NULL)
		{
			cout << "Book : " << c << endl << endl;
			cout << "ISBN : " << curr->data.ISBN;
			cout << "\nTitle : " << curr->data.Title;
			cout << "\nAuthor : " << curr->data.Author;
			cout << "\nAvailable Copies : " << curr->data.AvailableCopies << endl << endl;
			curr = curr->next;
			c++;
		}
	}
	else if (choice == 2)
	{
		int num;
		cout << "Enter ISBN number of book : \n";
		cin >> num;
		node* curr = BookHead;
		while (curr != NULL)
		{
			if (num == curr->data.ISBN)
			{
				cout << "\nDisplaying book data : \n";
				cout << "\nISBN : " << curr->data.ISBN;
				cout << "\nTitle : " << curr->data.Title;
				cout << "\nAuthor : " << curr->data.Author;
				cout << "\nAvailable Copies : " << curr->data.AvailableCopies << endl;
				break;
			}
			curr = curr->next;
			if (curr == NULL)
			{
				cout << "Book not found!\n";
			}
		}
	}
}


void LibraryManagement::UpdateBook()
{
	int num;
	cout << "Enter ISBN number of book : \n";
	cin >> num;
	node* temp = BookHead;
	while (temp != NULL)
	{
		if (num == temp->data.ISBN)
		{
			cout << "\nDisplaying book data : \n";
			cout << "\nISBN : " << temp->data.ISBN;
			cout << "\nTitle : " << temp->data.Title;
			cout << "\nAuthor : " << temp->data.Author;
			cout << "\nAvailable Copies : " << temp->data.AvailableCopies << endl;
			int choice;
			cout << "Enter 1 to Update ISBN\nEnter 2 to Update Book Title\nEnter 3 to Update Author\nEnter 4 to Update Number of copies available\n";
			cin >> choice;
			while (choice > 4 || choice < 1)
			{
				cout << "Invalid Input!\nEnter again : ";
				cin >> choice;
			}
			if (choice == 1)
			{
				cout << "Enter new ISBN : ";
				cin >> temp->data.ISBN;
			}
			else if (choice == 2)
			{
				cout << "Enter new Title : ";
				cin >> temp->data.Title;
			}
			else if (choice == 3)
			{
				cout << "Enter new Author : ";
				cin >> temp->data.Author;
			}
			else if (choice == 4)
			{
				cout << "Enter new Number of Copies Available : ";
				cin >> temp->data.AvailableCopies;
			}
			fileIn.open("Books.txt", ios::out);
			node* curr = BookHead;
			while (curr != NULL)
			{
				fileIn << endl << endl << curr->data.ISBN << endl;
				fileIn << curr->data.Title << endl;
				fileIn << curr->data.Author << endl;
				fileIn << curr->data.AvailableCopies;
				curr = curr->next;
			}
			fileIn.close();
			break;
		}
		temp = temp->next;
		if (temp == NULL)
		{
			cout << "Book not found!\n";
		}
	}
}


void LibraryManagement::DeleteBook()
{
	int num;
	cout << "Enter ISBN number of book : \n";
	cin >> num;
	node* temp = BookHead;
	while (temp != NULL)
	{
		if (num == temp->data.ISBN)
		{
			if (temp == BookHead)
			{
				BookHead = BookHead->next;
				delete temp;
			}
			else if (temp->next == NULL)
			{
				node* temp2 = temp;
				temp = BookHead;
				while (temp->next != temp2)
				{
					temp = temp->next;
				}
				temp->next = NULL;
				delete temp2;
			}
			else
			{
				node* temp2 = temp;
				temp = BookHead;
				while (temp->next != temp2)
				{
					temp = temp->next;
				}
				temp->next = temp2->next;
				temp2->next = NULL;
				delete temp2;
			}
			fileIn.open("Books.txt", ios::out);
			node* curr = BookHead;
			while (curr != NULL)
			{
				fileIn << endl << endl << curr->data.ISBN << endl;
				fileIn << curr->data.Title << endl;
				fileIn << curr->data.Author << endl;
				fileIn << curr->data.AvailableCopies;
				curr = curr->next;
			}
			fileIn.close();
			break;
		}
		temp = temp->next;
		if (temp == NULL)
		{
			cout << "Book not found!\n";
		}
	}
}


int main()
{
	Main_Menu();
	usleep(3000000);
	cout<< endl ;
}


void Main_Menu()
{
	cout << "\n\n\t------------------------------------LIBRARY MANAGEMENT SYSTEM------------------------------------\n\n";
	int choice;
	LibraryManagement obj;
	Book bobj;
	cout << "\nEnter 1 to Insert data\nEnter 2 to Read data\nEnter 3 to Update data\nEnter 4 to Delete data\nPress anyother to Terminate\n";
	cin >> choice;
	while (choice < 5 && choice >0)
	{
		if (choice == 1)
		{
			bobj.GetData();
			obj.InsertBook(bobj);
			usleep(4000000);
			cout<< endl ;
			system("clear");
		}
		else if (choice == 2)
		{
			obj.Read();
			usleep(4000000);
			cout<< endl ;
			system("clear");
		}
		else if (choice == 3)
		{
			obj.UpdateBook();
			usleep(4000000);
			cout<< endl ;
			system("clear");
		}
		else if (choice == 4)
		{
			obj.DeleteBook();
			usleep(4000000);
			cout<< endl ;
			system("clear");
		}
		cout << "\nEnter 1 to Insert data\nEnter 2 to Read data\nEnter 3 to Update data\nEnter 4 to Delete data\nPress anyother to Terminate\n";
		cin >> choice;
	}
}

