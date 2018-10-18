#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int n = 2; //kolichestvo elem ^2 massiva
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

int main()
{
	cout << "Vvedite znacheniya elementov massiva: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
		
	vivodmas();

	return 0;
}