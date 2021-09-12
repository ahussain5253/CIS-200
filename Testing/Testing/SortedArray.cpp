#ifdef SortedArray_H

//initial size of empty array
const int initSize = 0;

//Constructor
template <typename Object>
SortedArray<Object>::SortedArray() : sizeOfArray(initSize), capacityOfArray(initSize + SPARE_CAPACITY)
{
    objectsInArray = new Object[capacityOfArray];
}

//Copy Constructor
template <typename Object>
SortedArray<Object>::SortedArray(const SortedArray <Object>& from) : objectsInArray(NULL)
{
    operator=(from);
}

//Destructor
template <typename Object>
SortedArray<Object>::~SortedArray()
{
    delete[] objectsInArray;
}

// Overloading assignment operator
template <typename Object>
const SortedArray<Object>& SortedArray<Object>:: operator= (const SortedArray<Object>& from)
{
    if (this != &from)
    {
        delete[] objectsInArray;
        sizeOfArray = from.size();
        capacityOfArray = from.capacity();
        objectsInArray = new Object[capacity()];
        for (int i = 0; i < sizeOfArray; ++i)
        {
            objectsInArray[i] = from.objectsInArray[i];
        }
    }
    return *this;
}

//accessor Operator
template <typename Object>
const Object& SortedArray<Object>::operator[](int index) const
{
    return objectsInArray[index];
}

//check if two sorted arrays are same
template <typename Object>
bool SortedArray<Object>::equals(const SortedArray <Object>& rightHandSize)
{
    if (size() == rightHandSize.size())
    {
        for (int i = 0; i < sizeOfArray; ++i)
        {
            if (objectsInArray[i] != rightHandSize.objectsInArray[i])
                return false;
        }
        return true;
    }
    return false;
}

//check if array is empty
template <typename Object>
bool SortedArray<Object>::empty() const
{
    if (sizeOfArray == 0)
        return true;
    return false;
}

//get the size of objects
template <typename Object>
int SortedArray<Object>::size() const
{
    return sizeOfArray;
}

//get the capacity of objects
template <typename Object>
int SortedArray<Object>::capacity() const
{
    return capacityOfArray;
}

//Reserve function
template <typename Object>
void SortedArray<Object>::reserve(int newCapacity)
{
    if (newCapacity > sizeOfArray)
    {
        Object* old = objectsInArray;
        objectsInArray = new Object[newCapacity];
        for (int i = 0; i < sizeOfArray; ++i)
        {
            objectsInArray[i] = old[i];
        }
        capacityOfArray = newCapacity;
        delete[] old;
    }
}

//function to elements of the array
template <typename Object>
void SortedArray<Object>::print(ostream& out, char delimiter) const
{
    for (int i = 0; i < sizeOfArray; ++i)
    {
        out << objectsInArray[i] << delimiter;
    }
}

// function to clear the elements in the array
template <typename Object>
void SortedArray<Object>::clear()
{
    for (int i = 0; i < sizeOfArray; ++i)
    {
        objectsInArray[i] = NULL;
    }
    sizeOfArray = 0;
}

// function to inserts elements into the sorted arry
template <typename Object>
void SortedArray<Object>::insert(const Object& obj)
{
    if (sizeOfArray == capacityOfArray)
    {
        reserve(2 * sizeOfArray + 1);
    }

    if (sizeOfArray == 0)
    {
        objectsInArray[0] = obj;
    }
    else
    {
        int i;
        for (i = sizeOfArray - 1; (i >= 0 && objectsInArray[i] > obj); i--)
            objectsInArray[i + 1] = objectsInArray[i];

        objectsInArray[i + 1] = obj;
    }
    sizeOfArray++;
}

//functino to delete minimum value
template <typename Object>
void SortedArray<Object>::deleteMinimum()
{
    for (int i = 0; i < sizeOfArray - 1; ++i)
    {
        objectsInArray[i] = objectsInArray[i + 1];
    }
    sizeOfArray--;
}

//function to delete maximum value
template <typename Object>
void SortedArray<Object>::deleteMaximum()
{
    sizeOfArray--;

}

//function to find minimum value
template <typename Object>
const Object& SortedArray<Object>::findMinimum() const
{
    return objectsInArray[0];
}

//function to find maximum value
template <typename Object>
const Object& SortedArray<Object>::findMaximum() const
{
    return objectsInArray[sizeOfArray - 1];
}

//Binary Search function
template <typename Object>
int binarySearch(Object* array, int left, int right, Object object)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == object)
            return mid;

        if (array[mid] > object)
            return binarySearch(array, left, mid - 1, object);

        return binarySearch(array, mid + 1, right, object);
    }
    return -1;
}

//Binary Search
template <typename Object>
int SortedArray<Object>::binarySearch(const Object& obj)
{
    return binarySearch(objectsInArray, 0, sizeOfArray, obj);
}

#endif