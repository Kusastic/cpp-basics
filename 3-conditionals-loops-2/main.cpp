#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	const int MaxIter = 500; //����������� ���������� ���������� ��������
	double y, T, xk, xn, dx, eps;
	int n ;

	cout << "Vvedite znachenie xn > -1: ";
	cin >> xn;
	cout << "Vvedite znachenie xk <= 1: ";
	cin >> xk;
	cout << "Vvedite znachenie dx: ";
	cin >> dx;
	cout << "Vvedite znachenie tochnosti e != 0: ";
	cin >> eps;

	if ((xn < -1) || (xn > 1) || (xk < -1) || (xk > 1) || (eps == 0))
	{
		cout << "X doljen prenadlejat' promejytku -1 < x <= 1 i imet' tochnost' � != 0 !!! " << endl;
		return 0; //���� ������ ������� ������� �� ��������� �� ����� �������� ������
	}

	else

	{
		cout.width(12);
		cout << " | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << endl;

		cout.width(12);
		cout << " | " << setw(8) << "X " << setw(8) << " | " << setw(8) << "F " << setw(8) << " | " << setw(8) << "Iterations " << setw(5) << " | " << endl;

		cout.width(12);
		cout << " | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << endl;
	}


	for (; xn < xk; xn += dx)
	{
		y = 0.0; //��������� �������� �����
		T = 1.0; //=1 ��� ��� �� ����� �������� ���

		for (n = 0; fabs(T) > eps; n++)
		{   

			T *= (-xn * (n + 1)) / (n + 2); //������������ ������� ��������� ������������ ����� ������������������
			y += T; //���������� ����� ���� � �����
			
		}

		
		if (n < MaxIter)
		{

			cout.width(12);
			cout << " | " << setw(8) << xn << setw(8) << " | " << setw(8) << setprecision(4) << y << setw(8) << " | " << setw(8) << n << setw(8) << " | " << endl;

			cout.width(12);
			cout << " | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << "- - - - - - -" << " | " << endl;

		}

		else
		{
			cout.width(12);
			cout << "Ryad rashoditsya!" << endl;
			break;
		}

		continue;
	}
	
	
	return 0;
}