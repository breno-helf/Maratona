#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll a[MAX], d[MAX], q[MAX], w[MAX], resp;
int n;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf ("%lld", a + i);
	if (i > 1)
	    d[i - 1] = abs(a[i - 1] - a[i]);
    }
    
    for (int i = 1; i < n; i++) {
	q[i] = w[i] = d[i];
	if (i % 2) q[i] *= -1;
	else w[i] *= -1;
    }
    q[1] = 0;
    resp = -INF;
    ll cur1 = 0, cur2 = 0;
    for (int i = 1; i < n; i++) {
	cur1 += q[i];
	cur2 += w[i];
	resp = max(resp, max(cur1, cur2));
	if (cur1 < 0) cur1 = 0;
	if (cur2 < 0) cur2 = 0;
    }
    printf("%lld\n", resp);
}

