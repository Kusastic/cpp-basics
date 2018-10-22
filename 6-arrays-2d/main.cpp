#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int n = 3; //kolichestvo elem ^2 massiva
int a[n][n];

void vivodmas()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << a[i][j] << setw(3);
		cout << endl;
	}
}

void proizv()
{
	int b, c;

	for (int i = 0; i < n; i++)
	{
		b = a[i][0];
		c = 1;

		for (int j = 0; j < n-1; j++)
		{

			if ((a[i][j] > 0) && (a[i][j + 1] > 0))
			{
				c = a[i][j + 1];
				b *= c;
			}

			else

			{
				b = 0;
				break;
			}
		}

		if (b > 0)
			cout << setw(23) << "Proizvedenie stroki  " << i << " = " << b << endl;			
	}
}

void maxsummadiag()
{
	int max = 0, n, v;

	for ()
	{
		for ()
		{

		}
	}

	cout << "Max znachenie summi znachenij diagonali: ";

	if (v >= n)
		cout << v;
	else
		cout << n;
}


int main()
{
	cout << "Vvedite znacheniya elementov massiva: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
		
	vivodmas();

	proizv();
	maxsummadiag();

	return 0;
}