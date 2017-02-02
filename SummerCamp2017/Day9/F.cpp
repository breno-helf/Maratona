#include <bits/stdc++.h>
using namespace std;

int const N = 1e2 + 10;

int n, f;

int e[N];

vector <int> T;
bool mrk[N];

int findNext ()
{
	int pos = 1;

	while (pos <= n && mrk[pos])
		pos++;

	return pos;
}

int findInList (int Floor)
{
	for (int i = 1; i <= n; i++)
		if (!mrk[i] && e[i] == Floor)
			return i;

	return -1;
}

void solve ()
{
	int curFloor = f;

	while (true)
	{
		int pos = findNext ();

		if (pos == n + 1)
			return;

		if (curFloor <= e[pos]) // go up
		{
			while (curFloor <= e[pos])
			{
				int P = findInList (curFloor);

				if (P != -1)
				{
					T.push_back (curFloor);
					mrk[P] = true;
				}

				curFloor++;
			}

			curFloor = e[pos];
		}
		else // go down
		{
			while (e[pos] <= curFloor)
			{
				int P = findInList (curFloor);

				if (P != -1)
				{
					T.push_back (curFloor);
					mrk[P] = true;
				}

				curFloor--;
			}

			curFloor = e[pos];
		}
	}
}

int main ()
{
	cin.sync_with_stdio (false);

	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin >> n >> f;

	for (int i = 1; i <= n; i++)
		cin >> e[i];

	solve();

	for (int i = 0; i < n; i++)
		cout << T[i] << " ";
	cout << '\n';

	return 0;
}