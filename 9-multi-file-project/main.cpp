#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	const int n = 10;
	int a[n] = { -10, 1, -4, -2, 0 , 1, 6, 3, -9, 5 };

	int sumofodd = sum(a,n);
	cout << "Summa nechetnich elementov massiva: " << sumofodd << endl;

	int min = findmin(a, n);
	int max = findmax(a, n);
	int negsum = negativesum(a, n, min, max);
	if ((negsum >= 0) || (min == max))
		cout << "There is no elements between min&max " << endl;
	else
		cout << "Sum of elements between first&last negative elements of array: " << negsum << endl;

	removearray(a, n);
	cout << "Changed array: ";
	arrayout(a, n);

	return 0;
}