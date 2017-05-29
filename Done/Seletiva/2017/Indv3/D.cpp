#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 30;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct edge {
    int u, v, w;
    edge (int U, int V, int W): u(U), v(V), w(W) {}
    edge (): u(0), v(0), w(0) {}
};


int R[MAX], P[MAX];
int D[MAX];
int n;

bool bellman (int K) {
    vector<edge> E;
    memset(D, INF, sizeof(D));

    D[0] = 0;
    
    for (int i = 1; i <= 24; i++) {
	E.pb(edge(i - 1, i, P[i]));
	E.pb(edge(i, i - 1, 0));

	if (i >= 8)
	    E.pb(edge(i, i - 8, - R[i]));
	else
	    E.pb(edge(i, i + 16, K - R[i]));	
    }

    E.pb(edge(0, 24, K));
    E.pb(edge(24, 0, -K));
    
    for (int i = 0; i <= 24; i++) {
	int tam = E.size();
	for (int j = 0; j < tam; j++) {
	    int u = E[j].u;
	    int v = E[j].v;
	    int w = E[j].w;

	    if ((D[u] + w) < D[v]) {
		if (i == 24) return false;
		D[v] = D[u] + w;
	    }	    
	}	
    }

    return true;
}


int main () {
    int T;
    scanf ("%d", &T);
    for (int teste = 0; teste < T; teste++) {
	memset(R, 0, sizeof(R));
	memset(P, 0, sizeof(P));

	for (int i = 1; i <= 24; i++)
	    scanf ("%d", R + i);

	scanf ("%d", &n);
	
	for (int i = 1; i <= n; i++) {
	    int t;
	    scanf ("%d", &t);
	    P[t + 1]++;
	}
	
	int resp = -1;

	for (int i = 0; i <= n; i++) {
	    if (bellman(i)) {
		resp = i;
		break;
	    }
	}

	if (resp == -1) printf ("No Solution\n");
	else printf ("%d\n", resp);
    }
    return 0;
}

