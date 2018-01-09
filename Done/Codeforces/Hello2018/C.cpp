//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 32;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll  MOD = 1000000007;

int n, L;
ll c[MAX];
ll cost[MAX];
ll acc[MAX];

int main() {
    for (int i = 0; i <= 30; i++) {
	c[i] = cost[i] = INF;
    }
    
    cin >> n >> L;
    
    for (int i = 0; i < n; i++) {
	cin >> c[i];	
    }

    for (int i = 0; i <= 30; i++) {
	ll cur = c[i];
	for (int j = 0; j <= 30; j++) {
	    cost[j] = min(cost[j], cur);
	    if (j >= i) cur *= 2LL;
	    if (cur > INF) break;
	}
    }

    for (int i = 0; i <= 30; i++) {
	if ((1<<i) & L) {
	    acc[i] += cost[i];
	    debug("--> (%d) comprei %d por %lld\n", i, (1<<i), cost[i]);
	}
	if (i > 0) acc[i] += acc[i - 1];
    }
    
    ll resp = acc[30];

    debug("--> %lld\n", resp);
    
    for (int i = 1; i <= 30; i++) {
	if (!((1<<i) & L)) {
	    if (cost[i] < acc[i]) {
		debug("Troquei todos antes de %d (%lld -- %lld)\n", i, cost[i], acc[i]);
		resp = resp + (cost[i] - acc[i]);
		for (int j = i + 1; j <= 30; j++) {
		    acc[j] = acc[j] + (cost[i] - acc[i]);
		}
	    }
	}
    }

    cout << resp << '\n';
    
}

