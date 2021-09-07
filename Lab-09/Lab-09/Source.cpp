#include <iostream>

using namespace std;

template <typename T> T maxfunc(T arr[], int size) {

	int j;

	T maxVal = arr[0];

	for (int i = 1; i < size; i++) {

		if (maxVal < arr[i]) {

			maxVal = arr[i];

		}

	}

	return maxVal;

}

struct Date {

	int day;
	int month;
	int year;

};



template <class T>
class A
{
	T valuea;

public:

	T getValuea() const { return valuea; }
	void setValuea(int x) { valuea = x; }
	// copy constructor
	A(const A& classA) { A classa = classA; }

};

template <class T>
class B
{
	T valueb;
	T valuea;

public:

	B(T valuea, T valueb) { this->valuea = valuea; this->valueb = valueb; }
	T getValueb() const { return valueb; }
	void setValueb(T x) { this->valueb = x; }
	T getValuea() const { return valuea; }
	void setValuea(int x) { valuea = x; }
	// copy constructor
	B(const B& classB) { B classb = classB;}


};

int main() {

	// Question 1

	int first[5] = { 4,1,13,3,2 };

	float second[5] = { 1.1,4.1,8.1,5.2,2.3 };

	char third[7] = { 'A','B','a','c','d','E','f' };

	cout << "Max of first array: " << maxfunc(first, 5) << endl << endl;
	cout << "Max of second array: " << maxfunc(second, 5) << endl << endl;
	cout << "Max of third array: " << maxfunc(third, 7) << endl << endl;

	// Question 2

	B<float> floatb(1.34, 3.14);
	cout << "Float valuea: " << floatb.getValuea() << endl << "Float valueb: " << floatb.getValueb() << endl << endl;

	B<int> intb(1, 3);
	cout << "Integer valuea: " << intb.getValuea() << endl << "Integer valueb: " << intb.getValueb() << endl << endl;

	B<char> charb('a', 'c');
	cout << "Char valuea: " << charb.getValuea() << endl << "Char valueb: " << charb.getValueb() << endl << endl;

	B<string> stringb("good", "morning");
	cout << "String valuea: " << stringb.getValuea() << endl << "String valueb: " << stringb.getValueb() << endl << endl;

	Date a;

	a.day = 27;
	a.month = 10;
	a.year = 2014;

	Date b;

	b.day = 2;
	b.month = 11;
	b.year = 2014;

	B<Date> dateb(a, b);
	cout << "Date valuea: " << dateb.getValuea().day << "/" << dateb.getValuea().month << "/" << dateb.getValuea().year << endl;
	cout << "Date valueb: " << dateb.getValueb().day << "/" << dateb.getValueb().month << "/" << dateb.getValueb().year << endl;
	return 0;
}