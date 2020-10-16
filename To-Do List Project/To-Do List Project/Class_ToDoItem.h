#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#define MAX_SIZE 100

int count1 = 0;

using namespace std;

enum type { shopping, housing, work };
enum status { finished, running, hold };

class ToDoItem {

public:

	ToDoItem() {};
	ToDoItem(int Id, string Title, string Description, type Type, int Priority, status Status);
	ToDoItem(int Id, string Title, int Priority, type Type);
	ToDoItem(int Id, string Title, int Priority, type Type, time_t DueDate);

	int getID() { return this->Id; }
	void setID(int Id) { this->Id = Id; }

	string getTitle() { return Title; }
	void setTitle(string Title) { this->Title = Title; }

	string getDescription() { return Description; }
	void setDescription(string Description) { this->Description = Description; }

	string getType() { 

		if (this->Type == 0) { string shopping = "shopping"; return shopping; } 
		if (this->Type == 1) { string housing = "housing"; return housing; }
		if (this->Type == 2) { string work = "work"; return work; }
	}
	void setType(type Type) { this->Type = Type; }

	int getPriority() { return Priority; }
	void setPriority(int Priority) { this->Priority = Priority; }

	string getStatus() {

		if (this->Status == 0) { string finished = "finished"; return finished; }
		if (this->Status == 1) { string running = "running"; return running; }
		if (this->Status == 2) { string hold = "hold"; return hold; }
	}
	void setStatus(status Status) { this->Status = Status; }

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

ToDoItem::ToDoItem(int Id, string Title, string Description, type Type, int priority, status Status) {

	this->Id = Id;
	this->Title = Title;
	this->Type = Type;
	this->Description = Description;
	this->Priority = priority;
	this->Status = Status;
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