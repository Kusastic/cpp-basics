#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double a, b, c, x, xn, xk, dx, F;
	int ac, bc, cc;

	cout << "Vvedite znachenie a: " << endl;
	cin >> a ;

	cout << "Vvedite znachenie b: " << endl;
	cin >> b ;

	cout << "Vvedite znachenie c: " << endl;
	cin >> c ;

	cout << "Vvedite znachenie xn: " << endl;
	cin >> xn ;

	cout << "Vvedite znachenie xk: " << endl;
	cin >> xk ;

	cout << "Vvedite znachenie dx: " << endl;
	cin >> dx ;

	cout << endl;

	// так как ац, бц, сц это целые части а, б, с
	
	ac = int(a);
	bc = int(b);
	cc = int(c);

	cout.width(12);
	cout << " | " <<  "- - - - - - -"   << " | "  << "- - - - - - -"  << " | " << endl;

	cout.width(12);
	cout << " | " << setw(8) << "X " << setw(8) <<  " | " << setw(8) << setprecision(3) << "F " << setw(8) << " | " << endl;

	cout.width(12);
	cout << " | "  << "- - - - - - -"  << " | "  << "- - - - - - -"  << " | " << endl;
	
	
	for (x = xn; x < xk; x += dx) {

		if ((c < 0) && (x != 0)) F = -a * x - c;
		if ((c > 0) && (x == 0)) F = (x - a) / -c;
		else F = b*x / (c - a);

		if (ac || bc || cc != 0)
		{
			cout.width(12);
			cout << " | " << setw(8) << x << setw(8) << " | " << setw(8) << F << setw(8) << " | " << endl;
			cout.width(12);
			cout << " | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << endl;
		}

		else // если ац, бц, сц равны нулю, то F целочисленное
		{
			cout.width(12);
			cout << " | " << setw(68) << x << setw(8) << " | " << setw(8) << setprecision(3) << int(F) << setw(8) << " | " << endl;
			cout.width(12);
			cout << " | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << endl;
		}


	}

	return 0;

}