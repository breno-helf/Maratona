//If you are trying to hack me I wish you can get it, Good Luck :D. I am such a noob
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;

int v[MAX];

int mrk[MAX];

map<int, vector<int> > A, B;

int main () {
    while (true) {
	scanf ("%d", &n);
	if (n == 0) break;

	for (auto e : A)
	    e.second.clear();
	A.clear();

	for (auto e : B)
	    e.second.clear();
	B.clear();

	memset(mrk, 0, sizeof(mrk));
	
	for (int i = 0; i < n; i++) {
	    scanf ("%d", v + i);
	    A[v[i] - i].pb(i);
	    B[v[i] + i].pb(i);
	}
	
	queue<int> Q;
	Q.push(0);
	mrk[0] = 1;
	int resp = 0;
	while (!Q.empty()) {
	    int i = Q.front();
	    resp = max(resp, i);
	    debug ("%d\n", i);
	    for (auto e : B[i - v[i]]) {		
		debug ("  ---  %d\n", e);
		
		if (e >= i) continue;
		if (!mrk[e]) {
		    mrk[e] = 1;
		    Q.push(e);
		}
	    }

	    for (auto e : A[- i - v[i]]) {		
	    	debug ("  ---  %d\n", e);
		
		if (e <= i) continue;
	    	if (!mrk[e]) {
	    	    mrk[e] = 1;
	    	    Q.push(e);
	    	}
	    }

	    
	    Q.pop();
	}
	
	debug ("Resposta:\n");
	printf ("%d\n", resp);

    }
    return 0;
}

