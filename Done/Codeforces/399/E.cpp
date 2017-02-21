//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, s[MAX], g[112];
int totalXor = 0;
set<int> halve;

int main () {
    int cnt = 0, m = 1;
    for (int i = 1; i <= 60; i++) {
	if (cnt == (m + 1)) {
	    m++;
	    cnt = 0;
	}
	g[i] = m;
	cnt++;
    }
    for (int i = 1; i <= 60; i++)
	debug("%d ", g[i]);
    debug("\n");
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf ("%d", s + i);
	totalXor ^= g[s[i]];
    }
    //debug("%d\n", totalXor);
    if (totalXor != 0)
	puts("NO");
    else
	puts("YES");
}

