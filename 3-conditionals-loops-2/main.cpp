#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{	const int MaxIter = 500;
	double y, T, xk, xn, dx, eps;
	int n ;

	cout << "Vvedite znachenie xn > -1: ";
	cin >> xn;
	cout << "Vvedite znachenie xk <= 1: ";
	cin >> xk;
	cout << "Vvedite znachenie dx: ";
	cin >> dx;
	cout << "Vvedite znachenie tochnosti eps > 0 : ";
	cin >> eps;

	if ((xn < -1) || (xn > 1) || (xk < -1) || (xk > 1)
	|| (fabs(dx) < eps ) || (eps <= 0))
	{
		cout << "Wrong data!"
		<< endl;
		return 0; 
	}

	else

	{	cout << setw(12) << " | " << "- - - - - - -" << " | " <<
	"- - - - - - -" << " | " << "- - - - - - -" << " | " << "- - - - - - -" <<
	" | " << endl;
	cout << setw(12) << " | " << setw(8) << "X " << setw(8) << " | " <<
	setw(8) << "F " << setw(8) << " | " <<	setw(8) << "F2" << setw(8) <<
	" | " << setw(8) << "Iterations " << setw(5) << " | " << endl;
	cout << setw(12) << " | " << "- - - - - - -" << " | " << "- - - - - - -" <<
		" | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << endl;
	}

	for (; xn <= xk; xn += dx)
	{	y = 0.0; //nachal'noe znachenie summi
		T = 1.0; //=1 tak kak budem * ego
		
		for (n = 0; fabs(T) > eps; n++)
		{ 	T *= log(xn + 1);
			y += T; // + chlena ryada k summe
		}

		if (n < MaxIter)
		{	cout << setw(12) << " | " << setw(8) << xn << setw(8) << " | " <<
		setw(8) << setprecision(4) << fixed << y << setw(8) << " | " << setw(8) <<
		setprecision(4) << fixed << log (xn + 1) << setw(8) << " | " << setw(8) << n <<
		setw(8) << " | " << endl;
		cout << setw(12) << " | " << "- - - - - - -" << " | " <<
		"- - - - - - -" << " | " << "- - - - - - -" << " | " << "- - - - - - -" <<
		" | " << endl;
		}
		else
			cout << setw(12) << "MaxIter!!!" << endl;
	}
	return 0;
}