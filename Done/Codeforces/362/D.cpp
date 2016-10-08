//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, p[MAXN], sz[MAXN];
double ex[MAXN];
vector<int> adj[MAXN];

void calc(int u) {
    sz[u] = 1;
    for(int v : adj[u]) {
        calc(v);
        sz[u] += sz[v];
    }
    //    debug("--> %d %d\n", u, sz[u]);
}

void dfs(int u) {
    for(int v : adj[u]) {
        ex[v] = ex[u] + ((double)(sz[u] + 1 - sz[v]))/2.0;
        dfs(v);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
        adj[p[i]].pb(i);
    }
    ex[1] = 1.0;
    calc(1); 
    dfs(1);
    for(int i = 1; i <= n; i++)
        printf("%lf%c", ex[i], (i==n) ? '\n' : ' '); 
}

