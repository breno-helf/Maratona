//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int MXX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k, x;
int a[MAX];
int cnt[MXX][2];
int mn, mx;

int main () {
    scanf ("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++) {
	scanf ("%d", &a[i]);
	cnt[a[i]][0]++;
    }
    int cur = 1;
    while(k--) {
	for (int i = 0; i < MXX; i++)
	    cnt[i][cur] = 0;

	int pos = 0;
	for (int i = 0; i < MXX; i++) {
	    if (cnt[i][cur ^ 1] % 2) {
		cnt[i][cur] += cnt[i][cur ^ 1] / 2 + pos;
		cnt[i ^ x][cur] += cnt[i][cur ^ 1] / 2 + !pos;
	    } else {
		cnt[i][cur] += cnt[i][cur ^ 1] / 2;
		cnt[i ^ x][cur] += cnt[i][cur ^ 1] / 2;		
	    }
	    pos += cnt[i][cur ^ 1] % 2;
	    pos %= 2;
	}
	cur ^= 1;
    }
    cur ^= 1;
    mn = INF;
    mx = -1;
    for (int i = 0; i < MXX; i++) {
	if (cnt[i][cur]) {
	    mn = min(mn, i);
	    mx = max(mx, i);
	}
    }
    printf("%d %d\n", mx, mn);
}

