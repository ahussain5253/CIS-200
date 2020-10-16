
#include "Class_ToDoItem.h"
#include "Class_ToDoList.h"



int main() {

	int again = 1;

	while (again == 1) {

		int userChoice;

		cout << "Menu for To-Do List Program:" << endl << endl;
		cout << "Select from the items below:" << endl << endl;
		cout << "1: Create a To-Do list or Add an item to To-Do list" << endl << endl;
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1) {

			ToDoList mytodo;

			int n;
			
			n = mytodo.AddToDoItem();

			cout << "Item created with Id #" << n << endl;

		}

		for (int i = 0; i < List.size(); i++) {

			cout << List.at(i).getID();
			cout << List.at(i).getType();
			cout << List.at(i).getStatus();

		}

		cout << "again" << endl;
		cin >> again;


	}
		

		



	return 0;
}


