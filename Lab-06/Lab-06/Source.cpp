#include <iostream>

using namespace std;

struct listrec
{
	int value;
	struct listrec* next;

};

void deepcopy(listrec* old_linked_list, listrec*& new_linked_list) {

	listrec* oldlist;
	oldlist = old_linked_list;

	while (oldlist != NULL) {

		listrec* newlist = new listrec();
		newlist->value = oldlist->value;

		newlist->next = NULL;

		if (new_linked_list == NULL) {

			new_linked_list = newlist;

		}
		else {
			listrec* other = new_linked_list;

			while (other->next != NULL)

				other = other->next;

			other->next = newlist;

		}

		oldlist = oldlist->next;


	}

}

void display(listrec* begin) {

	listrec* e = begin;

	while (e != NULL) {

		cout << e->value << " ";
		e = e->next;

	}

	cout << endl;

}

// r = p    q = s

int main() {

	listrec* head_old, * head_new = NULL;

	head_old = new listrec();

	head_old->value = 4;

	listrec* r, * s;

	r = head_old;

	r->next = new listrec();

	r = r->next;

	r->value = 5;

	r->next = new listrec();

	r = r->next;

	r->value = 3;

	r->next = NULL;

	r = head_old;

	s = new listrec();

	s->value = 6;

	s->next = r->next;

	r->next = s;

	deepcopy(head_old, head_new);

	display(head_new);



	return 0;
}
