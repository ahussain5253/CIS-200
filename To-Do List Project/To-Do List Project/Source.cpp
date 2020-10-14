#include <iostream>
#include <string>
#include <ctime>

#define MAX_SIZE 100

using namespace std;

enum type { shopping, housing, work};
enum status { finished, running, hold};


class ToDoItem {

public:

	ToDoItem(int Id, string Title, string Description, type Type);
	ToDoItem(int Id, string Title, int Priority, type Type);
	ToDoItem(int Id, string Title, int Priority, type Type, time_t DueDate);

	int getID() { return Id; }
	void setID(int Id) { this->Id = Id; }

	string getTitle() { return Title; }
	void setTitle(string Title) { this->Title = Title; }

	string getDescription() { return Description; }
	void setDescription(string Description) { this->Description = Description; }

	type getType() { return Type; }
	void setType(type Type) { this->Type = Type; }

	int getPriority() { return Priority; }
	void setPriority(int Priority) { this->Priority = Priority; }

	status getStatus() { return Status; }
	void set(status Status) { this->Status = Status; }

	time_t getCreateDate() { return CreateDate; }
	void setCreateDate(time_t CreateDate) { this->CreateDate = CreateDate; }

	time_t getDueDate() { return DueDate; }
	void setDueDate(time_t DueDate) { this->DueDate = DueDate; }

	time_t getLastModified() { return LastModified; }
	void setLastModified(time_t LastModified) { this->LastModified = LastModified; }

private:

	int Id;
	string Title;
	string Description;
	int Priority;
	type Type;
	status Status;
	time_t CreateDate = time(0);
	time_t DueDate;
	time_t LastModified;
};

ToDoItem::ToDoItem(int Id, string Title, string Description, type Type) {

	this->Id = Id;
	this->Title = Title;
	this->Type = Type;
	this->Description = Description;
}

ToDoItem::ToDoItem(int Id, string Title, int Priority, type Type) {
	
	this->Id = Id;
	this->Title = Title;
	this->Type = Type;
	this->Priority = Priority;
}

ToDoItem::ToDoItem(int Id, string Title, int Priority, type Type, time_t DueDate) {

	this->Id = Id;
	this->Title = Title;
	this->Type = Type;
	this->Priority = Priority;
	this->DueDate = DueDate;
}

class ToDoList {

public:

	ToDoList() { count = 0; }
	ToDoList(const ToDoList& list);

private:

	int count;
	ToDoItem ToDoObjects[MAX_SIZE];

};

ToDoList::ToDoList(const ToDoList& list) {

	ToDoList ToDoObjects = list;

}


int main() {

	

	return 0;
}