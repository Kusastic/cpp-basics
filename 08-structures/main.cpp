#include <iostream>
#include <string>

using namespace std;

const int n = 7;

struct AEROFLOT
{
	string nameflight, planetype;
	int numberflight;
};

int main()
{
	AEROFLOT planes[n];

	cout << "Vvedite 7 tipov samoletov:";
	for (int i = 0; i < n; i++)
		cin >> planes[i].planetype;

	cout << "Vvedite 7 nomerov samoletov:";
	for (int i = 0; i < n; i++)
		cin >> planes[i].numberflight;

	cout << "Vvedite 7 naznachenij samoletov:";
	for (int i = 0; i < n; i++)
		cin >> planes[i].nameflight;	

	for (int i = 0; i < n - 1; i++)
	{		
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (planes[j].numberflight > planes[j + 1].numberflight)
			{
				int a = planes[j].numberflight;
				planes[j].numberflight = planes[j + 1].numberflight;
				planes[j + 1].numberflight = a;				
			}
		}		
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Plane " << planes[i].planetype;
		cout << " number " << planes[i].numberflight;
		cout << " is flying to " << planes[i].nameflight;
		cout << endl;
	}

	string naznachenie;
	cout << "Vvvedite naznachenie: ";
	cin >> naznachenie;
	cout << endl;

	bool flight = false;
	for (int i = 0; i < n; i++)
	{
		if (planes[i].nameflight == naznachenie)
		{
			flight = true;
			cout << "Vam podhodit ";
			cout << planes[i].planetype << " plane " ;
			cout << "number " << planes[i].numberflight;			
			cout << endl;
		}
	}

	if (flight == false)
		cout << "Vam ne podhodit ni odit samolet";	

	return 0;
}