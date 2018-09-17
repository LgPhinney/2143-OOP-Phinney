#include <iostream>
#include "myVector.h"

using namespace std;

/*  default constructor.
*/
myVector::myVector() {
	index = 0;
	vSize = 10;
	theVector = new int[vSize];
	//just so we have stuff to print!!!!!
	for (int i = 0; i<vSize; i++) {
		theVector[i] = i * 2;
	}
}

/*  default constructor.
    params: size 
*/
myVector::myVector(int size) {
	index = 0;
	vSize = size;
	theVector = new int[vSize];
	//just so we have stuff to print!!!!!
	for (int i = 0; i<vSize; i++) {
		theVector[i] = i * 2;
	}
}

/*  params: other vector
*/
myVector::myVector(myVector& other)
{
	index = other.index;
	vSize = other.vSize;
	for (int i = 0; i<vSize; i++) {
		theVector[i] = other.theVector[i];
	}
}

//size
int myVector::size()
{
	return index;
}

//print vector using index
void myVector::print() {
	for (int i = 0; i<index; i++) {
		cout << theVector[i] << " ";
	}
	cout << endl;
}

/*  resize the array to make it big or smaller
    params: multiplier 
*/
void myVector::resize(double multiple)
{
	int newsize = multiple * vSize;
	int *temp;
	int *arry;
	arry = new int[newsize];

	for (int i = 0; i < newsize; i++)
	{
		arry[i] = 0;
	}

	for (int i = 0; i < vSize; i++)
	{
		arry[i] = theVector[i];
	}

	temp = theVector;
	theVector = arry; //shift pointer
	delete[]temp;
	vSize = newsize;
}

//kick out the thing
int myVector::pop()
{
	if (index == 0)
	{
		cout << "No. Dont pop an empty vector." << endl;
		return 0;
	}

	index--;
	int trash = theVector[index];
	if (index < vSize *.4)
	{
		resize(.5);
	}
	return trash;
}

//pushin the thing
//accepts val
void myVector::push(int val)
{
	theVector[index] = val;
	index++;
	if (index == vSize)
	{
		resize(1.5);
	}
}
