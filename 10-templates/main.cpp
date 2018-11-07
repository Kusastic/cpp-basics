#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

template <class typ>
int matrix(string vfile);

template<class typ>
void vivodmas(typ **a, int n);

template<class typ>
int proizv(typ **a, int n);

template<class typ>
typ maxsumdiag(typ **a, int n);

int main()
{
	int typedata;
	cout << "what data type do you want to use? \n";
	cout << "1-int, 2-float, 3-double \n";
	cin >> typedata;

	if (typedata == 1)
		matrix<int>("int.txt");
	else if (typedata == 2)
		matrix<float>("float.txt");
	else if (typedata == 3)
		matrix<double>("double.txt");
	else
	{
		cout << "Error!!";
		return 0;
	}
	return 0;
}

template <class typ>
int matrix(string vfile)
{
	ifstream fin(vfile);
	if (!fin.is_open())
	{
		cout << "Error!! Something went wrong!\n";
		return 0;
	}

	int n;
	cout << "(n = kolichestvo strok ^2 in matrix)\n";
	cout << "Enter 1 <= n <=10: ";
	cin >> n;

	typ **a = new typ*[n];

	for (int i = 0; i < n; i++)
		a[i] = new typ[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> a[i][j];

	fin.close();

	vivodmas(a, n);

	proizv(a, n);
	typ sum = maxsumdiag(a, n);
	if (!(sum == -1000))
	{
		cout << fixed;
		cout.precision(4);
		cout << setw(32) << "Max sum of diagonals in array: " << sum;
	}

	for (int i = 0; i < n; i++) //cleaning services
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}

template<class typ>
void vivodmas(typ **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(5) << a[i][j] << setw(5);
		cout << endl;
	}
}

template<class typ>
int proizv(typ **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		typ przvd = a[i][0], part = 1;

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
			cout << fixed;
			cout.precision(4);
			cout << setw(22) << "Proizvedenie stroki: " << i + 1;
			cout << " = " << przvd << endl;
			//i+1 because array starts with 0
		}
	}
	return 0;
}

template<class typ>
typ maxsumdiag(typ **a, int n)
{
	typ sum = -1000;

	for (int i = 1; i < n; i++)
	{
		typ sum1 = 0, sum2 = 0;

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