#include "Header.h"

int main() {

	string userInput;

	Stack stack;

	cout << "Enter a Postfix expression or enter 'stop' to stop" << endl << endl;

	while (true) {

		cin >> userInput;

		if (userInput == "stop") {

			break;

		}
		else if (userInput == "+") {

			double secondValue = stack.Pop();
			double firstValue = stack.Pop();

			stack.Push(firstValue + secondValue);

		}

		else if (userInput == "*") {

			double secondValue = stack.Pop();
			double firstValue = stack.Pop();

			stack.Push(firstValue * secondValue);

		}

		else if (userInput == "-") {

			double secondValue = stack.Pop();
			double firstValue = stack.Pop();

			stack.Push(firstValue - secondValue);

		}

		else if (userInput == "/") {

			double secondValue = stack.Pop();
			double firstValue = stack.Pop();

			stack.Push(firstValue / secondValue);

		}

		else if (userInput == "=") {

			cout << endl;
			cout << fixed << showpoint << setprecision(5);
			cout << stack.Pop() << endl << endl;

		}

		else {

			double convertedNum = stod(userInput);

			stack.Push(convertedNum);

		}

	}

	return 0;

}