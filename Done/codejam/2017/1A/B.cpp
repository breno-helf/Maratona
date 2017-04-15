//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 60;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, p;
ll R[MAX];
ll q[MAX][MAX];

bool test (int i, ll qtd, ll num) {
    if (qtd == 0) return true;
    return (9 * R[i] * qtd <= 10 * num && 10 * num <= 11 * R[i] * qtd);
}



int main () {
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
	cin >> n >> p;
	vector<int> item;
	
	
	for (int i = 1; i <= n; i++)
	    cin >> R[i];

	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= p; j++) {
		cin >> q[i][j];
	    }
	}
	
	for (int i = 1; i <= p; i++) {
	    item.pb(i);
	}

	cout << "Case #" << T << ": ";
	
	if (n == 0) {
	    ll resp = 0;
	    for (int i = 1; i <= p; i++) {
		ll l = 0;
		ll s = (q[1][i] / R[1]);
		for (ll k = max(1LL, s - 10); k <= (s + 10); k++) {
		    if (test (1, k, q[1][i])) l = 1;
		}
		
		resp += l;
		debug ("\n\nConsegui %d ratatulli cm o pacote %d\n\n", l, i);
	    }
	    cout << resp << '\n';
	} else if (n == 2) {
	    ll best = 0;
	    do {
		ll cur = 0;
		
		for (int i = 1; i <= p; i++) {
		    ll l = 0;
		    ll s = min((q[1][i] / R[1]), q[2][item[i - 1]] / R[2]);
		    ll e = max((q[1][i] / R[1]), q[2][item[i - 1]] / R[2]);
		    for (ll k = max(1LL, s - 10); k <= e + 10; k++) {
			if (test (1, k, q[1][i]) && test(2, k, q[2][item[i - 1]])) l = k;
		    }
		    debug ("%d - ", l);
		    cur += (l > 0) ? 1 : 0;
		}
		debug ("\n");
		best = max(best, cur);
	    } while (next_permutation(item.begin(), item.end()));

	    cout << best << '\n';
	} else {
	    map<int, int> K, M[MAX];
	    ll resp = 0;

	    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= p; j++) {
		    ll s = roundl ((long double)(q[i][j]) / (long double) (R[i]));
		    debug (">> Try with %lld\n\n", s);
		    for (int k = max(s - 1, 1LL); k <= s; k++) {
			if (test(i, k, q[i][j])) {
			    debug ("    %lld can do with %d\n", q[i][j], k);
			    M[i][k]++;
			    K[k] = 1;
			}
		    }
		}
	    }

	    for (auto e : K) {
		int mn = INF;
		for (int i = 1; i <= n; i++) {
		    mn = min(M[i][e.first], mn);
		}
		resp += mn;
	    }

	    cout << resp << '\n';
	}
	
    }
}

