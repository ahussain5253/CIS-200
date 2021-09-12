#include <iostream>
#include <string>
#include "SortedArray.h"
#include "SortedArray.cpp"
using namespace std;


const int N = 1787;
const int M = 2357;

int main()
{
    SortedArray<int> sortedArray;
    SortedArray<string> animals;

    string string1[] = { "zebra", "tiger", "lion", "dog", "monkey", "snake", "turkey",
                        "cat", "duck", "alligator" };

    int minimumValue1, maximumValue1;
    int i, j;

    int index;

    for (i = N; i != 0; i = (i + N) % M)
        sortedArray.insert(i);

    cout << "Completed first round of insertions" << endl;

    for (j = 1; !sortedArray.empty(); j++)
    {
        minimumValue1 = sortedArray.findMinimum();
        sortedArray.deleteMinimum();
        if (minimumValue1 != j)
            cout << "OOPS!!!!!" << minimumValue1 << " " << j << endl;

        maximumValue1 = sortedArray.findMaximum();
        sortedArray.deleteMaximum();
        if (maximumValue1 != M - j)
            cout << "OOPS!!!!!" << maximumValue1 << " " << (M - j) << endl;
    }

    cout << "Completed first round of deletions" << endl;

    for (i = N; i != 0; i = (i + N) % M)
        sortedArray.insert(i);

    cout << "Completed second round of insertions" << endl;

    for (i = 0; i < M - 5; i += 2)
    {
        sortedArray.deleteMinimum();
        sortedArray.deleteMaximum();
    }

    while (!sortedArray.empty()) {
        cout << sortedArray.findMinimum() << endl;
        cout << sortedArray.findMaximum() << endl;
        sortedArray.deleteMinimum();
        sortedArray.deleteMaximum();
    }

    cout << "Completed the Integer Array test" << endl << endl;

    for (i = 0; i < 10; i++) {
        animals.insert(string1[i]);
    }

    cout << "Animal list: " << endl;
    animals.print(cout, '\n');
    cout << endl << endl;

    index = animals.binarySearch("lion");
    if (index >= 0) {
        cout << animals[index] << " is found in the list." << endl;
    }
    else {
        cout << "OOPS!!!!!" << "Lion should be in the list." << endl;
    }

    index = animals.binarySearch("bear");
    if (index >= 0) {
        cout << "OOPS!!!!!" << "Bear should not be in the list." << endl;
    }
    else {
        cout << "Bear is not found in the list." << endl;
    }

    SortedArray<string> animalsCopy(animals);

    if (animalsCopy.equals(animals)) {
        cout << "Correct! " << "The two animal lists are the same." << endl;
    }
    else {
        cout << "OOPS!!!!!" << "They should be equal" << endl;
    }

    animalsCopy.deleteMinimum();
    animalsCopy.deleteMaximum();

    cout << endl << "Animal list after the deletion: " << endl;
    animalsCopy.print(cout, '\n');
    cout << endl << endl;

    cout << "Completed the String Array test" << endl;

    getchar();

    return 0;
}