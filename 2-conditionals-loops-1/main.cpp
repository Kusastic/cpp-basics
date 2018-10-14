#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double a, b, c, x, xn, xk, dx, F;
	const double eps = 1e-5;

	cout << "Vvedite znachenie a: " << endl;
	cin >> a;
	cout << "Vvedite znachenie b: " << endl;
	cin >> b;
	cout << "Vvedite znachenie c: " << endl;
	cin >> c;
	cout << "Vvedite znachenie xn: " << endl;
	cin >> xn;
	cout << "Vvedite znachenie xk: " << endl;
	cin >> xk;
	cout << "Vvedite znachenie dx: " << endl;
	cin >> dx;
	cout << endl;

	if ((fabs(xn - xk) < eps) || (fabs(dx) < eps))
	{
		cout << "Dannie vvedeni neverno" << endl;
		return 0;
	}
		
    cout << setw(12) << " | " <<  "- - - - - - -"   << " | "  <<
	"- - - - - - -"  << " | " << endl; 
	cout << setw(12) << " | " << setw(8) << "X " << setw(8) <<  " | "
	<<	setw(8) << setprecision(3) << "F " << setw(8) << " | " << endl; 	
	cout << setw(12) << " | "  << "- - - - - - -"  << " | "  <<
	"- - - - - - -"  << " | " << endl; 	
	
	for (x = xn; x < xk; x += dx) {

		if ((c < 0) && (fabs(x) > eps)) F = -a * x - c;
		if ((c > 0) && (fabs(x) < eps)) F = (x - a) / -c;
		else if (fabs(a-c) > eps)
		F = b*x / (c - a);
		{	cout << setw(12) << " | " << setw(8) << x;

			if (int(a) || int(b) || int(c) != 0)
			{
				cout << setw(8) << " | "
				<< setw(8) << F << setw(8) << " | " << endl;
			}

			else // elsi ac, bc, cc ravni 0, to F celochislennoe
			{
				cout << setw(8) << " | " << setw(8) << setprecision(3) <<
				int(F) << setw(8) << " | " << endl;
			}

			cout << setw(12) << " | " << "- - - - - - -" << " | " <<
				"- - - - - - -" << " | " << endl;
		}
	}

	return 0;

}