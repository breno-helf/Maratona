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

const int MAXN=212345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, k;
int c[MAXN], l[MAXN], r[MAXN], marc[MAXN];
int resp;

map<int, map<int, int> > q;

vector<int> adj[MAXN];

void color(int u, int id) {
	q[id][c[u]]++;
	marc[u] = 1;
	for(auto v : adj[u]) {
		if(!marc[v])
			color(v, id);
	}
}

int main() {
	resp = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &l[i], &r[i]);
		adj[l[i]].pb(r[i]);
		adj[r[i]].pb(l[i]);
	}
	int idx = 1;
	for(int i = 1; i <= n; i++) {
		if(marc[i]) continue;
		color(i, idx);
		int tam = 0, tot = 0;
		for(auto v : q[idx]) {
			int num = v.second;
			tam = max(tam, num);
			tot += num;
		}
		debug("idx %d -- tot %d, tam %d\n", i, tot, tam);
		resp += tot - tam;
		idx++;
	}
	
	printf("%d\n", resp);
	return 0;
}



