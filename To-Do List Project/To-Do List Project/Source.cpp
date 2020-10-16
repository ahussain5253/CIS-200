
#include "Class_ToDoItem.h"
#include "Class_ToDoList.h"



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
		cout << "5: Delete To-Do Item by Status" << endl << endl;
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1) {

			ToDoList mytodo;

			int n;

			n = mytodo.AddToDoItem();

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
					cout << "1: TItle" << endl << "2: Description" << endl << "3: Type" << endl << "4: Priority" << endl << "5: Status" << endl << endl;
					cin >> toEdit;

					if (toEdit == 1) {

						string newTitle;

						cout << endl;
						cout << "Current Title: " << List.at(i).getTitle() << endl << endl;
						cout << "What would you like the new title to be?" << endl << endl;
						cin.ignore();
						getline(cin, newTitle);

						List.at(i).setTitle(newTitle);

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

						cout << endl;
						cout << "Status of Item Id #" << List.at(i).getID() << " has been changed to: " << List.at(i).getStatus() << endl << endl;


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

		cout << "Would you like to preform another action? (Type 1 for yes or 2 for no)" << endl << endl;
		cin >> again;

	}
}

	


