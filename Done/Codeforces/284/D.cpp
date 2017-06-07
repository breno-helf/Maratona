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

int n, T;
int s[MAX];
double dp[MAX][MAX];
double p[MAX];

int main () {
    scanf ("%d %d", &n, &T);

    for (int i = 1; i <= n; i++) {
	scanf ("%lf %d", &p[i], &s[i]);
	p[i] *= .01;
    }
    dp[0][0] = 1;
    
    double resp = 0;

    for (int i = 1; i <= n; i++) {
	double sum = dp[i - 1][0];
	double fail = 1.0 - p[i];
	
	for (int j = 1; j <= T; j++) {
	    dp[i][j] = sum * p[i];
	    sum = sum * (1.0 - p[i]) + dp[i - 1][j];
	    if (j < s[i])
		fail *= (1.0 - p[i]);
	    else {
		sum -= dp[i - 1][j - s[i]] * fail;
		dp[i][j] += dp[i - 1][j - s[i]] * fail;
	    }
	    resp += dp[i][j];
	}
    }

    
    printf ("%lf\n", resp);

    return 0;
}
