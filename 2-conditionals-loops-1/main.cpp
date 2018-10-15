#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double kEps = 1e-15;

	double a, b, c, xn, xk, dx;
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

	if (dx < kEps)
	{
		cout << "\ndx vveden neverno!!!" << endl;
		return 1;
	}

	cout << setw(44) << "| - - - - - - - | - - - - - - - |\n";
	cout << setw(44) << "|       X       |       F       |\n";
	cout << setw(44) << "| - - - - - - - | - - - - - - - |\n";

	cout << fixed;
	cout.precision(3);

	double F;
	for (double x = xn; x <= xk; x += dx)
	{
		cout << setw(11) << "|" << setw(10) << x << setw(6) << "|";

		if ((c < 0) && !(abs(x) < kEps))
			F = -a * x - c;
		else if ((c > 0) && (abs(x) < kEps))
			F = (x - a) / -c;
		else
		{
			if (abs(c - a) < kEps)
			{
				cout << " division by 0 |\n";
				continue;
			}
			else
				F = b * x / (c - a);
		}

		if ((int(a) | int(b) | int(c)) != 0)
			cout << setw(10) << F << setw(7) << "|\n";
		else
			cout << setw(8) << int(F) << setw(9) << "|\n";

	}
	cout << setw(44) << "| - - - - - - - | - - - - - - - |\n";

	return 0;
}