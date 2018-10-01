/*
* course: CMPS 2143 - OOP
* Purpose: This program is a version of the previous one
* that uses overloaded functions to make it run more 
* efficiently.
@ leah phinney
  github lgphinney
@version 1.2 9/12/18
*/
#include <iostream>
#include "myVector.h"

using namespace std;


int main() {
	myVector V1(10); //test code
	myVector V2(20);

	//int A[] = {1,2,3,4};

	for (int i = 0; i<7; i++) {
		V1.pushBack(rand() % 100);
	}

	for (int i = 0; i<5; i++) {
		V2.pushBack(rand() % 100);
	}

	cout << V1 << endl;
	cout << V2 << endl;

	myVector v3 = V1 + V2;

	myVector v1;
	myVector v2;

	v1.pushBack(8);
	// v1 contains: [8]

	v2.pushBack(10);
	v2.pushBack(20);
	v2.pushBack(30);
	// v2 contains: [10,20,30]

	// Declare some int array
	int A[] = { 1,2,3,4,5 };


	v1.pushBack(A, 5);
	// v1 contains: [8,1,2,3,4,5]

	v1 = v1 + v2;
	// v1 contains: [18,21,32,3,4,5]

	cout << v1 << endl;
	// would print: [18,21,32,3,4,5] to standard out.

	cout << v1[2] << endl;
	// would print: 32 to standard out.


	v2 = v2 * 3;
	// v2 contains: [30,60,90]

	v2 = v2 * v1;
	// v2 contains: [540,1260,2880]

	v2[2] = 100;
	// v2 contains: [540,1260,100]

	// What about strings??
	system("pause");
	return 0;
}
