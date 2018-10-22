#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int n = 10; //kolichestvo elem massiva
int a[n] = {-4, -3, -2, -1, 0 , 1, 2, 3, 4, 5};

void vivodmas()
{
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << setw(3);
	cout << endl; 
}

void summa()
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			sum += a[i];
	}

	cout << "Summa nechetnich elementov massiva: " << sum << endl;
}

int min = 0, minind; //min chislo kot budet > lubogo drugogo otr chisla v mas

int poiskmin()
{
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
	
	return min, minind;
} 

int max = -1000, maxind; //max otricat chislo kot budet < lubogo drugogo otr chisla v mas

int poiskmax()
{
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

	
	return max, maxind;
}

void otricsum()
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if ((a[i] >= min) && (a[i] <= max))
			sum += a[i];
	}
	sum -= (max + min); //Vichitaem iz summi min i max otr element

	if ((sum >= 0) || (min == max))
		cout << "Ne syshestvyet elementov mejdy min i max otric element" << endl;
	else 
        cout << "Summa elementov mejdy pervim i poslednim otricatel'nim elementom massiva: " << sum << endl;
}

void szatmas()
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
	summa();
    poiskmin();
    poiskmax();
    otricsum(); 

	cout << "Original array: ";
	vivodmas();
		
	szatmas();

	cout << "Changed array: ";
	vivodmas();

	return 0;
}