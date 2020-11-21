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

	void getCreateDate() {

		time_t now = time(0);

		tm* ltm = localtime(&now);

		cout << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year;

	}

	void getDueDate() { cout << this->month << "/" << this->day << "/" << this->year; }
	void setDueDate() { 

		cout << endl;
		cout << "Please enter the due date in the format MM DD YYYY (without slashes only spaces)" << endl << endl;	
		cin >> this->month >> this->day >> this->year;

	
	}

	void getLastModified() { 
	
		cout << this->month << "/" << this->day << "/" << this->year;
	
	}
	void setLastModified() { 
	
		cout << endl;
		cout << "Please enter today's date in the format MM DD YYYY (without slashes only spaces)" << endl << endl;
		cin >> this->LMmonth >> this->LMday >> this->LMyear;
	
	}

private:

	int Id;
	string Title;
	string Description;
	int Priority;
	int month;
	int day;
	int year;
	int LMmonth;
	int LMday;
	int LMyear;
	type Type;
	status Status;
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