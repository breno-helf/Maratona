#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int n;

multiset <int> Set;

vector <pii> P;

long long solve ()
{
	sort (P.begin(), P.end());

	long long ans = 0;
	long long lastDay = -1;

	for (int i = 0; i < n; i++)
	{
		int j = i;

		while (j < n && P[i].first == P[j].first)
		{
			Set.insert (P[j].second);
			j++;
		}
 
		lastDay = P[i].first;

		if (j < n)
		{
			int D = P[j].first - P[i].first;

			while (!Set.empty() && D)
			{
				int leastDay = *Set.begin();
				Set.erase (Set.begin());

				if (D >= leastDay)
				{
					D -= leastDay;
					lastDay += leastDay;
					ans += lastDay;
				}
				else
				{
					leastDay -= D;
					Set.insert (leastDay);
					D = 0;
				}
			}
		}

		i = j - 1;
	}

	while (!Set.empty())
	{
		int leastDay = *Set.begin();
		Set.erase (Set.begin());

		lastDay += leastDay;
		ans += lastDay;
	}

	return ans;
}

int main ()
{
	ifstream cin ("pulp.in");
	ofstream cout ("pulp.out");

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int r, p;
		cin >> r >> p;

		P.push_back (pii (r, p));
	}

	cout << solve () << '\n';
	return 0;
}