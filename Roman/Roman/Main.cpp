#include <iostream>
#include <string.h>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

string solution(int number)
{
	int tab[7];
	tab[0] = number / 1000;
	tab[2] = (number - tab[0] * 1000) / 100;
	tab[4] = (number - tab[0] * 1000 - tab[2]*100) / 10;
	tab[6] = (number - tab[0] * 1000 - tab[2]*100 - tab[4]*10);
	string Rome = "MDCLXVI";
	vector <char> helpRoman;
	for (int i = 0; i < 7; i = i + 2)
	{
		if (tab[i] == 0)
			continue;
		if (tab[i] == 9)
		{
			helpRoman.push_back(Rome[i]);
			helpRoman.push_back(Rome[i - 2]);
		}
		else if (tab[i] == 4)
		{
			helpRoman.push_back(Rome[i]);
			helpRoman.push_back(Rome[i - 1]);
		}
		else if (tab[i] > 4)
		{
			helpRoman.push_back(Rome[i - 1]);
			for (int j = 0; j < tab[i]-5; j++)
				helpRoman.push_back(Rome[i]);
		}
		else
		{
			for (int j = 0; j < tab[i]; j++)
				helpRoman.push_back(Rome[i]);
		}
	}
	string Roman(helpRoman.begin(), helpRoman.end());
	return Roman;
}

int main()
{
	string s=solution(182);
	cout << s;
	return 0;
}

