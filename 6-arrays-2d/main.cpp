#include <iostream>
#include <iomanip>

using namespace std;

void vivodmas(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << a[i][j] << setw(3);
		cout << endl;
	}
}

void proizv(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int przvd = a[i][0], part = 1;

		for (int j = 0; j < n-1; j++)
		{
			if ((a[i][j] > 0) && (a[i][j + 1] > 0))
			{
				part = a[i][j + 1];
				przvd *= part;
			}
			else
			{
				przvd = 0;
				break;
			}
		}

		if (przvd > 0)
		{
			cout << setw(22) << "Proizvedenie stroki: " << i + 1;
			cout << " = " << przvd << endl;
			//i+1 because array starts with 0
		}		
	}
}

int maxsumdiag(int **a, int n)
{
int sum = -1000;

for (int i = 1; i < n; i++)
{
	int sum1 = 0, sum2 = 0;

	for (int j = 0, k = j; j < n - i; j++, k++)
	{
		sum1 += a[j + i][k];
		sum2 += a[j][k + i];
	}

	if (sum1 >= sum)
		sum = sum1;
	if (sum2 >= sum)
		sum = sum2;
}
	return sum;
}

 int main()
 {
	int n;
	cout << "Vvedite kolichestvo elements of array ^2 : ";
		 cin >> n;
	if (n <= 0)
		 {
			 cout << "Wrong data!!!";
			 return 0;
	     }

	 int **a = new int* [n];
	 
	 for (int i = 0; i < n; i++)
	 {
		 a[i] = new int[n];
	 }

	cout << "Vvedite znacheniya elements of array: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	cout << endl;

	vivodmas(a, n);

	proizv(a, n);
	int sum = maxsumdiag(a, n);
	if (!(sum == -1000))
	cout << setw(32) << "Max sum of diagonals in array: " << sum;

	for (int i = 0; i < n; i++) //cleaning services
	{
		delete [] a[i] ;
	}
	delete[] a;

	return 0;
}