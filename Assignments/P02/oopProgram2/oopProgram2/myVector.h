#include <iostream>

using namespace std;

class myVector {
private:
	int *vPtr;      // int pointer to array
	int maxSize;    // max size of array
	int minSize;    // min size of array
	int index;      // current location to insert or remove
	int* _resize(int);

public:
	const int DEFSIZE = 1;
	myVector();
	myVector(int size);
	
	void pushBack(int item);
	void pushBack(int *, int size);
	void pushBack(myVector& other);
	int popBack();
	double percentFull();
	int* resize(double);
	int* resize(int);
	myVector operator=(myVector righthand); //overloaded =
	myVector operator-(myVector righthand); //overloaded - 
	myVector operator*(myVector rhs); //overloaded * (multiplcation)
	myVector operator/(myVector rhs); //overloaded / (division) 
	myVector operator==(myVector other); //overloaded equality

	void print();
	int size();
	void size(int);
	int vSize();

	// Implementation of [] operator.  This function must return a 
	// refernce as array element can be put on left side 
	int& operator[](int i)
	{
		if (i >= maxSize)
		{
			cout << "Array index out of bound, exiting\n";
			exit(0);
		}
		else if (i >= index) {
			cout << "Warning: vector[" << i << "] is undefined ...\n";
		}
		return vPtr[i];
	}

	friend ostream& operator<<(ostream& os, myVector V) {
		for (int i = 0; i<V.index; i++) {
			os << V.vPtr[i] << " ";
		}
		//os<<"test"<<endl;
		return os;
	}

	
	//hey look a + overloaded
	myVector operator+(const myVector& rhs) {

		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector newVector(max);
		for (int i = 0; i < max; i++)
		{
			newVector.vPtr[i] = vPtr[i] + rhs.vPtr[i];
		}

		// Of course, this doesn't have anything in it!
		return newVector;
	}


};

/**
* Default constructor
*   Sets up the vector
* @param {int} size : initial size of vector
* @return void
*/
myVector::myVector() {
	maxSize = DEFSIZE; //const used here only 
	minSize = DEFSIZE;
	// create the array of vSize
	vPtr = new int[maxSize];
	index = 0;
}



/**
* Function constructor
*   Sets up the vector
* @param {int} size : initial size of vector
* @return void
*/
myVector::myVector(int size) {
	maxSize = size;
	minSize = size;
	// create the array of vSize
	vPtr = new int[maxSize];
	index = 0;
}

/**
* Function print
*   Prints the current values in the vector
* @param void
* @return void
*/
void myVector::print() {
	for (int i = 0; i<index; i++) {
		cout << vPtr[i] << " ";
	}
	cout << endl;
}

/**
* Function pushBack
*   Adds value to vector
* @param {int} item : integer value
* @return void
*/
void myVector::pushBack(int item) {
	if (index >= maxSize) {
		vPtr = resize(1.5);
	}
	vPtr[index++] = item;
}

void myVector::pushBack(int * vectArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		pushBack(vectArray[i]); //push in all 
	}

}

/**
* OVERLOADED Function pushBack
*   Adds value to vector
* @param {int} item : integer value
* @return void
*/
void myVector::pushBack(myVector& other) 
{
	pushBack(other.vPtr, other.vSize()); 
	//its an overload using other overloaded functions
}

/**
* Function popBack
*   Returns value from vector
* @param none
* @return {int} : last item on vector
*/
int myVector::popBack() {

	index--;

	if (index < 0) {
		//dammit
		cout << "oops" << endl;
	}

	if (percentFull() <= .4) {
		vPtr = resize(.5);
	}

	return vPtr[index];
}

/**
* Function resize
*   Resizes our vector based on passed in ratio
* @param {double} ratio : new array size
* @return {int*} : pointer to new array
*/
int* myVector::resize(double ratio) {
	// figure out what our new size is, bigger or smaller
	int newSize = maxSize * ratio;

	return _resize(newSize);
}

int* myVector::resize(int size) {

	return _resize(size);

}

int* myVector::_resize(int newSize) {
	// Lets keep our vector above some minimum size
	if (newSize < minSize) {
		newSize = minSize;
	}

	// allocate new bigger vector
	int* vBigger = new int[newSize];

	//copy everything over
	for (int i = 0; i<index; i++) {
		vBigger[i] = vPtr[i];
	}

	// update new max size
	maxSize = newSize;

	// delete old memory
	delete[] vPtr;

	//return ptr to new memory
	return vBigger;
}

/**
* Function percentFull
*   helper function to calculate how full vector is
* @param none
* @return {double} : how full vector is
*/
double myVector::percentFull() {
	return double(index) / double(maxSize);
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
int myVector::size() {
	return index;
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
void myVector::size(int newSize) {
	vPtr = _resize(newSize);
}

/**
* Function vSize
*    Returns actual size of allocated memory
* @param none
* @return {int} : mem size
*/
int myVector::vSize() {
	return maxSize;
}

/**
* Function size
* Overloads the = operator to compare two values 
* of two vectors.
* @param myvector righthand (or rhs)
* @return myVector
*/
myVector myVector::operator=(myVector righthand)
{
	myVector c(righthand.vSize());


	for (int i = 0; i < righthand.vSize(); i++)
	{
		righthand.vPtr[i] = c.vPtr[i];

	}
	return c;

}

/**
* Overload subtraction
* Subtracts two vectors.
* @param none
* @return myVector
*/
myVector myVector :: operator-(myVector rhs)
{
	int rhsSize = rhs.index;
	int lhsSize = index;
	int max = 0;

	// which vector is bigger?
	if (rhsSize > lhsSize)
		max = rhsSize;
	else
		max = lhsSize;

	// create a new vector with the bigger size
	myVector newVector(max);
	for (int i = 0; i < max; i++)
	{
		newVector.vPtr[i] = vPtr[i] - rhs.vPtr[i];
	}

	// Of course, this doesn't have anything in it!
	return newVector;

}

/**
*  Overload Multiplecation 
*  Multiplies the contents of two vectors 
* @param none
* @return myVector
*/
myVector myVector::operator*(myVector rhs)
{
	int rhsSize = rhs.index;
	int lhsSize = index;
	int max = 0;

	// which vector is bigger?
	if (rhsSize > lhsSize)
		max = rhsSize;
	else
		max = lhsSize;

	// create a new vector with the bigger size
	myVector newVector(max);
	for (int i = 0; i < max; i++)
	{
		newVector.vPtr[i] = vPtr[i] * rhs.vPtr[i];
	}

	// Of course, this doesn't have anything in it!
	return newVector;

}

/**
* Overload Division
* Divides two vectors and 
* stores the result in a third 
* @param none
* @return MyVector 
*/
myVector myVector::operator/(myVector rhs)
{
	int rhsSize = rhs.index;
	int lhsSize = index;
	int max = 0;

	// which vector is bigger?
	if (rhsSize > lhsSize)
		max = rhsSize;
	else
		max = lhsSize;

	// create a new vector with the bigger size
	myVector newVector(max);
	for (int i = 0; i < max; i++)
	{
		newVector.vPtr[i] = vPtr[i] / rhs.vPtr[i];
	}

	// Of course, this doesn't have anything in it!
	return newVector;

}

/**
* Overload Equality 
* Compares two vectors and returns 
* whether both are identical.
* @param none
* @return Bool 
*/
myVector myVector::operator==(myVector other)
{
	bool equal = true;

	if (other.vSize() == vSize())
	{
		for (int i = 0; i < other.vSize(); i++)
		{
			if (other.vPtr[i] != vPtr[i])
				equal = false;
		}
	}
	else
		equal = false;

	return equal;
}