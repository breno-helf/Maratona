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
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll pot[MAX], a[MAX];
ll n;
int t;

int main () {
    pot[0] = 1;
    for (int i = 1; i < MAX; i++) {
	pot[i] = pot[i - 1] * 2;
	pot[i] %= MOD;
    }
    
    scanf("%d", &t);
    for (int c = 0; c < t; c++) {
	ll p = INF, g = -1;
	ll str, seq;
	str = seq = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
	    scanf("%lld", a + i);
	    p = min(p, a[i]);
	    g = max(g, a[i]);	    
	}
	if (p == g) {
	    str = (n * (n + 1)) / 2;
	    seq = pot[n] - 1;
	    str %= MOD;
	    seq %= MOD;
	    printf("%lld %lld\n", str, seq);
	    continue;
	}
	
	vector<int> mn, mx;
	for (int i = 0; i < n; i++) {
	    if (a[i] == p) mn.pb(i);
	    if (a[i] == g) mx.pb(i);
	}
	sort(mn.begin(), mn.end());
	sort(mx.begin(), mx.end());
	
	for (int i = n - 1; i >= 0; i--) {
	    auto lastmn = lower_bound(mn.begin(), mn.end(), i);
	    auto lastmx = lower_bound(mx.begin(), mx.end(), i);
	    if (lastmn != mn.end() && lastmx != mx.end())
		str += n - max(*lastmn, *lastmx);	    
	}
	
	
	seq += (pot[mx.size()] - 1) * (pot[mn.size()] - 1);
	seq %= MOD;
	seq *= (pot[n - mx.size() - mn.size()]);
	seq %= MOD;
	str %= MOD;

	printf("%lld %lld\n", str, seq);	
    }

}

