#include <bits/stdc++.h>
using namespace std;

int const N = 1e3 + 10;

vector <string> vec, answer;

map <char, string> START, END;

void solve (int ini, int fim, char type)
{
	answer.push_back (START[type]);

	for (int i = ini; i <= fim; i++)
		vec[i].pop_back();

	for (int i = ini; i <= fim; i++)
	{
		int j = i;

		if (vec[i].back() != '*' && vec[i].back() != '#')
		{
			reverse (vec[i].begin(), vec[i].end());

			answer.push_back ("<li>");
			answer.push_back (vec[i]);
			answer.push_back ("</li>");

			continue;
		}

		while (j <= fim && vec[j].back() == vec[i].back())
			j++;

		if (i + 1 == j)
		{
			reverse (vec[i].begin(), vec[i].end());
			answer.push_back ("<li>");
			answer.push_back (vec[i]);
			answer.push_back ("</li>");
			continue;
		}

		answer.push_back ("<li>");
		solve (i, j - 1, vec[i].back());
		answer.push_back ("</li>");

		i = j - 1;

	}

	answer.push_back (END[type]);
}

int main() 
{
	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	START['*'] = "<ul>";
	END['*'] = "</ul>";

	START['#'] = "<ol>";
	END['#'] = "</ol>"; 

	string S;
	while (cin >> S)
	{
		reverse (S.begin(), S.end());
		vec.push_back (S);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].back() != '*' && vec[i].back() != '#')
		{
			reverse (vec[i].begin(), vec[i].end());
			answer.push_back (vec[i]);
			continue;
		}

		int j = i;

		while (j < vec.size() && vec[j].back() == vec[i].back())
			j++;

		if (i + 1 == j)
		{
			reverse (vec[i].begin(), vec[i].end());
			answer.push_back (vec[i]);
			continue;
		}

		solve (i, j - 1, vec[i].back());

		i = j - 1;
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';

	return 0;
}