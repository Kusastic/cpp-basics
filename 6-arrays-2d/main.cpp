#include <iostream>
#include <iomanip>
#include <fstream>

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

		for (int j = 0; j < n - 1; j++)
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
	cout << "(n = kolichestvo strok ^2 in matrix)\n";
	cout << "Enter 1 <= n <=10: ";
	
	cin >> n;

	int **a = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	ifstream fin("file.txt");
	if (!fin.is_open()) 
	{
		cout << "Error!! Something went wrong!" << endl;
		return 0;
	}	

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)		
			fin >> a[i][j];

	fin.close();

	vivodmas(a, n);

	proizv(a, n);
	int sum = maxsumdiag(a, n);
	if (!(sum == -1000))
		cout << setw(32) << "Max sum of diagonals in array: " << sum;

	for (int i = 0; i < n; i++) //cleaning services
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}