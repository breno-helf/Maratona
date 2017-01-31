#include <bits/stdc++.h>
using namespace std;

int const N = 2e5 + 10;

int n;

typedef pair <int, int> pii;

vector <pii> dragons;

int seg [4 * N];
int lazy [4 * N];

void refresh (int idx, int i, int j)
{
	if (!lazy [idx])
		return;

	int left = idx << 1;
	int right = left | 1;

	if (i != j)
	{
		lazy[left] += lazy[idx];
		lazy[right] += lazy[idx];
	}

	seg[idx] -= lazy[idx];
	lazy[idx] = 0;
}

void change (int idx, int i, int j, int ini, int fim)
{
	refresh (idx, i, j);

	if (i > j || j < ini || fim < i)
		return;

	if (ini <= i && j <= fim)
	{
		lazy[idx]++;
		refresh (idx, i, j);
		return;
	}

	int mid = (i + j) >> 1;
	int left = idx << 1;
	int right = left | 1;

	change (left, i, mid, ini, fim);
	change (right, mid + 1, j, ini, fim);

	seg[idx] = min (seg[left], seg[right]);
}

void update (int idx, int i, int j, int pos, int value)
{
	refresh (idx, i, j);

	if (i == j)
	{
		seg[idx] = value;
		return;
	}

	int mid = (i + j) >> 1;
	int left = idx << 1;
	int right = left | 1;

	if (pos <= mid)
		update (left, i, mid, pos, value);
	else
		update (right, mid + 1, j, pos, value);

	seg[idx] = min (seg[left], seg[right]);
}

int get (int idx, int i, int j, int ini, int fim)
{
	refresh (idx, i, j);

	if (i > j || j < ini || fim < i)
		return INT_MAX;

	if (ini <= i && j <= fim)
		return seg[idx];

	int mid = (i + j) >> 1;
	int left = idx << 1;
	int right = left | 1;

	return min (get (left, i, mid, ini, fim), get (right, mid + 1, j, ini, fim));
}

bool cmp (pii A, pii B)
{
	return (A.first > B.first);
}

long long totalGold;
vector <int> ans;

void solve ()
{
	sort (dragons.begin(), dragons.end(), cmp);

	for (int i = 0; i < dragons.size(); i++)
	{
		int Gold = dragons[i].first;
		int pos = dragons[i].second;

		int menor = get (1, 1, n, pos, n - 1);

		if (menor > 1)
		{
			totalGold += Gold;
			ans.push_back (pos);

			change (1, 1, n, pos, n);
		}
	}

	if (get (1, 1, n, n, n) > 0)
	{
		totalGold = -1;
		ans.clear ();
	}
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin >> n;

	for (int i = 1; i <= n -1; i++)
	{
		char c;
		cin >> c;

		int values;
		cin >> values;

		if (c == 'd')
		{
			update (1, 1, n, i + 1, INT_MAX);
			dragons.push_back (pii (values, i + 1));
		}
		else
			update (1, 1, n, i + 1, values);
	}

	solve ();

	cout << totalGold << '\n';

	if (totalGold != -1)
	{
		cout << ans.size() << '\n';

		sort (ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";

		cout << '\n';
	}

	return 0;
}