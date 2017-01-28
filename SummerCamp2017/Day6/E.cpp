#include <bits/stdc++.h>
using namespace std;

int const maxN = 1e3 + 10;

int N;
long long a[maxN];

int dp[maxN];
long long DP[maxN];

int solve ()
{
	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		DP[i] = a[i];

		for (int j = i - 1; j >= 1; j--)
		{

			if (a[i] <= DP[j])
				continue;

			if (dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				DP[i] = DP[j] + a[i];
			}
			else if (dp[j] + 1 == dp[i] && DP[j] + a[i] < DP[i])
				DP[i] = DP[j] + a[i];
		}

		ans = max (ans, dp[i]);
	}

	return ans;
}

int main ()
{
		cin.sync_with_stdio (false);
		cin.tie (0);
		cout.tie (0);

		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> a[i];

		sort (a + 1, a + 1 + N);

		cout << solve () << '\n';

		return 0;
}