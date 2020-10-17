
#include "Class_ToDoItem.h"
#include "Class_ToDoList.h"

#include <fstream>
#include <ostream>



int main() {

	int again = 1;

	while (again == 1) {

		int userChoice;

		cout << endl;
		cout << "Menu for To-Do List Program:" << endl << endl;
		cout << "Select from the items below (Type just the number):" << endl << endl;
		cout << "1: Create a To-Do list or Add an item to To-Do list" << endl;
		cout << "2: Edit To-Do Item by Id" << endl;
		cout << "3: Delete To-Do Item by Id" << endl;
		cout << "4: Delete To-Do Item by Type" << endl;
		cout << "5: Delete To-Do Item by Status" << endl;
		cout << "6: Write To-Do Items to a text file" << endl;
		cout << "7: Read To-Do Items from a text file" << endl;
		cout << "8: Print Items to console with different options" << endl;
		cout << "9: Clone current To-Do List to another To-Do List" << endl << endl;
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1) {

			ToDoList mytodo1;

			int n;

			n = mytodo1.AddToDoItem();

			cout << endl;
			cout << "Item created with Id #" << n << endl << endl;

		}

		if (userChoice == 2) {

			int success = 0;

			int userID;

			cout << "What is the Id of the item you want to edit?" << endl << endl;
			cin >> userID;

			for (int i = 0; i < List.size(); i++) {

				if (List.at(i).getID() == userID) {

					int toEdit;

					cout << endl;
					cout << "What would you like to edit?" << endl << endl;
					cout << "Choose from the options below and enter just the number:" << endl << endl;
					cout << "1: TItle" << endl << "2: Description" << endl << "3: Type" << endl << "4: Priority" << endl << "5: Status" << endl << "6: Due Date" << endl << endl;
					cin >> toEdit;

					if (toEdit == 1) {

						string newTitle;

						cout << endl;
						cout << "Current Title: " << List.at(i).getTitle() << endl << endl;
						cout << "What would you like the new title to be?" << endl << endl;
						cin.ignore();
						getline(cin, newTitle);

						List.at(i).setTitle(newTitle);

						List.at(i).setLastModified();

						cout << endl;
						cout << "Title of Item Id #" << List.at(i).getID() << " has been changed to: " << List.at(i).getTitle() << endl << endl;

					}

					if (toEdit == 2) {

						string newDescription;

						cout << endl;
						cout << "Current Description: " << List.at(i).getDescription() << endl << endl;
						cout << "What would you like the new description to be?" << endl << endl;
						cin.ignore();
						getline(cin, newDescription);

						List.at(i).setDescription(newDescription);

						cout << endl;
						cout << "Description of Item Id #" << List.at(i).getID() << " has been changed to: " << List.at(i).getDescription() << endl << endl;


					}

					if (toEdit == 3) {

						type newType;

						string input;

						cout << endl;
						cout << "Current Type: " << List.at(i).getType() << endl << endl;
						cout << "What would you like the new type to be? (Enter shopping, housing, or work): " << endl << endl;
						cin.ignore();
						getline(cin, input);

						if (input == "shopping")

							newType = shopping;

						else if (input == "housing")

							newType = housing;


						else

							newType = work;

						List.at(i).setType(newType);

						List.at(i).setLastModified();

						cout << endl;
						cout << "Type of Item Id #" << List.at(i).getID() << " has been changed to: " << List.at(i).getType() << endl << endl;


					}

					if (toEdit == 4) {

						int newPriortiy;

						cout << endl;
						cout << "Current Priority: " << List.at(i).getPriority() << endl << endl;
						cout << "What would you like it's new priortiy to be?" << endl << endl;
						cin >> newPriortiy;

						List.at(i).setPriority(newPriortiy);

						List.at(i).setLastModified();

						cout << endl;
						cout << "Priority of Item Id #" << List.at(i).getID() << " has been changed to: " << List.at(i).getPriority() << endl << endl;


					}

					if (toEdit == 5) {

						status newStatus;

						string input;

						cout << endl;
						cout << "Current Status: " << List.at(i).getStatus() << endl << endl;
						cout << "What would you like the new status to be? (Enter finished, running, or hold): " << endl << endl;
						cin.ignore();
						getline(cin, input);

						if (input == "finished")

							newStatus = finished;

						else if (input == "running")

							newStatus = running;


						else

							newStatus = hold;

						List.at(i).setStatus(newStatus);

						List.at(i).setLastModified();

						cout << endl;
						cout << "Status of Item Id #" << List.at(i).getID() << " has been changed to: " << List.at(i).getStatus() << endl << endl;


					}
					if (toEdit == 6) {

						List.at(i).setDueDate();

						List.at(i).setLastModified();

						cout << endl;
						cout << "The due date has been set to "; List.at(i).getDueDate(); cout << endl << endl;

					}

					success = 1;

				}


			}

			if (success == 0) {

				cout << endl;
				cout << "The item with ID #" << userID << " cannot be found in the list. Please run program again." << endl << endl;

			}


		}

		if (userChoice == 3) {

			int userID;

			int success = 0;

			cout << endl;
			cout << "What is the ID of the item you want to delete from the list?" << endl << endl;
			cin >> userID;

			for (int i = 0; i < List.size(); i++) {

				if (List.at(i).getID() == userID) {

					List.erase(List.begin() + userID - 1);

					List.at(i).setLastModified();

					success = 1;

				}
			}

			if (success == 1) {

				cout << endl;
				cout << "Successfully Deleted item in list with ID #" << userID << endl << endl;

			}
			else {

				cout << endl;
				cout << "The item with ID #" << userID << " cannot be found in the list. Please run program again." << endl << endl;

			}



		}

		if (userChoice == 4) {

			string identifierType;

			int success = 0;

			cout << endl;
			cout << "What type of item would like to delete from the list? (WARNING: Will delete all items in list with this type) (Enter shopping, housing, or work)" << endl << endl;
			cin.ignore();
			getline(cin, identifierType);

			for (int i = 0; i < List.size(); i++) {

				if (List.at(i).getType() == identifierType) {

					List.erase(List.begin() + i);

					i--;

					success = 1;

				}
			}

			if (success == 0) {

				cout << endl;
				cout << "The type that was entered cannot be found in any of the items. Please run program again." << endl << endl;

			}
			else {

				cout << endl;
				cout << "Items in list with type " << identifierType << " have been deleted" << endl << endl;

			}


		}

		if (userChoice == 5) {

			string identifierStatus;

			int success = 0;

			cout << endl;
			cout << "What status of an item would like to delete from the list? (WARNING: Will delete all items in list with this status) (Enter finished, running, or hold)" << endl << endl;
			cin.ignore();
			getline(cin, identifierStatus);

			for (int i = 0; i < List.size(); i++) {

				if (List.at(i).getStatus() == identifierStatus) {

					List.erase(List.begin() + i);

					i--;

					success = 1;

				}
			}

			if (success == 0) {

				cout << endl;
				cout << "The status that was entered cannot be found in any of the items. Please run program again." << endl << endl;

			}
			else {

				cout << endl;
				cout << "Items in list with status " << identifierStatus << " have been deleted" << endl << endl;

			}


		}
		if (userChoice == 6) {

			ofstream outputFileStream;

			outputFileStream.open("ListItems.txt");

			if (!outputFileStream.is_open()) {

				cout << "Can't create file ListItems.txt." << endl;

				return 1;
			}

			else {

				for (int i = 0; i < List.size(); i++) {

					outputFileStream << "ID: " << List.at(i).getID() << ", " << "Title: " << List.at(i).getTitle() << ", " << "Description: " << List.at(i).getDescription() << ", " << "Type: " << List.at(i).getType() << ", " << "Priority: " << List.at(i).getPriority() << ", " << "Status: " << List.at(i).getStatus() << ", " << "Create Date: ";
					List.at(i).getCreateDate();
					cout << ", " << "Due Date: ";
					List.at(i).getDueDate();
					cout << ", " << "Last Modified Date: ";
					List.at(i).getLastModified(); cout  << endl;

				}
			}
			cout << endl;
			cout << "Items have been successfully written to file named: ListItems.txt" << endl << endl;

		}
		if (userChoice == 7) {

			string line;

			ifstream myfile("C:\\Users\\ammarhus\\Desktop\\CIS-200\\To-Do List Project\\To-Do List Project\\ListItems.txt");

			if (myfile.is_open()) {

				while (getline(myfile, line)) {

					cout << line << '\n';

				}

				myfile.close();

			}
			else {

				cout << "Unable to open file (file not created first or error)";

			}
		}
		if (userChoice == 8) {

			int userPrintChoice;

			cout << endl;
			cout << "Print item options (Please enter number):  " << endl << endl;
			cout << "1: Print All Items" << endl;
			cout << "2: Print items by chosen type" << endl;
			cout << "3: Print items by chosen priority" << endl;
			cout << "4: Print item by specific Id" << endl << endl;
			cin >> userPrintChoice;

			if (userPrintChoice == 1) {

				cout << endl;
				cout << "All Items: " << endl << endl;

				for (int i = 0; i < List.size(); i++) {

					cout << "ID: " << List.at(i).getID() << ", " << "Title: " << List.at(i).getTitle() << ", " << "Description: " << List.at(i).getDescription() << ", " << "Type: " << List.at(i).getType() << ", " << "Priority: " << List.at(i).getPriority() << ", " << "Status: " << List.at(i).getStatus() << ", " << "Create Date: "; 
					List.at(i).getCreateDate();
					cout << ", " << "Due Date: ";
					List.at(i).getDueDate();
					cout << ", " << "Last Modified Date: ";
					List.at(i).getLastModified();
					cout << endl;

				}

			}
			if (userPrintChoice == 2) {

				string userType;

				cout << endl;
				cout << "What type of items would you like to print? (Enter shopping, housing, or work)" << endl << endl;
				cin.ignore();
				getline(cin, userType);

				for (int i = 0; i < List.size(); i++) {

					if (List.at(i).getType() == userType) {

						cout << "ID: " << List.at(i).getID() << ", " << "Title: " << List.at(i).getTitle() << ", " << "Description: " << List.at(i).getDescription() << ", " << "Type: " << List.at(i).getType() << ", " << "Priority: " << List.at(i).getPriority() << ", " << "Status: " << List.at(i).getStatus() << ", " << "Create Date: ";
						List.at(i).getCreateDate();
						cout << ", " << "Due Date: ";
						List.at(i).getDueDate();
						cout << ", " << "Last Modified Date: ";
						List.at(i).getLastModified(); cout << endl;
					}

				}

			}
			if (userPrintChoice == 3) {

				int userPriority;

				cout << endl;
				cout << "What priority of items would you like to print? (Enter a number from 1-5)" << endl << endl;
				cin >> userPriority;

				for (int i = 0; i < List.size(); i++) {

					if (List.at(i).getPriority() == userPriority) {

						cout << "ID: " << List.at(i).getID() << ", " << "Title: " << List.at(i).getTitle() << ", " << "Description: " << List.at(i).getDescription() << ", " << "Type: " << List.at(i).getType() << ", " << "Priority: " << List.at(i).getPriority() << ", " << "Status: " << List.at(i).getStatus() << ", " << "Create Date: ";
						List.at(i).getCreateDate();
						cout << ", " << "Due Date: ";
						List.at(i).getDueDate();
						cout << ", " << "Last Modified Date: ";
						List.at(i).getLastModified(); cout << endl;
					}

				}

			}
			if (userPrintChoice == 4) {

				int userID;

				cout << endl;
				cout << "What is the ID of the item you want to print?" << endl << endl;
				cin >> userID;

				for (int i = 0; i < List.size(); i++) {

					if (List.at(i).getID() == userID) {

						cout << "ID: " << List.at(i).getID() << ", " << "Title: " << List.at(i).getTitle() << ", " << "Description: " << List.at(i).getDescription() << ", " << "Type: " << List.at(i).getType() << ", " << "Priority: " << List.at(i).getPriority() << ", " << "Status: " << List.at(i).getStatus() << ", " << "Create Date: ";
						List.at(i).getCreateDate();
						cout << ", " << "Due Date: ";
						List.at(i).getDueDate();
						cout << ", " << "Last Modified Date: ";
						List.at(i).getLastModified(); cout << endl;
					}

				}


			}

		}

		if (userChoice == 9) {

			vector<ToDoItem> newList = List;

			cout << endl;
			cout << "List has been copied to another new List" << endl << endl;
			cout << "New List Items: " << endl << endl;
			cout << "All Items: " << endl << endl;

			for (int i = 0; i < newList.size(); i++) {

				cout << "ID: " << List.at(i).getID() << ", " << "Title: " << List.at(i).getTitle() << ", " << "Description: " << List.at(i).getDescription() << ", " << "Type: " << List.at(i).getType() << ", " << "Priority: " << List.at(i).getPriority() << ", " << "Status: " << List.at(i).getStatus() << ", " << "Create Date: ";
				List.at(i).getCreateDate();
				cout << ", " << "Due Date: ";
				List.at(i).getDueDate();
				cout << ", " << "Last Modified Date: "; 
				List.at(i).getLastModified(); cout << endl;
			}

		}

		cout << endl;
		cout << "Would you like to preform another action? (Type 1 for yes or 2 for no)" << endl << endl;
		cin >> again;

	}
}

	


