#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a, z1, z2;

	cout << "Vvedite znachenie A:" << endl;
	cin >> a;

	z1 = ((a + 2) / (sqrt(2 * a)) - (a / (sqrt(2 * a) + 2)) + (2 / (a - sqrt(2 * a)))) * ((sqrt(a) - sqrt(2)) / (a + 2));
	z2 = 1 / (sqrt(a) + sqrt(2));

	cout << "Znachenie z1: " << z1 << endl << "Znachenie z2: " << z2 << endl;

	return 0;
}