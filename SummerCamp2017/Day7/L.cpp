#include <bits/stdc++.h>
using namespace std;

int n, T1, T2;

typedef pair <long long, long long> pii;

pii solve ()
{
	long long total = 0;

	long long T = 0;

	while (true)
	{
		T++;

		if (T % T1 == 0)
			total++;

		if (T % T2 == 0)
			total++;

		if (total >= n)
			break;
	}

	if (T % T1 != 0)
	{
		total++;
		while (T % T1 != 0)
			T++;
	}
	else
		if (T % T2 != 0)
		{
			total++;
			while (T % T2 != 0)
				T++;
		}

	return pii (total, T);
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin >> n >> T1 >> T2;

	pii p = solve ();

	cout << p.first << " " << p.second << '\n';

	return 0;

}