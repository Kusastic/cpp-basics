#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	char glansije[] = { 'E', 'Y', 'U', 'I', 'O', 'e', 'y', 'u', 'i', 'o' };

	ifstream fin("text.txt");
	if (!fin.is_open())
	{
		cout << "Error!! Something went wrong!\n" << endl;
		return 0;
	}

	cout << "Slova nachinaushiesya s glasnih bukv: \n";

	while (getline(fin, str))
	{
		for (unsigned int i = 0; i < str.length(); i++)
			if (find(glansije, glansije + 10, str[i]) != (glansije + 10))
				if ((i == 0) || ((str[i - 1] == ' ') && (i > 0)))
				{
					while (isalpha(str[i]))
						cout << str[i++];
					cout << endl;
				}
	}

	fin.close();

	return 0;
}