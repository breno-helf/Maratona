#include <bits/stdc++.h>
using namespace std;

int const N = 4e3 + 10;

typedef pair <int, int> pii;

int n, k;
vector <int> W[N];

bool cmp (pii A, pii B)
{
	return (A.first > B.first);
}

int total;
long long sum;

void solve ()
{
	vector <pii> p;

	for (int i = 1; i <= 4000; i++)
	{
		sort (W[i].begin(), W[i].end());
		reverse (W[i].begin(), W[i].end());

		if (!W[i].empty())
			p.push_back (pii (W[i].size(), i));
	}

	if ((int) (p.size()) < k)
		return;

	sort (p.begin(), p.end(), cmp);

	int lowerBoundSize = p[k - 1].first;
	
	vector <long long> sums;

	for (int i = 0; i < p.size(); i++)
	{
		if (p[i].first < lowerBoundSize)
			break;

		int mass = p[i].second;

		long long add = 0;
		for (int k = 0; k < lowerBoundSize; k++)
			add += W[mass][k];

		sums.push_back (add);
	}

	sort (sums.begin(), sums.end());
	reverse (sums.begin(), sums.end());

	total = lowerBoundSize;
	for (int i = 0; i < k; i++)
		sum += sums[i];
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int w, cost;
		cin >> w >> cost;

		W[w].push_back (cost);
	}

	solve ();

	cout << total << " " << sum << '\n';

	return 0;
}