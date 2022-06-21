//CS112 CS OOP FINAL PROJECT
//Syed Mohammad Hadi Ul Hassan 2020475
//Muhammad Abdullah Farooq 2020022
//Sheikh Daniyal Naveed 2020459

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

class CBook
{
private:
	int ID, price, pages;
	string BookName, author, ISBN, IssuedOn, IssuedBy, ReturnDate;

public:
	CBook(int ID = 0, int price = 0, int pages = 0, string BookName = "\0", string author = "\0", string ISBN = "\0", string IssuedOn = "\0", string IssuedBy = "\0", string ReturnDate = "\0")
	{
		this->ID = ID;
		this->price = price;
		this->pages = pages;
		this->BookName = BookName;
		this->author = author;
		this->ISBN = ISBN;
		this->IssuedOn = IssuedOn;
		this->IssuedBy = IssuedBy;
		this->ReturnDate = ReturnDate;
	}

	void set_ID(int ID)
	{
		this->ID = ID;
	}
	void set_price(int price)
	{
		this->price = price;
	}
	void set_pages(int pages)
	{
		this->pages = pages;
	}
	void set_BookName(string BookName)
	{
		this->BookName = BookName;
	}
	void set_author(string author)
	{
		this->author = author;
	}
	void set_ISBN(string ISBN)
	{
		this->ISBN = ISBN;
	}
	void set_IssuedOn(string IssuedOn)
	{
		this->IssuedOn = IssuedOn;
	}
	void set_IssuedBy(string IssuedBy)
	{
		this->IssuedBy = IssuedBy;
	}
	void set_ReturnDate(string ReturnDate)
	{
		this->ReturnDate = ReturnDate;
	}
	int get_ID()
	{
		return ID;
	}
	int get_price()
	{
		return price;
	}
	int get_pages()
	{
		return pages;
	}
	string get_IssuedBy()
	{
		return IssuedBy;
	}
	string get_BookName()
	{
		return BookName;
	}
	string get_author()
	{
		return author;
	}
	string get_ISBN()
	{
		return ISBN;
	}
	string get_IssuedOn()
	{
		return IssuedOn;
	}
	string get_ReturnDate()
	{
		return ReturnDate;
	}
	CBook getBook()
	{
		return *this;
	}

	void PrintBookDetails()
	{

		cout << endl
			 << endl;
		cout << "The ID of the book is : " << ID << endl
			 << "The Book Name is : " << BookName << endl
			 << "The Author Name is : " << author << endl
			 << "The ISBN of Book is : " << ISBN << endl
			 << "The Price of Book is : " << price << endl
			 << "Total pages in the book are : " << pages << endl
			 << "The Book is Issue Date is : " << IssuedOn << endl
			 << "The Book is Issued by : " << IssuedBy << endl
			 << "The return Date is : " << ReturnDate << endl;
	}

	~CBook()
	{
	}

	CBook(CBook &CB)
	{

		ID = CB.ID;
		price = CB.price;
		pages = CB.pages;
		BookName = CB.BookName;
		author = CB.author;
		ISBN = CB.ISBN;
		IssuedOn = CB.IssuedOn;
		IssuedBy = CB.IssuedBy;
		ReturnDate = CB.ReturnDate;
	}
};

struct bookList
{

	CBook obj;
	bookList *next;
};

class CBookList
{
private:
	CBook books;
	bookList *HeadPtr;

public:
	bookList *getBookHead()
	{
		return HeadPtr;
	}

	CBookList(int ID = 0, int price = 0, int pages = 0, string BookName = "\0", string author = "\0", string ISBN = "\0", string IssuedOn = "\0", string IssuedBy = "\0", string ReturnDate = "\0")
	{

		books.set_ID(ID);
		books.set_price(price);
		books.set_pages(pages);
		books.set_BookName(BookName);
		books.set_author(author);
		books.set_ISBN(ISBN);
		books.set_IssuedOn(IssuedOn);
		books.set_IssuedBy(IssuedBy);
		books.set_ReturnDate(ReturnDate);
		HeadPtr = NULL;
	}

	void printBookList()
	{

		bookList *print = HeadPtr;

		while (print != NULL)
		{

			print->obj.PrintBookDetails();
			print = print->next;
		}
		char a;
		cout << "\nEnter any key to continue: ";
		cin >> a;
	}

	~CBookList(){};

	void Addbook()
	{

		bookList *ptrNew = new bookList;
		bookList *ptrTemp = HeadPtr;

		int ID;
		int price;
		int pages;

		string IssuedBy;
		string IssuedOn;
		string BookName;
		string author;
		string ISBN;
		string ReturnDate;

		cout << "\nEnter New Book Details\n";
		cout << "Enter book ID : ";
		cin >> ID;
		ptrNew->obj.set_ID(ID);
		cout << "Enter book Price : ";
		cin >> price;
		ptrNew->obj.set_price(price);
		cout << "Enter book pages : ";
		cin >> pages;
		ptrNew->obj.set_pages(pages);
		cout << "The Book is issued by : ";
		cin >> IssuedBy;
		ptrNew->obj.set_IssuedBy(IssuedBy);
		cout << "The Book is issued on : ";
		cin >> IssuedOn;
		ptrNew->obj.set_IssuedOn(IssuedOn);
		cout << "Enter book Name: ";
		cin >> BookName;
		ptrNew->obj.set_BookName(BookName);
		cout << "Enter author's name' : ";
		cin >> author;
		ptrNew->obj.set_author(author);
		cout << "Enter ISBN : ";
		cin >> ISBN;
		ptrNew->obj.set_ISBN(ISBN);
		cout << "Enter Return Date : ";
		cin >> ReturnDate;
		ptrNew->obj.set_ReturnDate(ReturnDate);

		ptrNew->next = NULL;
		if (HeadPtr == NULL)
		{
			HeadPtr = ptrNew;
			return;
		}
		while (ptrTemp->next != NULL)
		{

			ptrTemp = ptrTemp->next;
		}
		ptrTemp->next = ptrNew;
	}

	void DeleteBook()
	{

		int ID;

		cout << "\nEnter Book ID: ";
		cin >> ID;

		bookList *ptrCurrent = HeadPtr;
		bookList *ptrPrevious = HeadPtr;

		while (ptrCurrent != NULL && ptrCurrent->obj.get_ID() != ID)
		{
			ptrPrevious = ptrCurrent;
			ptrCurrent = ptrCurrent->next;
		}

		if (ptrCurrent == NULL)
		{
			cout << "\nBook with ID " << ID << " not found in the list\n";
			char a;
			cout << "\nEnter any key to continue: ";
			cin >> a;
			return;
		}

		if (ptrCurrent == HeadPtr)
		{
			HeadPtr = HeadPtr->next;
		}
		else
		{
			ptrPrevious->next = ptrCurrent->next;
		}

		cout << "\nBook with ID " << ID << " has been Deleted.\n";

		delete ptrCurrent;
		char a;
		cout << "\nEnter any key to continue: ";
		cin >> a;
		return;
	}

	void showParticularBook()
	{
		int ID;
		cout << "Enter the ID of the book that you want to see: ";
		cin >> ID;

		bookList *print = HeadPtr;
		while (print != NULL)
		{
			if (print->obj.get_ID() == ID)
			{
				print->obj.PrintBookDetails();
				cout << "\nEnter any key to continue: ";
				char a;
				cin >> a;
				return;
			}
			print = print->next;
		}
		cout << "There is no book with this ID!";
		char a;
		cout << "\nEnter any key to continue: ";
		cin >> a;
		return;
	}
};
class CStudent
{

	int ID;
	string StdName;
	int RollNo, count;
	CBook BooksIssued[5];

public:
	CStudent(int _ID = 0, string _StdName = "\0", int _RollNo = 0, int _BooksIssued[5] = {0})
	{
		ID = _ID;
		StdName = _StdName;
		RollNo = _RollNo;
		count = 0;
	}
	void IssueBook(bookList *tempBook)
	{
		if (count < 5)
			BooksIssued[count] = tempBook->obj.getBook();
		count++;
	}

	int getID()
	{
		return ID;
	}
	string getStdName()
	{
		return StdName;
	}
	int getRollNo()
	{
		return RollNo;
	}

	void setID(int _ID)
	{
		ID = _ID;
	}
	void setStdName(string _StdName)
	{
		StdName = _StdName;
	}
	void setRollNo(int _RollNo)
	{
		RollNo = _RollNo;
	}

	void printStudent()
	{
		cout << endl;
		cout << "Student ID : " << ID << endl;
		cout << "Student Name : " << StdName << endl;
		cout << "Student Roll No : " << RollNo << endl;
	}
};
struct node
{
	CStudent std;
	node *next;
};
class CStudentList
{
private:
	node *head;

public:
	node *getStudentHead()
	{
		return head;
	}
	CStudentList()
	{
		head = NULL;
	}
	void addStudent()
	{
		node *newnode = new node;
		node *tempnode = head;
		string name;
		int ID, Roll;
		int issuedbook[5] = {0};

		cout << "Enter Last name of the student: ";
		cin >> name;
		newnode->std.setStdName(name);
		cout << "Enter the Student ID: ";
		cin >> ID;
		newnode->std.setID(ID);
		cout << "Enter the Student's roll number: ";
		cin >> Roll;
		newnode->std.setRollNo(Roll);

		newnode->next = NULL;
		if (head == NULL)
		{
			head = newnode;
			return;
		}
		while (tempnode->next != NULL)
		{
			tempnode = tempnode->next;
		}
		tempnode->next = newnode;
	}
	void deleteStudent()
	{
		int ID;
		cout << "\nEnter the Id of the student that you want to delete: ";
		cin >> ID;
		node *ptrCurrent = head;
		node *ptrPrevious = head;

		while (ptrCurrent != NULL)
		{
			if (ptrCurrent->std.getID() == ID)
				break;
			ptrPrevious = ptrCurrent;
			ptrCurrent = ptrCurrent->next;
		}
		if (ptrCurrent == NULL)
		{
			cout << "\n No student with this ID has been found!\n";
		}
		else
		{

			if (ptrCurrent == head)
			{
				head = ptrCurrent->next;
			}
			else
			{
				ptrPrevious->next = ptrCurrent->next;
			}
		}
	}
	void printStudentList()
	{
		node *print = head;

		while (print != NULL)
		{
			print->std.printStudent();
			print = print->next;
		}
		char a;
		cout << "\nEnter any key to continue: ";
		cin >> a;
	}

	void printSelectedStudent()
	{
		int ID;
		cout << "Enter the ID of the student who's details you want to see: ";
		cin >> ID;

		node *currentnode = head;

		while (currentnode != NULL)
		{
			if (currentnode->std.getID() == ID)
			{
				currentnode->std.printStudent();
				char a;
				cout << "\nEnter any key to continue: ";
				cin >> a;
				return;
			}
			currentnode = currentnode->next;
		}
		cout << "There is no student with such ID!";
		char a;
		cout << "\nEnter any key to continue: ";
		cin >> a;
		return;
	}
};

class CLibrary
{
private:
	CBookList Blist;
	CStudentList Slist;

public:
	CLibrary() {}
	void deleteIssuedBook(int ID)
	{
		bookList *temp = Blist.getBookHead();
		bookList *prev = temp;
		while (temp != NULL)
		{
			if (temp->obj.get_ID() == ID)
			{
				if (temp == Blist.getBookHead())
				{
					temp = temp->next;
					break;
				}
				else
					prev->next = temp->next;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	CBookList &getBookList()
	{
		return Blist;
	}

	CStudentList &getStudentList()
	{
		return Slist;
	}
	void issueBook()
	{
		int bookID, studentID;
		cout << "Enter the ID of the book that you want to be issued: ";
		cin >> bookID;
		bookList *tempBookHead = Blist.getBookHead();
		node *tempStudenthead = Slist.getStudentHead();
		while (tempBookHead != NULL)
		{
			if (tempBookHead->obj.get_ID() == bookID)
			{
				break;
			}
			tempBookHead = tempBookHead->next;
		}

		if (tempBookHead == NULL)
		{
			cout << "This book does not exist!";
			char a;
			cout << "\nEnter any key to continue: ";
			cin >> a;
			return;
		}
		else
		{
			cout << "Enter the student for which you want to issue the book: ";
			cin >> studentID;
			while (tempStudenthead != NULL)
			{
				if (tempStudenthead->std.getID() == studentID)
				{
					break;
				}
				tempStudenthead = tempStudenthead->next;
			}
			if (tempStudenthead == NULL)
			{
				cout << "This student does not exist!";
				char a;
				cout << "\nEnter any key to continue: ";
				cin >> a;
				return;
			}
			else
			{
				tempStudenthead->std.IssueBook(tempBookHead);
				deleteIssuedBook(bookID);
			}
		}

		char a;
		cout << "\nEnter any key to continue: ";
		cin >> a;
	}
	void returnIssuedBook()
	{
		char a;
		cout << "\nEnter any key to continue: ";
		cin >> a;
	}
	void printIssuedBooks()
	{
		char a;
		cout << "\nEnter any key to continue: ";
		cin >> a;
		return;
	}
};

int mainMenu();
void SubMenu(int, CLibrary &);
void studentSubMenu(CStudentList &);
void bookSubMenu(CBookList &);
void librarySubMenu(CLibrary &);

int main()
{
	CLibrary lib;
	while (true)
	{
		int choice = mainMenu();
		SubMenu(choice, lib);
	}
	return 0;
}

int mainMenu()
{
	int choice;

	while (true)
	{
		system("cls");
		cout << "1. Student" << endl
			 << "2. Book" << endl
			 << "3. Library" << endl
			 << "4. Exit" << endl
			 << endl;

		cout << "Your Choice: ";

		cin >> choice;

		if (!cin || choice < 1 || choice > 4)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
			break;
	}

	return choice;
}
void SubMenu(int x, CLibrary &lib)
{
	system("cls");

	switch (x)
	{
	case 1:
		studentSubMenu(lib.getStudentList()); // student does not need the booklist part of library, so only the studentlist object of library is being passed
		break;
	case 2:
		bookSubMenu(lib.getBookList()); // clist is being passed instead of whole library, because book menu will only relate with books and booklists
		break;
	case 3:
		librarySubMenu(lib); // here complete library is being passed because it will access both the functionality of books/booklists and students/studentlist in order to issue/return books
		break;
	case 4:
		exit(1);
	}
}

void studentSubMenu(CStudentList &studentList)
{
	int choice;

	while (true)
	{
		system("cls");
		cout << "1. Add New Student" << endl
			 << "2. Delete Existing Student" << endl
			 << "3. Show Particular Student" << endl
			 << "4. Show All Students" << endl
			 << "5. BACK" << endl
			 << endl;

		cout << "Your Choice: ";
		cin >> choice;

		if (!cin || choice < 1 || choice > 5)
		{
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}

		if (choice == 5)
			return;

		switch (choice)
		{
		case 1:
			studentList.addStudent();
			break;

		case 2:
			studentList.deleteStudent();
			break;

		case 3:
			studentList.printSelectedStudent();
			break;

		case 4:
			studentList.printStudentList();
			break;
		}
	}
}

void bookSubMenu(CBookList &blist)
{
	int choice;
	while (true)
	{
		system("cls");

		cout << "1. Add New Book" << endl
			 << "2. Delete Existing Book" << endl
			 << "3. Show All Books" << endl
			 << "4. Show Particular Book" << endl
			 << "5. BACK\n\n";

		cout << "Your Choice: ";
		cin >> choice;

		if (choice == 5)
			return;

		switch (choice)
		{
		case 1:
			blist.Addbook();
			break;

		case 2:
			blist.DeleteBook();
			break;

		case 3:
			blist.printBookList();
			break;

		case 4:
			blist.showParticularBook();
			break;
		}
	}
}

void librarySubMenu(CLibrary &clibrary)
{
	while (true)
	{
		system("cls");
		cout << "1. Issue a Book" << endl
			 << "2. Return a Book" << endl
			 << "3. Print which books have been issued" << endl
			 << "4. BACK" << endl
			 << endl;

		cout << "Your Choice: ";
		int choice;
		cin >> choice;

		if (!cin || choice < 1 || choice > 4)
		{
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}

		if (choice == 4)
			return;

		system("cls");

		switch (choice)
		{
		case 1:
			clibrary.issueBook();
			break;
		case 2:
			clibrary.returnIssuedBook();
			break;
		case 3:
			clibrary.printIssuedBooks();
			break;
		}
	}
}