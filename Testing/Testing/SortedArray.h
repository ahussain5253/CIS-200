#ifndef SortedArray_H
#define SortedArray_H

#include <iostream>
using namespace std;

//SortedArray<Object>

template <typename Object>
class SortedArray
{
public:

    // Default constructor
    SortedArray();

    // Copy constructor
    SortedArray(const SortedArray <Object>& from);

    // Destructor
    ~SortedArray();

    // Assignment operator
    const SortedArray& operator= (const SortedArray& from);

    // Accessor Operator []
    const Object& operator[](int index) const;

    // equals
    bool equals(const SortedArray <Object>& rightHandSize);

    // empty
    bool empty() const;

    // size
    int size() const;

    // capacity
    int capacity() const;

    // reserve
    void reserve(int);
    void print(ostream& out, char delimiter = ',') const;


    //clear method
    void clear();

    //insert
    void insert(const Object& obj);

    //delete min
    void deleteMinimum();

    //delet max
    void deleteMaximum();

    //function to find the minimum element in the sorted array
    const Object& findMinimum() const;

    //function to find the maximum element in the sorted array
    const Object& findMaximum() const;

    //binarySearch
    int binarySearch(const Object& obj);

    enum { SPARE_CAPACITY = 16 };

private:
    int sizeOfArray;
    int capacityOfArray;
    Object* objectsInArray;
};

#endif