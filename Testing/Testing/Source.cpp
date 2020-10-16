// I have defined the structure of the first few functions to give you all the idea you need. You can modify it and define the rest on your own to serve your purpose.
#include <iostream> // std input output
#include <string> // use string data type
#include <ctime> // to use date time datatype
using namespace std; // to easily ise cin and cout without writing std::
#define MAX_SIZE 100 // defining MAX_SIZE to represent 100

enum type //defining an enumeration data type by the name type which can hold the given values
{
	shopping,
	housing,
	work
};
enum status //defining an enumeration data type by the name status which can hold the given values
{
	done,
	inProgress,
	hold
};

// Class For To Do Item
class ToDoItem
{
private:
	// below mentioned are all the attributes given in the question
	int Id;
	string Title;
	string Description;
	type Type;
	int Priority;
	status Status;
	// time_t is a datatype for date time
	time_t CreateDate = time(0); // time initialized with present time.
	time_t DueDate;
	time_t LastModified;

public:
	// The different constructor functions
	ToDoItem() {};
	ToDoItem(int Id, string Title, type Type, string Description)
	{
		this->Id = Id;
		this->Title = Title;
		this->Description = Description;
		this->Type = Type;
	}
	ToDoItem(int Id, string Title, type Type, int Priority)
	{
		this->Id = Id;
		this->Title = Title;
		this->Type = Type;
		this->Priority = Priority;
	}
	ToDoItem(int Id, string Title, type Type, int Priority, time_t DueDate)
	{
		this->Id = Id;
		this->Title = Title;
		this->Type = Type;
		this->Priority = Priority;
		this->DueDate = DueDate;
	}

	// all the get/set methods required
	int getId() { return Id; }
	void setId(int Id) { this->Id = Id; }

	string getTitle() { return Title; }
	void setTitle(string Title) { this->Title = Title; }

	string getDescription() { return Description; }
	void setDescription(string Description) { this->Description = Description; }

	type getType() { return Type; }
	void setType(type Type) { this->Type = Type; }

	int getPriority() { return Priority; }
	void setPriority(int Priority) { this->Priority = Priority; }

	status getStatus() { return Status; }
	void sets(status Status) { this->Status = Status; }

	time_t getCreateDate() { return CreateDate; }
	void setCreateDate(time_t CreateDate) { this->CreateDate = CreateDate; }

	time_t getDueDate() { return DueDate; }
	void setDueDate(time_t DueDate) { this->DueDate = DueDate; }

	time_t getLastModified() { return LastModified; }
	void setLastModified(time_t LastModified) { this->LastModified = LastModified; }
};

// ToDo list class for maintaining an array of to-do items
class ToDoList
{
private:
	int count; // We will be mainiaining the number of to do items in the to do list
	ToDoItem TODoObjects[MAX_SIZE];

public:
	// Constructor
	ToDoList() { count = 0; }
	// Copy Constructor
	ToDoList(const ToDoList& list) { ToDoList TODoObjects = list; }
	// method to add a to do item
	int AddToDoItem()
	{
		string Title;
		string Description;
		cout << "Enter Title: ";
		cin >> Title;
		cout << "Enter Description: ";
		cin >> Description;
		string inp; // we will take a string input and match it with our type enumerator because directly taking an enumerator input is not possible in C++
		type Type;
		cout << "Enter Type: ";
		cin >> inp;
		if (inp == "shopping")
			Type = shopping; // we change the value of our type enum as per the value of our string input
		else if (inp == "housing")
			Type = housing;
		else
			Type = work;
		TODoObjects[count] = ToDoItem(count, Title, Type, Description); // we have used the counter to give the id number to our to do item, you can use any other approach too.
		count++; // after inserting the to do item, we have increased the count to reflect the number of to do items
		return count;
	}
};

// this is the driver function to run the above class functions and achieve our task
int main()
{
	ToDoList mytodo;
	int i, n;
	// you can provide all the menu options required. I have displayed 2 as an example.
	cout << "You can perform the following operations:\n1. Add To Do Item\n2. Exit the program";
	// 1 means always true, so infinite while loop is run so that we can ask the user again and again what he wants to choose, untill they opt to exit, in which case we call run
	while (1)
	{
		cout << "Enter your choice";
		cin >> i;
		// Switch menu to perform different operations of your choice.
		switch (i)
		{
		case 1: // thsi will be called when the user wants to add an item in the to do list
			n = mytodo.AddToDoItem(); // we will take the count number and hence the id to display the user where the item is inserted, so that they can refer to it for future modifications/deletions
			cout << "New item added to the list with Id: " << n;
			break;
		case 2:
			return 0;
		default: // the default case is triggered when none of the correct options have been selected, thus the user will be asked for a choice again
			cout << "Please enter the right choice.";
		}
	}
	return 0;
}