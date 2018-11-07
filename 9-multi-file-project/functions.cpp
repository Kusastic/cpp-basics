#include <iostream>
#include <iomanip>

using namespace std;

void arrayout(int*a, const int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << setw(3);
	cout << endl;
}

int sum(int*a, const int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			sum += a[i];
	}

	return sum;
}

int findmin(int*a, const int n)
{
	int min = 0, minind = 0;

	for (int i = 0; i < n; i++)

		if ((a[i] <= min) && (a[i] < 0))
		{
			minind = i;
			min = a[minind];
		}

	if (min != 0)
		cout << "Min - element: " << min << endl;

	else
	{
		cout << "Ne syshestvuet min otricatel'nogo elementa" << endl;
		return 0;
	}

	return min;
}

int findmax(int*a, const int n)
{
	int max = -1000, maxind = 0;

	for (int i = 0; i < n; i++)

		if ((a[i] >= max) && (a[i] < 0))
		{
			maxind = i;
			max = a[maxind];
		}

	if (max != -1000)
		cout << "Max - element: " << max << endl;

	else
	{
		cout << "Ne syshestvuet max otricatel'nogo elementa" << endl;
		return 0;
	}


	return max;
}

int negativesum(int*a, const int n, int min, int max)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if ((a[i] >= min) && (a[i] <= max))
			sum += a[i];
	}
	sum -= (max + min); //Vichitaem iz summi min i max otr element

	return sum;
}

void removearray(int*a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i]) <= 1)
			a[i] = 0;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] == 0)
			{
				a[j] = a[j + 1];
				a[j + 1] = 0;
			}
		}
	}
}