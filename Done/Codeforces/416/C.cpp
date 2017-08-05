//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX], dp[MAX];
int qtd[MAX][MAX];
int p[MAX], mrk[MAX];
int t = 0;


int main() {
    memset(p, INF, sizeof(p));
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d", a + i);
	for (int j = 0; j < MAX; j++) qtd[j][i] = qtd[j][i - 1];
	qtd[a[i]][i]++;
	p[a[i]] = min(p[a[i]], i);
    }
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
	dp[i] = max(dp[i], dp[i - 1]);

	if (qtd[a[i]][i] == qtd[a[i]][n]) {
	    int cur = 0;

	    memset(mrk, 0, sizeof(mrk));
	    int ini = p[a[i]];
	    for (int j = i; j >= ini; j--) {
		if (mrk[a[j]] == 0 && (qtd[a[j]][j] - qtd[a[j]][ini - 1]) != qtd[a[j]][n]) {
		    cur = 0;
		    break;
		}
		mrk[a[j]] = 1;
		if ((qtd[a[j]][j] - qtd[a[j]][ini - 1]) == qtd[a[j]][n]) cur ^= a[j];
	    }
	    
	    
	    //debug("==> %d +++ ", cur);
	    dp[i] = max(dp[i], dp[p[a[i]] - 1] + cur);
	}
	
	//debug("--> %d\n", dp[i]);
    }

    int cur = 0;
    
    for (int i = 0; i < MAX; i++) if (p[i] != INF) cur ^= i;
    dp[n] = max(dp[n], cur);
    printf("%d\n", dp[n]);
}
