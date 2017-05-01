//If you are trying to hack me I wish you can get it, Good Luck :D. I am such a noob
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long double ld;
typedef long long ll;
typedef pair<ld,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const ld  PI  = acos(-1);

int n, k;
ld r[MAX], h[MAX];
int mrk[MAX];

ld calc (int i) {
    return (2. * PI * r[i] * h[i] + PI * r[i] * r[i]);  
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
	memset(r, 0, sizeof(r));
	memset(h, 0, sizeof(h));
	memset(mrk, 0, sizeof(mrk));
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
	    cin >> r[i] >> h[i];
	}
	
	ld resp = 0;
	set<ld> R;
	debug ("Caso %d\n\n", T);
	
	for (int j = 0; j < k; j++) {
	    ld cur = 0;
	    int id = -1;

	    for (int i = 0; i < n; i++) {	
		if (mrk[i]) {
		    continue;
		}
		
		auto it = R.lower_bound(r[i]);

		ld topo = 0;
		
		if (it == R.end()) {
		    if (it != R.begin()) {
			--it;
			topo = PI * r[i] * r[i] - PI * (*it) * (*it);
		    } else {
			topo = PI * r[i] * r[i];
		    }		    
		}
		ld A = 2 * PI * h[i] * r[i] + topo;

		if (A > cur) {
		    cur = A;
		    id = i;
		}
	    }

	    debug ("Usei %d\n", id);
	    
	    resp += cur;
	    mrk[id] = 1;
	    R.insert(r[id]);
	}
	debug ("\n");
	cout << "Case #" << T << ": "; 
	cout << fixed << setprecision(10) << resp << '\n';
    }
    
}

