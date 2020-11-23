
#include "ToDoItem.h"
#include "ToDoList.h"

int main() {

	ToDoList List;
	
	int again = 1;

	while (again == 1) {

		int userChoice;

		cout << endl;
		cout << "Menu for To-Do List Program:" << endl << endl;
		cout << "Select from the items below (Type just the number):" << endl << endl;
		cout << "1: Create a To-Do list and Add an item" << endl;
		cout << "2: Edit an item from the To-Do list" << endl;
		cout << "3: Delete an item from the To-Do list" << endl;
		cout << "4: Write list to a text file" << endl;
		cout << "5: Read list from a text file" << endl;
		cout << "6: Print Items" << endl;
		cout << endl;
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1) {

			List.addNode();

		}

		if (userChoice == 2) {

			List.editToDoItem();

		}

		if (userChoice == 3) {

			List.deleteNode();

		}

		if (userChoice == 4) {

			List.writeListToFile();
		}

		if (userChoice == 5) {

			cout << "Contents of List.txt: " << endl << endl;

			List.readListFromFile();

		}

		if (userChoice == 6) {

			cout << "Please follow instructions below" << endl << endl << endl;

			List.printList();

		}

		cout << endl;
		cout << "Would you like to preform another action? (Type 1 for yes or 2 for no)" << endl << endl;
		cin >> again;
	}

	
	return 0;
}