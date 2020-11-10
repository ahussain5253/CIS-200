#include<iostream>

using namespace std;

struct listrec {
    int value;
    struct listrec* next;
};

void deepcopy(listrec* oldlink, listrec*& newlink) {

    listrec* p;
    p = oldlink;

    while (p != NULL) {
        listrec* q = new listrec();
        q->value = p->value;
        q->next = NULL;
        if (newlink == NULL) {
            newlink = q;
        }
        else {
            listrec* r = newlink;
            while (r->next != NULL)
                r = r->next;
            r->next = q;
        }
        p = p->next;
    }
}

void disp(listrec* start) {

    listrec* p = start;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {

    listrec* head_old, * head_new = NULL;

    head_old = new listrec();
    head_old->value = 4;
    listrec* p, * q;
    p = head_old;
    p->next = new listrec();
    p = p->next;
    p->value = 5;
    p->next = new listrec();
    p = p->next;
    p->value = 3;
    p->next = NULL;

    p = head_old;
    q = new listrec();
    q->value = 6;
    q->next = p->next;
    p->next = q;

    deepcopy(head_old, head_new);
    disp(head_new);
    return 0;
}