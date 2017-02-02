#include <bits/stdc++.h>
using namespace std;

int const N = 1e2 + 10;

int n, m;

char s[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int solve ()
{
	int topArea = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			topArea += (s[i][j] != '0');

	int ans = (2 * topArea);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int A = s[i][j] - '0';

			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];

				if (x < 0 || y < 0 || x >= n || y >= m)
				{
					ans += A;
					continue;
				}

				int B = s[x][y] - '0';

				if (A < B)
					ans += (B - A);
			}
		}

	return ans;
}

int main ()
{
	cin.sync_with_stdio (false);

	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> s[i][j];

	cout << solve() << '\n';

	return 0;
}