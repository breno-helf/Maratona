#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k;

int dist[MAX];
vector<pii> edges;

int pai[MAX], sz[MAX], f[MAX];

int find(int a) {
    if (pai[a] == a) return a;
    else return pai[a] = find(pai[a]);
}

void une(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) return;
    
    if (sz[b] > sz[a]) swap(a, b);

    pai[b] = a;
    sz[a] += sz[b];     
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; i++) {
	pai[i] = i;
	sz[i] = 1;
    }
    int resp = 0;
    
    set<pii> Q;
    for (int i = 2; i <= k + 1; i++) {
	f[i] = 1;
	edges.pb(pii(1, i));
	Q.insert(pii(1, i));
    }
    int cur = k + 2;

    for (int j = cur; j <= n; j++) {
	int u = Q.begin()->second;
	edges.pb(pii(u, j));
	Q.erase(Q.begin());
	f[j] = f[u] + 1;
	Q.insert(pii(f[j], j));
    }

    int FF = 0, SS = 0;

    for (int i = 1; i <= n; i++) {
	if (f[i] > FF) {
	    SS = FF;
	    FF = f[i];
	} else if (f[i] > SS) SS = f[i];
    }
    
    resp = FF + SS;
    printf("%d\n", resp);
    for (auto e : edges) {
	printf("%d %d\n", e.first, e.second);
    }
}

