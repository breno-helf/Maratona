//If you are trying to hack me I wish you can get it, Good Luck :D. I am such a noob
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int C, J;
int TEMPO[MAX];
set<pii> L;
int dp[MAX][MAX][2][2];

int solve (int i, int  k, int p, int c) {
    int &res = dp[i][k][p][c];

    if (res != -1) return res;

    if (k > 720 || (i - k) > 720) return res = INF;

    if (TEMPO[i] != -1 && TEMPO[i] != p) return res = INF;
    
    if (i == 1440) {
	if (k == 720) return res = (c != p) ? 1 : 0;
	else return res = INF;
    }
    
    if (p == 0) {
	return res = min(solve(i + 1, k + 1, p, c), 1 + solve(i + 1, k + 1, p ^ 1, c));
    } else {
	return res = min(solve(i + 1, k, p, c), 1 + solve(i + 1, k, p ^ 1, c));
    }
}


int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	memset(dp, -1, sizeof(dp));
	memset(TEMPO, -1, sizeof(TEMPO));
	cin >> C >> J;

	for (int i = 0; i < C; i++) {
	    int l, r;
	    cin >> l >> r;
	    for (int j = l; j < r; j++)
		TEMPO[j] = 1;
	}
	
	for (int i = 0; i < J; i++) {
	    int l, r;
	    cin >> l >> r;
	    for (int j = l; j < r; j++)
		TEMPO[j] = 0;
	}
	
	cout << "Case #" << t << ": ";
	
	cout << min(solve(0, 0, 0, 0), solve(0, 0, 1, 1)) << '\n';
    }
}
