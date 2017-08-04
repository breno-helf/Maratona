//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2212;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll  MOD = 1000000007;

ll resp;
int n, k;
ll p, a[MAX], b[MAX];

void solve() {
    resp = INF;

    for (int i = 0; i <= k - n; i++) {
	ll cur = 0;
	for (int j = 0; j < n; j++) {
	    int x = j + i;
	    cur = max(cur, abs(a[j] - b[x]) + abs(b[x] - p));
	}
	resp = min(resp, cur);
    }
    
}

int main() {
    resp = 0;
    scanf("%d%d%lld", &n, &k, &p);

    for (int i = 0; i < n; i++) {
	scanf("%lld", a + i);
    }
    for (int i = 0; i < k; i++) {
	scanf("%lld", b + i);
    }

    sort(a, a + n);
    sort(b, b + k);
    
    solve();

    printf("%lld\n", resp);
    return 0;
}

