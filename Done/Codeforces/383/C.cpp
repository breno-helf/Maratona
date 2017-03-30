#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
int c[MAX], mrk[MAX];
int ind[MAX], cyc, resp;
bool ok = true;
set<int> s;

void dfs (int u) {
    mrk[u] = 1;
    cyc++;
    if (!mrk[c[u]])
	dfs(c[u]);
}

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main () {
    resp = 1;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf ("%d", c + i);
	ind[c[i]]++;
    }

    for (int i = 1; i <= n; i++) if (ind[i] > 1) ok = false;

    if (!ok) {
	puts("-1");
	return 0;
    }

    for (int i = 1; i <= n; i++) {
	if (!mrk[i]) {
	    cyc = 0;
	    dfs (i);
	    if (cyc % 2 == 0) cyc /= 2;
	    s.insert(cyc);
	}	
    }
    int f = *s.begin();
    s.erase(s.begin());
    for (int e : s)
        f = (f * e) / gcd(f, e);

    resp = f;
    printf("%d\n", resp);
    return 0;
}

