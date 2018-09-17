#include <iostream>

using namespace std;

/*  the class itself. 
*/
class myVector {
private:
	int *theVector;
	int vSize;
	int index;

public:
	//constructors
	myVector();
	myVector(int size);
	myVector(myVector& other);

	//size
	int size();

	//functions 
	void print();
	void resize(double multiple);
	int pop();
	void push(int val);

};
