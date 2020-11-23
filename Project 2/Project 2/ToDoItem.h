#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include <fstream>
#include <ostream>

using namespace std;

int count1 = 0;

time_t now = time(0);

char* dt = ctime(&now);


enum Status { Complete, InProgress, OnHold, UnassignedStatus };
enum Type { shopping, housing, work, UnassignedType };

struct createDate { string createDate; };
struct dueDate { string dueDate; };
struct lastModifiedDate { string lastModifiedDate; };

class ToDoItem
{
public:
	ToDoItem();
	ToDoItem(string Title, string Description, Type type);
	ToDoItem(string Title, Type type, int Priority);
	ToDoItem(string Title, Type type, int Priority, string dueDate);
	ToDoItem(int Id, string Title, string Description, int Priority, Status status, Type type, string dueDate);

	int getId() { return this->Id; }
	string getTitle() { return this->Title; }
	string getDescription() { return this->Description; };
	string getType() {

		string type;
		if (this->type == shopping) { type = "shopping"; }
		if (this->type == housing) { type = "housing"; }
		if (this->type == work) { type = "work"; }
		if (this->type == UnassignedType) { type = "Unassigned"; }

		return type;
	};
	int getPriority() { return this->Priority; };
	string getStatus() {

		string status;
		if (this->status == Complete) { status = "Complete"; }
		if (this->status == InProgress) { status = "InProgress"; }
		if (this->status == OnHold) { status = "OnHold"; }
		if (this->status == UnassignedStatus) { status = "Unassigned"; }

		return status;

	};
	string getcreateDate() {return this->createDate.createDate; };
	string getdueDate() { return this->dueDate.dueDate; };
	string getlastModifiedDate() { return this->lastModifiedDate.lastModifiedDate; };

	void setId(int Id) { this->Id = Id; };
	void setTitle(string Title) { this->Title = Title; };
	void setDescription(string Description) { this->Description = Description; };
	void setType(Type type) { this->type = type; };
	void setPriority(int Priority) { this->Priority = Priority; };
	void setStatus(Status status) { this->status = status; };
	void setcreateDate(string createDate) { this->createDate.createDate = "November 2020"; };
	void setdueDate(string dueDate) { this->dueDate.dueDate = dueDate; };
	void setlastModifiedDate(string lastModifiedDate) { this->lastModifiedDate.lastModifiedDate = lastModifiedDate; };

private:

	int Id;
	string Title;
	string Description;
	int Priority;
	Status status;
	Type type;
	createDate createDate;
	dueDate dueDate;
	lastModifiedDate lastModifiedDate;
};

ToDoItem::ToDoItem() {

	this->Id = 0;
	this->Title = "Untitled";
	this->Description = "No Description";
	this->Priority = 0;
	this->status = UnassignedStatus;
	this->type = UnassignedType;

	cout << "What is the due date for this task? (Enter in this format: MM/DD/YYYY)" << endl << endl;
	cin >> this->dueDate.dueDate;


}

ToDoItem::ToDoItem(string Title, string Description, Type type) {

	this->Title = Title;
	this->Description = Description;
	this->type = type;

}

ToDoItem::ToDoItem(string Title, Type type, int Priority) {

	this->Title = Title;
	this->type = type;
	this->Priority = Priority;

}

ToDoItem::ToDoItem(string Title, Type type, int Priority, string dueDate) {

	this->Title = Title;
	this->type = type;
	this->Priority = Priority;
	this->dueDate.dueDate = dueDate;

}

ToDoItem::ToDoItem(int Id, string Title, string Description, int Priority, Status status, Type type, string dueDate) {

	this->Id = Id;
	this->Title = Title;
	this->Description = Description;
	this->Priority = Priority;
	this->status = status;
	this->type = type;
	this->dueDate.dueDate = dueDate;

	this->createDate.createDate = dt;
	this->lastModifiedDate.lastModifiedDate = dt;

}
