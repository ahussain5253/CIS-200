#include <iostream>

#include <string>

using namespace std;

class Node {
public:

	char a;
	Node* nodeptr;

	Node(char b = ' ', Node* ptr = nullptr) {
		a = b;
		nodeptr = ptr;
	}
};

class List {

	Node* Head;

public:

	List() {
		Head = nullptr;
	}

	List(const List& rhs) {
		string data = rhs.toString();
		fromString(data);
	}

	void addToEnd(char let) {

		Node* p = Head;

		if (Head == nullptr) {
			Head = new Node(let);
		}
		else {
			while (p->nodeptr != nullptr)
				p = p->nodeptr;

			p->nodeptr = new Node(let);
		}
	}

	void fromString(const string& word) {

		for (const char& c : word) {
			addToEnd(c);
		}
	}

	string toString() const {

		string blank = "";
		Node* ptr = Head;

		while (ptr != nullptr) {

			blank += ptr->a;
			ptr = ptr->nodeptr;
		}
		return blank;
	}

	List operator+(const List& rhs) const {

		List list;
		string y = toString() + rhs.toString();
		list.fromString(y);
		return list;
	}

	~List() {

		Node* ptr = Head;
		while (ptr != nullptr) {
			Node* t = ptr;
			ptr = ptr->nodeptr;
			delete t;
		}
	}

	friend ostream& operator<<(ostream& out, const List& rhs);
};

ostream& operator<<(ostream& os, const List& obj) {

	os << obj.toString();
	return os;
}

int main() {

	List list1;
	List list2;
	List list3;

	string word1 = "cat";
	string word2 = "fish";
	string word3 = "";

	list1.fromString(word1);
	list2.fromString(word2);

	word3 = list1.toString();

	cout << list1 << " + " << list2 << " = ";
	cout << list1 + list2 << endl;

	return 0;
}