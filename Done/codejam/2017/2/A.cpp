//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


int n, p;
vector<int> G[10];

bool cmp (int a, int b) {
    return (a % p) > (b % p);
}

int main () {
    int T;
    scanf ("%d", &T);

    for (int t = 1; t <= T; t++) {
	int resp = 0;
	for (int i = 0; i < 10; i++)
	    G[i].clear();
	scanf ("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
	    int x;
	    scanf ("%d", &x);
	    if (x % p != 0) G[x % p].pb(x);
	    else resp++;
	}
	printf ("Case #%d: ", t);

	int r = 0;
	if (p == 2) {
	    resp = n;
	    resp -= (int)G[1].size() / 2;
	    printf ("%d\n", resp);
	    continue;
	}

	if (p == 4) {
	    int tam = G[1].size() + G[3].size() + G[2].size();
	    int i = 0, j = 0, v = 0;
	    for (int E = 0; E < tam; E++) {
		int cur;
		if (E % 2 == 0) {
		    if (j != (int)G[3].size()) {
			cur = G[3][j++];
		    } else if(v == (int)G[2].size()) 
			cur = G[1][i++];
		    else
			cur = G[2][v++];
		} else {
		    if (i != (int)G[1].size()) {
			cur = G[1][i++];
		    }
		    else if(v == (int)G[2].size())
			cur = G[3][j++];
		    else
			cur = G[2][v++];
		}
		
		if (r != 0) {
		    int k = min(r, cur);
		    //debug ("%d -- Tirei %d de %d e %d\n", i, k, r, G[i]);
		    cur -= k;
		    r -= k;
		    
		} else resp++;
		
		if (cur != 0) {
		    r += (p - cur % p) % p;
		    cur = 0;
		}
	    }
	    
	    printf ("%d\n", resp);
	    continue;
	} else {
	    int tam = G[1].size() + G[2].size();
	    int i = 0, j = 0;
	    for (int E = 0; E < tam; E++) {
		int cur;
		if (E % 2 == 0) {
		    if (j != (int)G[2].size()) {
			cur = G[2][j++];
		    } else
			cur = G[1][i++];
		} else {
		    if (i != (int)G[1].size()) {
			cur = G[1][i++];
		    }
		    else
			cur = G[2][j++];
	    }
		
		if (r != 0) {
		    int k = min(r, cur);
		    //debug ("%d -- Tirei %d de %d e %d\n", i, k, r, G[i]);
		    cur -= k;
		    r -= k;
		    
		} else resp++;
		
		if (cur != 0) {
		r += (p - cur % p) % p;
		cur = 0;
		}
	    }
	    
	    printf ("%d\n", resp);
	    continue;
	}
    }
    return 0;
}



