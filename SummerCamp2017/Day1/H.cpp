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

const int MAXN=412345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n;

map<pii, int> rel;

int nx[MAXN], cl, hd[MAXN], to[MAXN];
int del[MAXN];
int sz[MAXN], color[MAXN], tim, mark[MAXN], p;

int get(int x) {
    if (!x || !del[x]) return x;
    return nx[x] = get(nx[x]);    
}

void pinta(int u, int c) {
    if(mark[u] == tim)
	return;
    mark[u] = tim;
    sz[color[u]]--;
    sz[c]++;
    color[u] = c;
    
    for(int e = get(hd[u]); e != 0; e = get(nx[e])) { 
	pinta(to[e], c);
    }
}

void une(int u, int v) {
    rel[mp(u, v)] = cl;
    if(sz[color[u]] < sz[color[v]]) swap(u, v);
    tim++;
    pinta(v, color[u]);
    nx[cl] = hd[u]; to[cl] = v; hd[u] = cl++;
    nx[cl] = hd[v]; to[cl] = u; hd[v] = cl++;       
}


void cut(int u, int v) {
    int ar = rel[pii(u, v)];
    del[ar] = del[ar + 1] = 1;

    queue<pii> fila[2];
    int t = 1;
    fila[0].push(pii(u, hd[u]));
    fila[1].push(pii(v, hd[v]));
    tim++;

    while(!fila[t].empty()) {
	pii att = fila[t].front();
	fila[t].pop();

	mark[att.first] = tim;

	int ed = get(att.second);
	if(ed == 0) continue;
	int a = to[ed];

	if(mark[a] != tim)
	    fila[t].push(pii(a, hd[a]));
	fila[t].push(pii(att.first, nx[ed]));

	t = !t;
    }

    
    tim++;
    if(t)
	swap(u, v);
    
    pinta(u, p++);
}

int main() {
    scanf("%d", &n);
    tim = 0;
    p = 0;
    for(int i = 0; i < n; i++) {
	sz[p] = 1;
	color[i] = p++;
    }
    cl = 2;
    
    while(true) {
	char op;
	int u, v;
	scanf(" %c", &op);
	
	if(op == 'E')
	    return 0;
	
	scanf("%d%d", &u, &v);
	u--; v--;
	if(u > v) swap(u, v);

	if(op == 'C')
	    une(u, v);

	else if(op == 'D')
	    cut(u, v);

	else {
	    if(color[u] == color[v])
		printf("YES\n");
	    else
		printf("NO\n");
	    fflush(stdout);
	}	    
    }
    return 0;
}

