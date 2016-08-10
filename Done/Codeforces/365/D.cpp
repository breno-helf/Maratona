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

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


struct seg{
  int x;
}tree[4*MAXN];

int n, a[MAXN], m;

int acc[MAXN];

vector<pii> q[MAXN];

map<int,int> f;

int resp[MAXN];


void update(int id, int l, int r, int pos, int val){
  if(l==r){
    tree[id].x ^= val;
    return;
  }
  
  int mid = (l+r)/2;

  if(pos<=mid) update(2*id, l, mid, pos, val);
  else update(2*id +1, mid + 1, r, pos, val);
  
  tree[id].x = (tree[2*id].x)^(tree[2*id +1].x);
    
}

seg query(int id, int l, int r, int lo, int hi){
  seg ret;
  ret.x = 0;
  if(l>hi || r<lo) return ret;
  if(l>=lo && r<=hi) return tree[id];
  int mid = (l+r)/2;
  seg esq = query(2*id, l, mid, lo, hi);
  seg dir = query(2*id +1, mid +1, r, lo, hi);

  ret.x = (esq.x)^(dir.x);
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &a[i]);
    acc[i] = acc[i-1]^a[i];
  }
  memset(tree,0,sizeof(tree));
  scanf("%d", &m);

  for(int i=1;i<=m;i++){
    int x, y;
    scanf("%d%d", &x, &y);
    q[y].pb(mp(x,i));
  }
  
  for(int i=1;i<=n;i++){
    sort(q[i].begin(), q[i].end());
    
    if(f[a[i]]!=0) update(1, 1, n, f[a[i]], a[i]);

    update(1, 1, n, i, a[i]);

    f[a[i]] = i;

    int tam = q[i].size();
    
    for(int k=0; k<tam; k++){
      int ff = q[i][k].first, ss = q[i][k].second;
      resp[ss] = acc[i]^acc[ff-1]^query(1,1,n,ff,i).x;
    }    
  }
  for(int i=1;i<=m;i++) printf("%d\n", resp[i]);
  
  return 0;
}
  

