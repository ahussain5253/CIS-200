#include<iostream>
using namespace std;

//Function with array A[][], length, width as its parameters
//This function sum of elements in array A and return the result
int arraySum(int A[][10], int length, int width) {
    //Local varaible result stores the calculated sum of array elements
    int result = 0;
    //Two layer for loop to go through every element of A and calculate the sum
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            result = result + A[i][j];
        }
    }
    return result;
}

//Main function of program starts here
int main() {
    //It is given to declare the array with size 10x10
    const int NUM_ROWS = 10;
    const int NUM_COLUMN = 10;
    //Creating 2D array with size 10x10
    int A[NUM_ROWS][NUM_COLUMN];
    //declaring lenght,width variables
    //which will be used to store the user wanted array size
    int length;
    int width;
    //Count variable is declared to keep count of the array elements
    int count = 1;
    //Reading no.of rows in array(length) from user
    cout << "Enter no.of rows of array A : ";
    cin >> length;
    //Reading no.of columns in array(width) from user
    cout << "Enter no.of columns of array A : ";
    cin >> width;
    //endl is used to print new line
    cout << endl;
    cout << "Enter the element of " << length << "x" << width << " 2D array :" << endl;
    //two layer for loops to read the length*width sized array elements
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++) {
            cout << "Enter element " << count << " : ";
            cin >> A[i][j];
            count = count + 1;
        }
    }
    cout << endl;
    //Printing the array
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //Calling arraySum() function and storing the function return value in variable sum
    int sum = arraySum(A, length, width);
    cout << "Sum of elements of entered array is : " << sum;
    return 0;
}