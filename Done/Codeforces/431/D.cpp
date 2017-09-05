//If you are trying to hack me I wish you can get it, Good Luck :D.
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

int n, w, h;

int g[MAX], p[MAX], t[MAX];

map<int, vector<int> > hor, ver;

pii ed[MAX], resp[MAX];

bool cmp1(int a, int b) {
    return p[a] < p[b];
}
bool cmp2(int a, int b) {
    return p[a] > p[b];
}

int main() {
    scanf("%d%d%d", &n, &w, &h);

    for (int i = 1; i <= n; i++) {
	scanf("%d%d%d", g + i, p + i, t + i);
	if (g[i] == 1) {
	    ver[p[i] - t[i]].pb(i);
	    ed[i] = resp[i] = pii(p[i], h);
	}
	else {
	    hor[p[i] - t[i]].pb(i);
	    ed[i] = resp[i] = pii(w, p[i]);
	}
    }
    vector<int> H, V;
    vector<int> U, R;
    
    for (auto e : hor) {
    	H = hor[e.first];
    	V = ver[e.first];
    	sort(H.begin(), H.end(), cmp1);
    	sort(V.begin(), V.end(), cmp2);
    	U = H;
    	for (auto v : V) U.pb(v);
    	R = V;
    	for (auto r : H) R.pb(r);
	
    	int j = 0;
    	int tam = R.size();
    	while (j < tam) {
    	    resp[R[j]] = ed[U[j]];
    	    j++;
    	}
    }

    for (int i = 1; i <= n; i++)
	printf("%d %d\n", resp[i].first, resp[i].second);
    
}
