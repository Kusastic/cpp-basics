#include <iostream>
#include <iomanip>

using namespace std;

const int n = 10;
int a[n] = { -10, 1, -4, -2, 0 , 1, 6, 3, -9, 5 };

void arrayout()
{
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << setw(3);
	cout << endl;
}

int sum()
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			sum += a[i];
	}

	return sum;
}

int findmin()
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

int findmax()
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

int negativesum(int min, int max)
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

void removearray()
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

int main()
{
	int sumofodd = sum();
	cout << "Summa nechetnich elementov massiva: " << sumofodd << endl;

	int min = findmin();
	int max = findmax();
	int negsum = negativesum(min, max);
	if ((negsum >= 0) || (min == max))
		cout << "There is no elements between min&max " << endl;
	else
		cout << "Sum of elements between first&last negative elements of array: " << negsum << endl;

	removearray();
	cout << "Changed array: ";
	arrayout();

	return 0;
}