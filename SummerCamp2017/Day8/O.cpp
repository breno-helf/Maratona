#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 52;
const int MAXVAL = 5e4+10;
const int MAXK = 12;
const int MAX = 50002;

int n, m;
int v[MAXN];
ll dp[MAXN][MAXK][MAX];

ll f(int i, int k, int sum) {
    if (sum >= MAX) sum = MAX-1;
	if (k == 0) return 1;
	if (i >= n) return 0;
	if (k == 1 && v[i] >= sum) return 0;
	if (dp[i][k][sum] != -1) return dp[i][k][sum];
	return (dp[i][k][sum] = f(i+1, k, sum) + f(i+1, k-1, sum + v[i]));
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", v+i);
	sort(v, v+n);
	scanf("%d", &m);

	printf("%lld\n", f(0, m, 0));
}
