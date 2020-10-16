#pragma once

#include "Class_ToDoItem.h"

vector<ToDoItem> List;

class ToDoList {

public:

	ToDoList() { count = 0; }
	ToDoList(const ToDoList& list);
	int AddToDoItem() {

		string Title;
		string Description;

		cin.ignore();
		cout << "Enter Title of the Item" << endl << endl;
		getline(cin, Title);
		cout << endl;

		cout << "Enter Description of Item" << endl << endl;
		getline(cin, Description);
		cout << endl;

		string input;

		type Type;

		cout << "Enter type of item (shopping, housing, or work)" << endl << endl;
		cin >> input;
		cout << endl;

		if (input == "shopping") 

			Type = shopping;
		
		else if (input == "housing") 

			Type = housing;

		
		else 

			Type = work;

		

		string input2;

		status Status;

		cout << "Enter status of task (finished, running, hold)" << endl << endl;
		cin >> input2;
		cout << endl;

		if (input2 == "finished") 

			Status = finished;
		
		else if (input2 == "running") 

			Status = running;

		
		else 

			Status = hold;

		int priority;

		cout << "What is the priority number? (1-5)" << endl;
		cin >> priority;

	
		 ToDoItem todo(count1, Title, Description, Type, priority, Status);

		count1++;

		todo.setID(count1);

		List.push_back(todo);

		return count1;
	}


private:

	int count;

	ToDoItem TODoObjects[MAX_SIZE];
};

ToDoList::ToDoList(const ToDoList& list) {

	ToDoList ToDoObjects = list;

}










