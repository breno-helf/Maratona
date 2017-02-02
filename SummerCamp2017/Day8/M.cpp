#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
const int MAXN = 52;
const int MAXVAL = 1e4+10;
const int MAX = 52 * MAXVAL;

bool notprime[MAX];
int n;
vector<int> v;
int cnt[MAXVAL];
ll dp[MAXN][MAX];

int main()
{
	notprime[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (notprime[i]) continue;
		for (int k = i*2; k < MAX; k += i) {
			notprime[k] = true;
		}
	}

	scanf("%d", &n);
	for (int i = 0,a; i < n; i++) {
		scanf("%d", &a);
		if (cnt[a] == 0) {
			v.push_back(a);
		}
		cnt[a]++;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i <= v.size(); i++)
		dp[i][0] = 1;

	for (int i = int(v.size()) - 1; i >= 0; i--) {
		// printf("%d > %d\n", i, v[i]);
		for (int left = MAX-1; left > 0; left--) {
			for (int k = 0; k <= cnt[v[i]] && k * v[i] <= left; k++) {
				dp[i][left] += dp[i+1][left - k*v[i]];
			}
			// if (left <= 10)
			// 	printf("dp[%d][%d] = %d\n",i,left,dp[i][left]);
		}
	}

	ll ans = 0;

	for (int i = 2; i < MAX; i++) {
		if (notprime[i]) continue;
		ans += dp[0][i];
	}

	printf("%lld\n", ans);
}