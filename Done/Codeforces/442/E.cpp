//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, p[MAX], t[MAX];
int from[MAX], to[MAX], pos[MAX], sz = 0;
int inv[MAX];

bool used[MAX];

vector<int> adj[MAX];

struct TREE {
    int lazy;
    int sum;
} seg[4 * MAX];

void dfs(int node) {
    used[node]=true;
    pos[node]=++sz;
    from[node]=sz;
    to[node]=sz;
    int i;
    for(i=0; i < (int)(adj[node].size()); i++) {
        if(!used[adj[node][i]]) {
	    dfs(adj[node][i]);
	    to[node]=max(to[node],to[adj[node][i]]);
	}
    }
}


void build(int idx, int l, int r) {
  //debug("--> %d %d %d\n", idx, l, r);
  assert(idx != 0);
  
  if(l == r) {
      seg[idx].sum = t[inv[l]];
      seg[idx].lazy = 0;
      return;
  }
  
  int mid = (l + r)/2;
  int esq = 2*idx;
  int dir = 2*idx + 1;
  build(esq, l, mid);
  build(dir, mid + 1, r);
  seg[idx].sum = (seg[esq].sum) + (seg[dir].sum);
  seg[idx].lazy = 0;
}

void propagate(int idx, int l, int r) {
  if(seg[idx].lazy != 0) {

      if (seg[idx].lazy % 2) {
	  int I = r - l + 1;
	  seg[idx].sum = I - seg[idx].sum;
      }
      
      if(l != r) {
	  int esq = 2*idx, dir = 2*idx + 1;
	  seg[esq].lazy += seg[idx].lazy;
	  seg[dir].lazy += seg[idx].lazy;
      }
      seg[idx].lazy = 0;
  }
}

void update(int idx, int l, int r, int lo, int hi, int val) {
  if(l >= lo && r <= hi) {
    seg[idx].lazy += val;
    return;
  }
  propagate(idx, l, r);
  int mid = (l + r)/2;
  int esq = 2*idx, dir = 2*idx + 1;
  if(mid >= lo) update(esq, l, mid, lo, hi, val);
  if(mid < hi) update(dir, mid + 1, r, lo, hi, val);
  propagate(esq, l, mid);
  propagate(dir, mid + 1, r);
  seg[idx].sum = seg[esq].sum + seg[dir].sum;
}

ll query(int idx, int l, int r, int lo, int hi) {
  propagate(idx, l, r);
  if(l >= lo && r <= hi) return seg[idx].sum;
  int mid = (l + r) / 2;
  int esq = 2*idx;
  int dir = 2*idx + 1;
  ll ret = 0;
  if(mid >= lo) ret = query(esq, l, mid, lo, hi);
  if(mid < hi) ret += query(dir, mid + 1, r, lo, hi);
  return ret;
}

char str[12];

int main() {
    scanf("%d", &n);
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
	scanf("%d", p + i);
	adj[p[i]].pb(i);
	adj[i].pb(p[i]);
    }
    for (int i = 1; i <= n; i++) {
	scanf("%d", t + i);
    }
    
    dfs(1);
    for (int i = 1; i <= n; i++) {
	inv[pos[i]] = i;
    }

    build(1, 1, n);

    int q;
    scanf("%d", &q);

    while(q--) {
	int v;
	scanf(" %s %d", str, &v);
	if (str[0] == 'g') {
	    printf("%lld\n", query(1, 1, n, from[v], to[v]));
	} else {
	    update(1, 1, n, from[v], to[v], 1);
	}	
    }

    return 0;
}
