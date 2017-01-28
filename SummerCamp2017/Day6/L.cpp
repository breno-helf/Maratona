#include <bits/stdc++.h>
using namespace std;

int const maxN = 5e3 + 10;

char A [maxN], B [maxN];

int dp [maxN][maxN][2];

int N, M;

int solve (int i, int j, int can)
{
	if (dp[i][j][can] == -1)
	{
		if (i >= N)
		{
			if (j >= M)
				return (dp[i][j][can] = 1);

			return (dp[i][j][can] = can);	
		}

		if (j >= M)
			return (dp[i][j][can] = 0);

		dp[i][j][can] = 0;

		if (can)
		{
				dp[i][j][can] = solve (i, j, 0);

				dp[i][j][can] = max (dp[i][j][can], solve (i, j + 1, can));
		}
		else
			if (!can)
			{
				if (A[i] != B[j])
					return (dp[i][j][can] = 0);

				dp[i][j][can] = solve (i + 1, j + 1, 0);

				if ((j + 1 < M && A[i] != B[j + 1]) || (j + 1 == M))
					dp[i][j][can] = max (dp[i][j][can], solve (i + 1, j + 1, 1));
			}
	}

	return dp[i][j][can];
}

int main ()
{
	scanf (" %s %s", A, B);

	N = strlen (A);
	M = strlen (B);

	if (M < N)
	{
		printf ("No\n");
		return 0;
	}

	memset (dp, -1, sizeof (dp));

	if (solve (0, 0, 0))
		printf ("Yes\n");
	else
		printf ("No\n");

	return 0;
}