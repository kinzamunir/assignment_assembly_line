#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "assembly_line.h"

using namespace std;


int main()
{

	int number, e1, e2, x1, x2;
	int w, v, x, y;
	int f1[60], f2[60], L1[60], L2[60], L;

	cout << "Enter the number of stations in lines: " << endl;
	cin >> number;

	/* initialize random seed: */
	srand(time(NULL));

	e1 = rand() % 30 + 1;
	cout << "The cost of entrying in line 1: " << e1<< endl;
	
	e2 = rand() % 30 + 1;
	cout << "The cost of entrying in line 2: " << e2 << endl<<endl;

	//dynamic array
	int *a1 = new int[number];
	int *a2 = new int[number];
	int *t1 = new int[number];
	int *t2 = new int[number];
	//the first value of array is 0 in all cases.
	a1[0] = 0;
	a2[0] = 0;
	t1[0] = 0;
	t2[0] = 0;

	for (int i = 1; i <= number; i++){
		a1[i] = rand() % 30 + 1;
		cout << "The cost of stations in line 1: " << a1[i] << endl;
	}
	cout << endl;
	for (int i = 1; i <= number; i++){
		a2[i] = rand() % 30 + 1;
		cout << "The cost of stations in line 2: " << a2[i] << endl;
	}
	cout << endl;
	for (int i = 1; i <= number - 1; i++){
		t1[i] = rand() % 30 + 1;
		cout << "The transfer cost from station in line 1 to line 2:  " << t1[i] << endl;
	}

	for (int i = 1; i <= number - 1; i++){
		t2[i] = rand() % 30 + 1;
		cout << "The transfer cost from station in line 2 to line 1:  " << t2[i] << endl;
	}
	cout << endl;
	
	x1  = rand() % 30 + 1;
	cout << "The cost of exiting line 1: " << x1 << endl;
	
	x2  = rand() % 30 + 1;
	cout << "The cost of exiting line 2: " << x2 << endl<<endl;
	FastWay(a1, a2, t1, t2, e1, e2, x1, x2, f1, f2, L1, L2, L, number + 1);
	lane(L1, L2, L, number, f1);
	return 0;
}