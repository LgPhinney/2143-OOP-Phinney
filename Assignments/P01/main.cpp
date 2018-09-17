#include <iostream>
#include "myVector.h"
using namespace std;

struct arrInfo {
	int *arr;
	int size;
};


arrInfo copyArray2(int *a, int size);
int* copyArray(int *a, int size);
int* resizeArray(int *a, int orig_size, int new_size);
void print(int *arry, int size);

int main() {
	myVector theVector(10);
	theVector.pop(); //test popping empty vect

	theVector.push(13); //more testing
	theVector.print();
	theVector.push(31);
	theVector.print();
	theVector.push(73);
	theVector.print();

	for (int i = 0; i < 10000; i++)
	{
		theVector.push(6);
	}
	cout << "vector size" << theVector.size() <<endl;

	for (int i = 0; i < 998; i++)
	{
		theVector.pop();
	}
	cout << "vector size" << theVector.size() << endl;

	int *orig;
	int *copy;

	orig = new int[10];

	for (int i = 0; i<10; i++) {
		orig[i] = rand() % 1000;
	}

	//print(orig,10);

	// point copy at orig base address
	// setting one pointer = to the other
	copy = orig;

	//print(copy,10);

	copy[3] = 3;

	//print(orig,10);

	int* myAwesomeArray = copyArray(orig, 10);

	print(myAwesomeArray, 20);

	//arrInfo info = copyArray2(myAwesomeArray,20);

	//cout<<info.size<<endl;

	//delete[] copy;
	//delete[] orig;

	myAwesomeArray = resizeArray(myAwesomeArray, 20, 5);

	print(myAwesomeArray, 5);

	system("pause");
}



// returns a struct with a pointer to the array
// and the arrays size
arrInfo copyArray2(int *a, int size) {

	arrInfo info;
	// new size is double original
	info.size = size * 2;

	//allocate new memory and reference
	//it with the struct arr member
	info.arr = new int[info.size];

	//Initialize new array with zeros
	//for printing purposes
	for (int i = 0; i<info.size; i++) {
		info.arr[i] = 0;
	}

	//copying old array into new
	for (int i = 0; i<size; i++) {
		info.arr[i] = a[i];
	}

	//return the pointer to the new array
	return info;
}


// creates a new array double the size of the 
// original and returns a pointer to it.
int* copyArray(int *a, int size) {
	int *newArray;
	int newSize = size * 2;

	newArray = new int[newSize];

	//Initialize new array with zeros
	//for printing purposes
	for (int i = 0; i<newSize; i++) {
		newArray[i] = 0;
	}

	//copying old array into new
	for (int i = 0; i<size; i++) {
		newArray[i] = a[i];
	}

	//return the pointer to the new array
	return newArray;
}

int* resizeArray(int *a, int orig_size, int new_size) {
	int *newArray;
	int newSize = new_size;

	newArray = new int[newSize];

	//Initialize new array with zeros
	//for printing purposes
	for (int i = 0; i<newSize; i++) {
		newArray[i] = 0;
	}

	//copying old array into new
	for (int i = 0; i<new_size; i++) {
		newArray[i] = a[i];
	}

	//return the pointer to the new array
	return newArray;
}

void print(int *arry, int size) {
	for (int i = 0; i<size; i++) {
		cout << arry[i] << " ";
	}
	cout << endl;

}
