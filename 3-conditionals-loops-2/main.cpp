#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{	const int MaxIter = 500;
	double y, T, xk, xn, dx, eps;
	int n;

	cout << "Znachenie -1 > x >= 1 !!! \n";
	cout << "Vvedite znachenie xn: ";
	cin >> xn;
	cout << "Vvedite znachenie xk: ";
	cin >> xk;
	cout << "Vvedite znachenie dx: ";
	cin >> dx;
	cout << "Vvedite znachenie tochnosti eps > 0 : ";
	cin >> eps;

	if ((xn < -1) || (xn > 1) || (xk < -1) || (xk > 1)
		|| (fabs(dx) < eps) || (eps <= 0))
	{
		cout << "Wrong data!" << endl;
		return 0;
	}

	else

	cout << "| - - - - - - - | - - - - - - - |" ;
	cout << " - - - - - - - | - - - - - - - |\n" ;
	cout << "|       X       |  F (series)   |";
	cout << " F (in-built)  |  Iterations   |\n";
	cout << "| - - - - - - - | - - - - - - - |";
	cout << " - - - - - - - | - - - - - - - |\n";

	for (; xn <= xk; xn += dx)
	{	y = 0.0; //nachal'noe znachenie summi
		T = 1.0; //=1 tak kak budem * ego
		
		for (n = 0; fabs(T) > eps; n++)
		{ 	T *= (pow(-1, n) * pow(xn, n+1))/(n+1);
			y += T; // + chlena ryada k summe
		}

		if (n < MaxIter)
		{	cout << fixed;
			cout.precision(3);

			cout << " | " << setw(8) << xn << setw(7) << " | " ;
			cout << setw(8) << y << setw(8) << " | ";
			cout << setw(8) << log(xn + 1) << setw(8) << " | ";
		    cout << setw(8) << n << setw(9) << " | \n";
		}
		else
		{
			cout << "MaxIter!!!" << endl;
			return 0;
		}
	}
	cout << " | " << "- - - - - - -" << "| " << "- - - - - - -" << " | " <<
		"- - - - - - -" << " | " << "- - - - - - -" << " | " << endl;
	return 0;
}