#pragma once

#include "ToDoItem.h"

class ToDoList
{
public:

	ToDoList() {

		head = NULL;
		curr = NULL;
		temp = NULL;

	};

	ToDoList(const ToDoList& list) { ToDoList ToDoItems = list; }

	void addNode();
	void deleteNode();
	void editToDoItem();
	void writeListToFile();
	void readListFromFile();
	void printList();
	void mergeList(ToDoItem itemToMerge);

private:

	int count;

	struct Node {

		ToDoItem item;
		Node* next;
	};
	typedef struct Node* NodePtr;

	NodePtr head;
	NodePtr curr;
	NodePtr temp;
};


void ToDoList::addNode() {

	string Title;
	string Description;
	int Priority;
	Status status = Complete;
	Type type;
	string dueDate;

	cout << "Enter a title for this item" << endl << endl;
	cin >> Title;
	cout << endl;

	cin.ignore();
	cout << "Enter a description for this item" << endl << endl;
	getline(cin, Description);
	cout << endl;

	cout << "Enter the priority of this item" << endl << endl;
	cin >> Priority;
	cout << endl;

	string t;
	cout << "Enter the type of this item (Only enter either shopping, housing, or work)" << endl << endl;
	cin >> t;
	cout << endl;

	if (t == "shopping") { type = shopping; }
	if (t == "housing") { type = housing; }
	if (t == "work") { type = work; }

	string s;
	cout << "Enter the status of this item (Only enter either Complete, InProgress, OnHold)" << endl << endl;
	cin >> s;
	cout << endl;

	if (s == "Complete") { status = Complete; }
	if (s == "InProgress") { status = InProgress; }
	if (s == "OnHold") { status = OnHold; }

	cout << "What is the due date for this task? (Enter in this format: MM/DD/YYYY)" << endl << endl;
	cin >> dueDate;
	cout << endl;

	ToDoItem listItem(count1, Title, Description, Priority, status, type, dueDate);

	count1++;

	listItem.setId(count1);

	NodePtr n = new Node;
	n->next = NULL;
	n->item = listItem;

	if (head != NULL) {

		curr = head;

		while (curr->next != NULL) {

			curr = curr->next;

		}

		curr->next = n;

	}
	else {

		head = n;

	}

	cout << endl;
	cout << "Item with Id " << count1 << " has been created and added to the list" << endl << endl;

}

void ToDoList::deleteNode() {

	cout << endl;
	int userChoice;
	cout << "Would you like to delete an item by 1. Id, 2. All types, or 3. All statuses? (Type 1 2 or 3)" << endl << endl;
	cin >> userChoice;
	cout << endl;

	if (userChoice == 1) {

		int userId;

		cout << "What is the Id of the item you want to delete?" << endl << endl;
		cin >> userId;
		cout << endl;

		NodePtr delPtr = NULL;
		temp = head;
		curr = head;

		while (curr != NULL && curr->item.getId() != userId) {

			temp = curr;
			curr = curr->next;

		}

		if (curr == NULL) {

			cout << "The item with Id " << userId << " was not found in the list" << endl << endl;
			delete delPtr;

		}

		else {

			delPtr = curr;
			curr = curr->next;
			temp->next = curr;

			delete delPtr;

			cout << "The item with Id " << userId << " was succesfully deleted" << endl << endl;

		}

	}

	if (userChoice == 2) {

		string userType;

		int u;

		cout << "What is the type of the items you want to delete? (Enter 1 for shopping, 2 for housing, and 3 for work)" << endl << endl;
		cin >> u;
		cout << endl;

		if (u == 1) {

			userType = "shoppin:";

		}
		if (u == 2) {

			userType = "housing";

		}
		if (u == 3) {

			userType = "work";

		}

		NodePtr delPtr = NULL;
		temp = head;
		curr = head;

		while (curr != NULL && curr->item.getType() != userType) {

			temp = curr;
			curr = curr->next;

		}

		if (curr == NULL) {

			if (userType == "shopping") {

				cout << "No items with type shopping were not found in the list" << endl << endl;
				delete delPtr;
			}
			if (userType == "housing") {

				cout << "No items with type housing were not found in the list" << endl << endl;
				delete delPtr;
			}
			if (userType == "work") {

				cout << "No items with type work were not found in the list" << endl << endl;
				delete delPtr;
			}

		}

		else {

			delPtr = curr;
			curr = curr->next;
			temp->next = curr;

			delete delPtr;

			if (userType == "shopping") {

				cout << "All items with type shopping were succesfully deleted" << endl << endl;

			}
			if (userType == "housing") {

				cout << "All items with type housing were succesfully deleted" << endl << endl;

			}
			if (userType == "work") {

				cout << "All items with type work were succesfully deleted" << endl << endl;
			}

		}

	}

	if (userChoice == 3) {

		string userStatus;

		int u;

		cout << "What is the status of the items you want to delete? (Enter 1 for Complete, 2 for InProgress, and 3 for OnHold)" << endl << endl;
		cin >> u;
		cout << endl;

		if (u == 1) {

			userStatus = "Complete";

		}
		if (u == 2) {

			userStatus = "InProgress";

		}
		if (u == 3) {

			userStatus = "OnHold";

		}

		NodePtr delPtr = NULL;
		temp = head;
		curr = head;

		while (curr != NULL && curr->item.getStatus() != userStatus) {

			temp = curr;
			curr = curr->next;

		}

		if (curr == NULL) {

			if (userStatus == "Complete") {

				cout << "No items of status Complete were not found in the list" << endl << endl;
				delete delPtr;
			}
			if (userStatus == "InProgress") {

				cout << "No items of status InProgress were not found in the list" << endl << endl;
				delete delPtr;
			}
			if (userStatus == "OnHold") {

				cout << "No items of status OnHold were not found in the list" << endl << endl;
				delete delPtr;
			}

		}

		else {

			delPtr = curr;
			curr = curr->next;
			temp->next = curr;

			delete delPtr;

			if (userStatus == "Complete") {

				cout << "All items with the status Complete were succesfully deleted" << endl << endl;

			}
			if (userStatus == "InProgress") {

				cout << "All items with the status InProgress were succesfully deleted" << endl << endl;

			}
			if (userStatus == "OnHold") {

				cout << "All items with the status OnHold were succesfully deleted" << endl << endl;
			}

		}


	}

}

void ToDoList::editToDoItem() {

	int userId;

	cout << "What is the Id of the element you wish to edit?" << endl << endl;
	cin >> userId;
	cout << endl;

	NodePtr editPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->item.getId() != userId) {

		temp = curr;
		curr = curr->next;

	}

	if (curr == NULL) {

		cout << "There were no items with that Id found in the list" << endl << endl;
		delete editPtr;

	}

	else {

		editPtr = curr;
		curr = curr->next;
		temp->next = curr;

		int userChoice;

		cout << "What do you want to edit from the list? (Enter one number from below)" << endl << endl;
		cout << "1: Title" << endl;
		cout << "2: Description" << endl;
		cout << "3: Type" << endl;
		cout << "4: Priority" << endl;
		cout << "5: Status" << endl;
		cout << "6: Due Date" << endl << endl;
		cin >> userChoice;

		if (userChoice == 1) {

			string title;

			cout << endl;
			cout << "What is the new title?" << endl << endl;
			cin >> title;
			cout << endl;

			editPtr->item.setTitle(title);

			string date;

			cout << endl;
			cout << "What is the date today? (MM/DD/YYYY)" << endl << endl;
			cin >> date;
			cout << endl;

			editPtr->item.setlastModifiedDate(date);

			cout << "The title has been succesfully changed" << endl << endl;

		}

		if (userChoice == 2) {

			string desc;

			cin.ignore();
			cout << "What is the new description?" << endl << endl;
			getline(cin, desc);
			cout << endl;

			editPtr->item.setDescription(desc);

			string date;

			cout << endl;
			cout << "What is the date today? (MM/DD/YYYY)" << endl << endl;
			cin >> date;
			cout << endl;

			editPtr->item.setlastModifiedDate(date);


		}

		if (userChoice == 3) {

			Type type;

			int userChoice;

			cout << "What is the new type? (Enter 1 for shopping, 2 for housing, or 3 for work)" << endl << endl;
			cin >> userChoice;
			cout << endl;

			if (userChoice == 1) { type = shopping; editPtr->item.setType(type); }
			if (userChoice == 2) { type = housing; editPtr->item.setType(type); }
			if (userChoice == 3) { type = work; editPtr->item.setType(type); }
		}
		if (userChoice == 4) {

			int p;

			cout << "What is the new priority?" << endl << endl;
			cin >> p;
			cout << endl;

			editPtr->item.setPriority(p);

			string date;

			cout << endl;
			cout << "What is the date today? (MM/DD/YYYY)" << endl << endl;
			cin >> date;
			cout << endl;

			editPtr->item.setlastModifiedDate(date);

			cout << "The priority has been succesfully changed" << endl << endl;

		}
		if (userChoice == 5) {

			Status status;;

			int userChoice;

			cout << "What is the new status? (Enter 1 for Complete, 2 for InProgress, or 3 for OnHold)" << endl << endl;
			cin >> userChoice;
			cout << endl;

			if (userChoice == 1) { status = Complete; editPtr->item.setStatus(status); }
			if (userChoice == 2) { status = InProgress; editPtr->item.setStatus(status); }
			if (userChoice == 3) { status = OnHold; editPtr->item.setStatus(status); }

			string date;

			cout << endl;
			cout << "What is the date today? (MM/DD/YYYY)" << endl << endl;
			cin >> date;
			cout << endl;

			editPtr->item.setlastModifiedDate(date);
		}
		if (userChoice == 6) {

			string dd;

			cout << "What is the new due date? (Enter in this form MM/DD/YYYY)" << endl << endl;
			cin >> dd;
			cout << endl;

			editPtr->item.setdueDate(dd);

			string date;

			cout << endl;
			cout << "What is the date today? (MM/DD/YYYY)" << endl << endl;
			cin >> date;
			cout << endl;

			editPtr->item.setlastModifiedDate(date);

			cout << "The due date has been succesfully changed" << endl << endl;

		}

	}

}

void ToDoList::writeListToFile() {

	ofstream outputFileStream("ListItems.txt", ios::app);

	if (!outputFileStream.is_open()) {

		cout << "Can't create file ListItems.txt." << endl;

	}

	else {

		curr = head;

		int itemNum = 1;

		while (curr != NULL) {

			outputFileStream << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
			curr = curr->next;

			itemNum++;

		}

		cout << "Successfully written to file named ListItems.txt" << endl << endl;

	}

}

void ToDoList::readListFromFile() {

	string line;

	ifstream myfile("C:\\Users\\Ammar\\Desktop\\CIS-200\\Project 2\\Project 2\\ListItems.txt");

	if (myfile.is_open()) {

		while (getline(myfile, line)) {

			cout << line << '\n';

		}

		myfile.close();

	}
	else {

		cout << endl;
		cout << "Unable to open file (file not created first or error)" << endl << endl;

	}
}

void ToDoList::printList() {

	int userChoice;

	cout << "How would you like to print the items? Please only enter the number associated with each selection" << endl << endl;
	cout << "1: Print all items" << endl;
	cout << "2: Print items only of a certain type" << endl;
	cout << "3: Print items only of a certain priority" << endl;
	cout << "4: Print one item given the Id" << endl << endl;
	cin >> userChoice;
	cout << endl;

	int itemNum = 1;

	if (userChoice == 1) {

		curr = head;

		while (curr != NULL) {

			cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
			curr = curr->next;

			itemNum++;
		}

	}

	if (userChoice == 2) {

		int userChoice;

		cout << "What type of items would you like to output? (Enter 1 for shopping, 2 for housing, and 3 for work)" << endl << endl;
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1) {

			curr = head;

			while (curr != NULL) {


				if (curr->item.getType() == "shopping") {

					cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
					curr = curr->next;
				}

				else {

					curr = curr->next;
				}

			}


		}

		if (userChoice == 2) {

			curr = head;

			while (curr != NULL) {

				if (curr->item.getType() == "housing") {

					cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
					curr = curr->next;
				}

				else {

					curr = curr->next;
				}

			}


		}

		if (userChoice == 3) {

			curr = head;

			while (curr != NULL) {

				if (curr->item.getType() == "work") {

					cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
					curr = curr->next;
				}

				else {

					curr = curr->next;
				}

			}



		}


	}

	if (userChoice == 3) {

		int userChoice;

		cout << "What priority of items would you like to output? (Enter a number from 1 to 5)" << endl << endl;
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1) {

			curr = head;

			while (curr != NULL) {

				if (curr->item.getPriority() == 1) {

					cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
					curr = curr->next;
				}

				else {

					curr = curr->next;
				}
			}


		}

		if (userChoice == 2) {

			curr = head;

			while (curr != NULL) {

				if (curr->item.getPriority() == 2) {

					cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
					curr = curr->next;
				}

				else {

					curr = curr->next;
				}

			}


		}

		if (userChoice == 3) {

			curr = head;

			while (curr != NULL) {

				if (curr->item.getPriority() == 3) {

					cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
					curr = curr->next;
				}

				else {

					curr = curr->next;
				}

			}



		}

		if (userChoice == 4) {

			curr = head;

			while (curr != NULL) {

				if (curr->item.getPriority() == 4) {

					cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
					curr = curr->next;
				}

				else {

					curr = curr->next;
				}

			}



		}

		if (userChoice == 5) {

			curr = head;

			while (curr != NULL) {

				if (curr->item.getPriority() == 5) {

					cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
					curr = curr->next;
				}

				else {

					curr = curr->next;
				}

			}



		}


	}

	if (userChoice == 4) {

		int userChoice;

		cout << endl;
		cout << "What is the Id of the item you want to output?" << endl << endl;
		cin >> userChoice;
		cout << endl;

		curr = head;

		while (curr != NULL) {

			if (curr->item.getId() == userChoice) {

				cout << "Item " << itemNum << ". Id: " << curr->item.getId() << ", Title: " << curr->item.getTitle() << ", Description: " << curr->item.getDescription() << ", Type: " << curr->item.getType() << ", Priority: " << curr->item.getPriority() << ", Status: " << curr->item.getStatus() << ", Date Created: " << curr->item.getcreateDate() << ", Due Date: " << curr->item.getdueDate() << ", Last Modified Date: " << curr->item.getlastModifiedDate() << endl;
				curr = curr->next;

				itemNum++;

			}

			else {

				curr = curr->next;

			}

		}

	}
}

void ToDoList::mergeList(ToDoItem itemToMerge) {

	curr = head;

	while (curr != NULL) {

		curr = curr->next;

	}

	curr->item = itemToMerge;
}
