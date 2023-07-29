#include<iostream>
#include<fstream>
#include<string>
//#include<conio.h>
#include <unistd.h>

using namespace std;


//--------------------------------------------------------------------Classes-------------------------------------------------------------------------------


								//-----------------------------------Trie trees ADT-------------------------------------

struct TrieNode
{
	TrieNode* links[26];
	bool flag = false;
	bool containKey(char);							//checks if the reference trie is present or not
	void put(char, TrieNode*);						//creating reference trie
	TrieNode* get(char);							//to get the next node for traversal
	void setEnd();									//setting flag to true at the end of the word
	bool isEnd();									//checking if the word is completed or not
};

class TrieTree
{
private:
	int sugg_Limit;
	int count;
	int present;
	string* strSuggessions;
public:
	TrieNode* root;
	TrieTree();
	void insert(string);									//Insertion in a trie tree
	void Sugg(TrieNode*, string);							//Recursive function to print suggessions
	void selectWord(string&);								//To select word from given suggessions
	void GiveSuggessions(TrieNode*, string);				//print suggestions for given string
};



//-----------------------------------Priority queue ADT-------------------------------------

struct PQ_node
{
	char data;
	int prior;
	PQ_node* next = NULL;
	PQ_node();
};

class P_Queue
{
private:
	PQ_node* head;
public:
	char queueArray[26];
	int priority[26];
	int queueSize;
	P_Queue();										//constructor
	bool IsEmpty();									//Check if queue is empty
	void Insert(char, int);							//inserting element in priority queue list
	void sort(char[], int[]);						//Applying bubble sort algorithim for sorting the queue arr
	void display();									//Function to display the values of Priority queue list
	void get(string, int);				//Function which gets a string,its size and sort by priority and insert in list
};



//-----------------------------------MinHeap ADT-------------------------------------

struct Mnode
{
	Mnode* left, * right;
	Mnode* next;
	char data;
	int prior;
	Mnode();
};

class MHeap
{
	Mnode* root;
	string* arr;
	int CharNum;
	int size;
public:
	fstream codes, org, encoded;
	MHeap();
	void Insert(P_Queue);										//to insert elements of priority queue in heap
	void Enqueue(Mnode*);
	Mnode* Dequeue();
	void sort();												//Sorting list
	Mnode* system();											//function to implement the process of making huffman tree
	void HuffMan();												//Making tree and decreasing the priority queue
	void Search(Mnode*, string, char, string&);					//Function used to find codes for a character
	void FindCode(string&, char);								//Function used to find codes of string alphaets using the above recursive function
	void AssignCodes(P_Queue, string);							//function to assign codes from file to array
	void read();												//Function to decode the text from the file
	void read2();
};



//----------------------------------------------------------------Implementation----------------------------------------------------------------------------


						//-----------------------------------Trie trees Implementation-------------------------------------


//checks if the reference trie is present or not
bool TrieNode::containKey(char ch)
{
	return (links[ch - 'a'] != NULL);
}


//creating reference trie
void TrieNode::put(char ch, TrieNode* node)
{
	links[ch - 'a'] = node;
}


//to get the next node for traversal
TrieNode* TrieNode::get(char ch)
{
	return links[ch - 'a'];
}


//setting flag to true at the end of the word
void TrieNode::setEnd()
{
	flag = true;
}


//checking if the word is completed or not
bool TrieNode::isEnd()
{
	return flag;
}


//Constructor of trie tree
TrieTree::TrieTree()
{
	sugg_Limit = 10;
	count = 0;
	present = 0;
	root = new TrieNode();
	strSuggessions = new string[sugg_Limit];
}


//Insert function to insert string in tree
void TrieTree::insert(string word)
{
	TrieNode* node = root;
	for (int i = 0; i < word.size(); i++)
	{
		if (!node->containKey(word[i]))				//If key is not present then we add the node
		{
			node->put(word[i], new TrieNode());		//IF that node is null then we create the node
		}
		node = node->get(word[i]);					//moves to reference trie
	}
	node->setEnd();									//This will return true
}


//Recursive function to print suggessions
void TrieTree::Sugg(TrieNode* root, string currword)
{
	if (count < sugg_Limit)
	{
		if (root->flag)								 // found a string in Trie with the given prefix
		{
			strSuggessions[count] = currword;
			count++;
			present++;
			cout << count << " : " << currword << endl;
		}
		for (int i = 0; i < 26; i++)
		{
			if (root->links[i])						// child node character value
			{
				char child = 'a' + i;
				Sugg(root->links[i], currword + child);
			}
		}
	}
}


//To select word from given suggessions
void TrieTree::selectWord(string& str)
{
	int x = 0;
	char pressed;
	if (x == present)
	{
		cout << "No suggessions present!\nPress 2 or press anything else except 1\n";
		return;
	}
	else
	{
		while (x < present)
		{
			system("clear");
			cout << "Enter / for moving to next word\nEnter ; to select the word\n\n";
			cout << "String --> " << str << endl << endl;
			for (int i = 0; i < present; ++i)
			{
				cout << i + 1 << " : " << strSuggessions[i] << endl;
			}
			cin >> pressed;
			while (pressed != '/' && pressed != ';')
			{
				cout << "Invalid key pressed\nEnter again : \n";
				cin >> pressed;
			}
			if (pressed == '/')
			{
				str = strSuggessions[x];
				x++;
			}
			else if (pressed == ';')
			{
				break;
			}
		}
	}
	if (x == present)						//If we proceeded to the last suggession then we will set out string to the last suggession
	{
		system("clear");
		cout << "Enter / for moving to next word\nEnter ; to select the word\n\n";
		cout << "String --> " << str << endl << endl;
		for (int i = 0; i < present; ++i)
		{
			cout << i + 1 << " : " << strSuggessions[i] << endl;
		}
		str = strSuggessions[present - 1];
	}
}


// print suggestions for given query prefix
void TrieTree::GiveSuggessions(TrieNode* root, string word)
{
	count = 0;
	present = 0;
	int n = 0;
	TrieNode* node = root;
	for (int i = 0; i < word.size(); ++i)
	{
		if (!node->containKey(word[i]))         //If key is not contain then we add the node
		{
			return;                           //If already key contain then this will return false
		}
		node = node->get(word[i]);              //moves to reference trie
	}
	Sugg(node, word);
}


//------------------------------------Huffman Implementation-------------------------------------


//Priority queue implementation


//Constructor of priority queue node
PQ_node::PQ_node()
{
	next = NULL;
}


//Constructor of priority queue
P_Queue::P_Queue()
{
	queueSize = 0;
	char a = 'a';
	for (int i = 0; i < 26; i++)
	{
		queueArray[i] = char(a + i);
		priority[i] = 0;
	}
}


//Check if queue is empty
bool P_Queue::IsEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//inserting element in priority queue list
void P_Queue::Insert(char ch, int num)
{
	PQ_node* curr = head;
	PQ_node* temp = new PQ_node;
	temp->data = ch;
	temp->prior = num;
	if (IsEmpty() == true)
	{
		head = temp;
	}
	else
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
	if (head->next != NULL)
	{
		curr = head;
		PQ_node* temp = curr->next;
		while (curr != NULL)
		{
			while (temp != NULL)
			{
				if ((curr->prior < temp->prior))			//Sorting the priority queue list by priority
				{
					PQ_node* tempNode = new PQ_node;
					tempNode->data = temp->data;
					tempNode->prior = temp->prior;

					temp->prior = curr->prior;
					temp->data = curr->data;

					curr->data = tempNode->data;
					curr->prior = tempNode->prior;
				}
				temp = temp->next;
			}
			temp = head;
			curr = curr->next;
		}
	}
}


//Applying bubble sort algorithim for sorting the queue arr
void P_Queue::sort(char queuArray[], int priority[])
{
	int temp;
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			if (priority[j - 1] < priority[j])
			{
				temp = priority[j - 1];						//sorting the priority arr
				priority[j - 1] = priority[j];
				priority[j] = temp;

				temp = queuArray[j - 1];					//sorting the queue arr by priority
				queuArray[j - 1] = queuArray[j];
				queuArray[j] = temp;
			}
		}
	}
}


//Function to display the values of Priority queue list
void P_Queue::display()
{
	PQ_node* curr = head;
	while (curr != NULL)
	{
		cout << curr->data << "(" << curr->prior << ")  ";
		curr = curr->next;
	}
	cout << endl;
}


//Main function which gets a string,its size and sort by priority and insert in list
void P_Queue::get(string str, int size)
{
	if (head != NULL)
	{
		head = NULL;
	}
	for (int i = 0; i < size; i++)				// loop till Size of string
	{
		for (int j = 0; j < 26; j++)			// loop for total alphabets
		{
			if (str[i] == queueArray[j])
			{
				priority[j]++;
			}
		}
	}
	sort(queueArray, priority);	//Sorting both arrays
	for (int i = 0; i < 26; i++)
	{
		if (priority[i] > 0)
		{
			queueSize++;
		}
	}
	for (int i = 0; i < queueSize; ++i)
	{
		Insert(queueArray[i], priority[i]);		//Inserting an element by giving char and priority
	}
}


//Minheap implementation


//Constructor of MinHeap node
Mnode::Mnode()
{
	left = right = NULL;
}


//Constructor of MinHeap
MHeap::MHeap()
{
	int CharNum = 0;
	int size = 0;
}


//to insert elements of priority queue in heap
void MHeap::Insert(P_Queue obj)
{
	if (root != NULL)
	{
		root = NULL;
	}
	arr = new string[obj.queueSize];
	size = obj.queueSize;
	CharNum = obj.queueSize;
	Mnode* curr = root;
	for (int i = 0; i < obj.queueSize; ++i)
	{
		Mnode* temp = new Mnode;
		temp->data = obj.queueArray[i];
		temp->prior = obj.priority[i];
		if (root == NULL)
		{

			root = temp;
			curr = root;
			curr->next = NULL;
		}
		else
		{

			temp->next = root;
			root = temp;
		}
	}
}


//Function to enqueue node
void MHeap::Enqueue(Mnode* obj)
{
	if (root == NULL)
	{
		root = obj;
	}
	else
	{
		Mnode* temp;
		temp = obj;
		temp->next = root;
		root = temp;
		size++;
	}
}


//Function to dequeue node
Mnode* MHeap::Dequeue()
{
	Mnode* del = root;
	Mnode* temp = new Mnode;
	temp->data = root->data;
	temp->prior = root->prior;
	temp->left = root->left;
	temp->right = root->right;
	root = root->next;
	size--;
	delete del;
	return temp;
}


//Sorting list
void MHeap::sort()
{
	Mnode* curr = root;
	Mnode* temp = curr->next;
	Mnode* currPrev = new Mnode;
	while (curr->next != NULL)
	{
		if (curr->prior > temp->prior)
		{
			if (curr == root)
			{
				Mnode* tempNode = new Mnode;

				tempNode->prior = curr->prior;
				tempNode->data = curr->data;
				tempNode->left = curr->left;
				tempNode->right = curr->right;

				tempNode->next = temp->next;
				root = temp;
				temp->next = tempNode;
			}
			else
			{
				Mnode* tempNode = new Mnode;

				tempNode->prior = curr->prior;
				tempNode->data = curr->data;
				tempNode->left = curr->left;
				tempNode->right = curr->right;

				tempNode->next = temp->next;
				currPrev->next = temp;
				temp->next = tempNode;
			}
		}
		currPrev = curr;
		curr = curr->next;
		temp = temp->next;
	}
}


//function to implement the process of making huffman tree
Mnode* MHeap::system()
{
	Mnode* Left, * Right;
	Left = Dequeue();
	Right = Dequeue();
	Mnode* treeNode = new Mnode;
	treeNode->left = Left;
	treeNode->right = Right;
	treeNode->prior = (Left->prior + Right->prior);
	treeNode->data = '-';
	return treeNode;
}


//Making tree and decreasing the priority queue
void MHeap::HuffMan()
{
	while (size != 1)
	{
		Enqueue(system());
		if (size == 0)
		{
			break;
		}
		sort();
	}
}


//Function used to find codes for a character
void MHeap::Search(Mnode* curr, string val, char ch, string& F)
{
	if (curr != NULL)
	{
		Search(curr->left, val + "0", ch, F);
		if (curr->left == NULL && curr->right == NULL)
		{
			if (curr->data == ch)
			{
				F = val;
			}
		}
		Search(curr->right, val + "1", ch, F);
	}
}


//Function used to find codes of string alphaets using the above recursive function
void MHeap::FindCode(string& s, char ch)
{
	Mnode* curr = root;
	Search(curr, "", ch, s);
}


//function to assign codes from file to array
void MHeap::AssignCodes(P_Queue obj, string str)
{
	codes.close();
	codes.open("Table_Codes.txt", ios::out);
	org.open("Original_Text.txt", ios::out);
	encoded.close();
	encoded.open("Encoded_Text.txt", ios::out);
	for (int i = 0; i < CharNum; ++i)			//Making all codes null at start
	{
		arr[i] = "";
	}
	for (int i = 0; i < CharNum; ++i)			//Finding codes and storing them in array
	{
		FindCode(arr[i], obj.queueArray[i]);
	}
	for (int i = 0; i < CharNum; ++i)
	{
		if (i == CharNum - 1)
		{
			codes << obj.queueArray[i] << " " << arr[i];
		}
		else
		{
			codes << obj.queueArray[i] << " " << arr[i] << endl;
		}

	}
	int size = str.size();
	for (int i = 0; i < size; ++i)
	{
		if (str[i] == ' ')
		{
			org << ' ';
			encoded << '-';
		}
		else
		{
			for (int j = 0; j < size; ++j)
			{
				if (str[i] == obj.queueArray[j])
				{
					org << str[i];
					encoded << arr[j];
				}
			}
		}
	}
	codes.close();
	org.close();
	encoded.close();
}


//Function to decode at start
void MHeap::read2()
{
	int count = 0, i = 0;
	int counter;
	string str;
	codes.close();
	codes.open("Table_Codes.txt", ios::in);
	while (!codes.eof())
	{
		getline(codes, str);
		count++;
	}
	codes.close();
	codes.open("Table_Codes.txt", ios::in);
	string code;
	char* chr = new char[count];
	string* strr = new string[count];
	while (!codes.eof())
	{
		codes >> chr[i];
		codes >> strr[i];
		i++;
	}
	codes.close();
	encoded.close();
	encoded.open("Encoded_Text.txt", ios::in);
	/*while (!encoded.eof())
	{
		string str2 = "";
		i = 0;
		encoded >> str;
		if (str[0] == '-')
		{
			i++;
			cout << " ";
			while (str[i] != '\0')
			{
				str2 += str[i];
				i++;
			}
			str = str2;
		}
		for (int i = 0; i < count; ++i)
		{
			if (strr[i] == str)
			{
				cout << chr[i];
				break;
			}
		}
	}*/
	i = 0;
	encoded >> str;
	counter = str.size();
	Mnode* curr = root;
	string temp, decoded = "";
	string strrr = "";
	while (i <= counter)
	{
		if (curr->left == NULL && curr->right == NULL)
		{
			for (int i = 0; i < count; ++i)
			{
				if (strr[i] == strrr)
				{
					decoded += chr[i];
					break;
				}
			}
			//temp = curr->data;
			//decoded += strrr;
			curr = root;
		}
		if (str[i] == '0')
		{
			curr = curr->left;
			strrr = strrr + "0";
		}
		else if (str[i] == '1')
		{
			curr = curr->right;
			strrr = strrr + "1";
		}
		else if (str[i] == '-')
		{
			decoded = decoded + " ";
		}
		i++;
	}
	cout << decoded;
}



//Function to decode the text from the file
void MHeap::read()
{
	int count = 0, i = 0;
	int counter;
	string str;
	codes.close();
	codes.open("Table_Codes.txt", ios::in);
	while (!codes.eof())
	{
		getline(codes, str);
		count++;
	}
	codes.close();
	codes.open("Table_Codes.txt", ios::in);
	string code;
	char* chr = new char[count];
	string* strr = new string[count];
	while (!codes.eof())
	{
		codes >> chr[i];
		codes >> strr[i];
		i++;
	}
	codes.close();
	encoded.close();
	encoded.open("Encoded_Text.txt", ios::in);
	/*while (!encoded.eof())
	{
		string str2 = "";
		i = 0;
		encoded >> str;
		if (str[0] == '-')
		{
			i++;
			cout << " ";
			while (str[i] != '\0')
			{
				str2 += str[i];
				i++;
			}
			str = str2;
		}
		for (int i = 0; i < count; ++i)
		{
			if (strr[i] == str)
			{
				cout << chr[i];
				break;
			}
		}
	}*/
	i = 0;
	encoded >> str;
	counter = str.size();
	Mnode* curr = root;
	string temp, decoded = "";
	while (i <= counter)
	{
		if (curr->left == NULL && curr->right == NULL)
		{
			temp = curr->data;
			decoded += temp;
			curr = root;
		}
		if (str[i] == '0')
		{
			curr = curr->left;
		}
		else if (str[i] == '1')
		{
			curr = curr->right;
		}
		else if (str[i] == '-')
		{
			decoded = decoded + " ";
		}
		i++;
	}
	cout << decoded;
}


//Function to get the string from the file
void getstr(string& str)
{
	MHeap obj;
	string temp;
	obj.org.close();
	obj.org.open("Original_Text.txt", ios::in);
	if (!obj.org)
	{
		cout << "File not found!\n";
	}
	else
	{
		obj.org >> temp;
		str = str + temp;
		while (!obj.org.eof())
		{
			str = str + " ";
			obj.org >> temp;
			str = str + temp;
		}
	}
}


//Function to display the encoded test in the file
void DisplayEncoded()
{
	string str, temp;
	MHeap obj;
	obj.encoded.close();
	obj.encoded.open("Encoded_Text.txt", ios::in);
	if (!obj.encoded)
	{
		cout << "File not found!\n";
	}
	else
	{
		while (!obj.encoded.eof())
		{
			obj.encoded >> temp;
			str += temp;
		}
	}
	cout << str << endl;
}



//------------------------------------------------------------------Start & Process------------------------------------------------------------------------



//Main Function for text editor
void process()
{
	TrieTree obj;
	MHeap Mobj;
	P_Queue Pobj;
	string R, str1, search, str = "", str2, choice;
	string Final = "";
	int h = 0;
	ifstream wordsfile;
	wordsfile.open("outfile.txt");
	while (!wordsfile.eof())
	{
		int TT = 1;
		int s;
		wordsfile >> R;
		s = R.size();
		for (int i = 0; i < s; ++i)
		{
			if (R[i] < 'a' || R[i]>'z')
			{
				TT = 0;
			}
		}
		if (TT == 1)
		{
			obj.insert(R);
		}
		h++;
	}
	wordsfile.close();
	cout << "Enter 1 if you want to decode the last text\n";
	cin >> choice;
	char c;
	if (choice == "1")
	{
		Mobj.encoded.open("Encoded_Text.txt", ios::in);
		if (Mobj.encoded)
		{
			Mobj.encoded >> c;
			if (Mobj.encoded.eof())
			{
				cout << "File is empty\nPress anything to continue";
				cin.get();
			}
			else
			{
				getstr(Final);
				int S = Final.length();
				Pobj.get(Final, S);
				Mobj.Insert(Pobj);
				Mobj.HuffMan();
				cout << "Encoded text is : ";
				DisplayEncoded();
				cout << "Decoded text : ";
				Mobj.read();
				cout << endl << "Press anything to continue";
				cin.get();
				system("clear");
			}
		}
		else
		{
			cout << "File not opened\nPress anything to continue";
			cin.get();
		}
	}
	else
	{
		cout << "Press anything to continue";
		cin.get();
	}
	Final = "";
	system("clear");
	cout << "Enter First Letter of string : " << str;
	cin >> str2;
	while ((str2.size() > 1) || (str2[0] < 'a' || str2[0]>'z'))
	{
		if (str2.size() > 1)
		{
			cout << "Enter a character not a string\n";
		}
		if (str2[0] < 'a' || str2[0]>'z')
		{
			cout << "Enter only from a-z";
		}
		cin >> str2;
	}
	str = str + str2;
	obj.GiveSuggessions(obj.root, str);
	do
	{
		cout << "---> Press 1 if you want to select from these suggessions\n---> Press 2 to add more characters\n---> Press any key to complete the word\n";
		cin >> choice;
		if (choice == "1")
		{
			obj.selectWord(str);
			cout << "\nEntered string is : " << str << endl;
		}
		else if (choice == "2")
		{
			system("clear");
			cout << "Enter string : " << Final + str;
			cin >> str2;
			while ((str2.size() > 1) || (str2[0] < 'a' || str2[0]>'z'))
			{
				if (str2.size() > 1)
				{
					cout << "Enter a character not a string\n";
				}
				if (str2[0] < 'a' || str2[0]>'z')
				{
					cout << "Enter only from a-z";
				}
				cin >> str2;
			}
			str += str2;
			obj.GiveSuggessions(obj.root, str);
		}
		else
		{
			cout << "\nEntered string is : " << str << endl;
			cout << "Enter = to complete string\nEnter 1 to Add another word\n\n";
			cin >> choice;
			while (choice != "=" && choice != "1")
			{
				cout << "Invalid key pressed\nEnter again : \n";
				cin >> choice;
			}
			if (choice == "=")
			{
				cout << "String completed\n";
				Final += str;
				break;
			}
			else
			{
				Final += str + " ";
				str = "";
				system("clear");
				cout << "Enter string : " << Final;
				cin >> str2;
				while (str2 < "a" || str2 > "z")
				{
					cout << "Enter from alphabet a to z\n";
					cin >> str2;
				}
				while (str2.size() > 1)
				{
					cout << "Enter a character not a string\n";
					cin >> str2;
					while (str2 < "a" || str2 > "z")
					{
						cout << "Enter from alphabet a to z\n";
						cin >> str2;
					}
				}
				str += str2;
				obj.GiveSuggessions(obj.root, str);
			}
		}
	} while (choice == "1" || choice == "2");
	cout << "\nEntered string is : " << Final << "\nPress anything to continue";
	cin.get();
	system("clear");
	int S = Final.length();
	cout << "Entered string is : " << Final << endl << "Now encoding this into file : \n";
	Pobj.get(Final, S);
	Mobj.Insert(Pobj);
	Mobj.HuffMan();
	Mobj.AssignCodes(Pobj, Final);
	cout << "Encoded Text : ";
	DisplayEncoded();
	cout << "Enter 1 if you want to decode : \n";
	cin >> choice;
	if (choice == "1")
	{
		Mobj.read();
		cout << endl;
	}
}


//Function for introductory display
void start()
{
	char arr1[19][50] =
	{
		{ ' ' ,' ' ,' ' , '*' ,'*','*','*','*',' ','*','*','*',' ','*',' ','*',' ','*', '*','*', '*','*',' ',' ','*','*','*',' ','*','*',' ',' ','*','*','*',' ','*' ,'*','*','*','*',' ',' ','*',' ',' ','*','*',' ',' '}
		,{ ' ' ,' ' ,' ' ,'*' ,'*','*','*','*',' ','*','*','*',' ','*',' ','*',' ','*', '*','*', '*','*',' ',' ','*','*','*',' ','*','*','-',' ','*','*','*',' ','*' ,'*','*','*','*',' ','_','*','-',' ','*','*','-',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ' ,' ','*',' ',' ',' ',' ', '*',' ',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ' ,' ','*',' ',' ',' ','*',' ','*',' ','*',' ','*',' ' }
		,{ ' ' ,' ' ,' ' ,' ' ,' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ' ,' ','*',' ',' ',' ',' ', '*',' ',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ' ,' ','*',' ',' ',' ','*',' ','*',' ','*',' ','*',' ' }
		,{ ' ' ,' ' ,' ' ,' ' ,' ','*',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ',' ' ,' ','*',' ',' ',' ',' ', '*','*',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ' ,' ','*',' ',' ',' ','*',' ','*',' ','*','*','-',' ' }
		,{ ' ' ,' ' ,' ' ,' ' ,' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ' ,' ','*',' ',' ',' ',' ', '*',' ',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ' ,' ','*',' ',' ',' ','*',' ','*',' ','*',' ','*',' ' }
		,{ ' ' ,' ' ,' ' ,' ' ,' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ' ,' ','*',' ',' ',' ',' ', '*',' ',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ' ,' ','*',' ',' ',' ','*',' ','*',' ','*',' ','*',' ' }
		,{ ' ' ,' ' ,' ' ,' ' ,' ','*',' ',' ',' ','*','*','*',' ','*',' ','*',' ',' ' ,' ','*',' ',' ',' ',' ', '*','*','*',' ','*','*','-',' ','*','*','*',' ',' ' ,' ','*',' ',' ',' ','_','*','-',' ','*',' ','*',' ' }
		,{ ' ' ,' ' ,' ' ,' ' ,' ','*',' ',' ',' ','*','*','*',' ','*',' ','*',' ',' ' ,' ','*',' ',' ',' ',' ', '*','*','*',' ','*','*',' ',' ','*','*','*',' ',' ' ,' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*',' ' }
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' }
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*','*','-',' ','*','*', ' ',' ',' ' ,'*',' ',' ','_','*','*','*',' ', '*','*','*',' ','_','*','-',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ','*', '*', '-',' ','_' ,'*','-',' ','_','*','*','*',' ', '*','*','*',' ','*','*','*',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ', '*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ', '*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*','*','-',' ','*','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ', '*','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ', '*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ', '*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ','_','*','-',' ','*','*','*',' ',' ', '*','*','*',' ','*','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
		,{ ' ' ,' ' ,' ' ,' ' ,' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ','*',' ',' ','_','*','-',' ',' ', '*','*','*',' ','_','*','-',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
	};
	system("clear");
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\tLOADING\n\t\t\t\t\t";
	for (int i = 0; i < 36; i++)
	{
		usleep(90000);
		cout.flush();
		cout << '.';
	}
	usleep(2000000);
	system("clear");
	cout << endl;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (arr1[i][j] == '*')
			{
				cout << '*' << '*';
			}
			else if (arr1[i][j] == '_')
			{
				cout << " " << '*';
			}
			else if (arr1[i][j] == '-')
			{
				cout << '*' << " ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout.flush();
		usleep(90000);
		cout << endl;
	}
	cout << "\n\t\t\t\t\tPress something to continue";
	cin.get();
}



//------------------------------------------------------------------Main-------------------------------------------------------------------------



//Main / Driver program
int main()
{
	start();					//Introductory Display
	system("clear");
	process();					//Text Editor function
	cout << "Press anything to continue";
	cin.get();
}


