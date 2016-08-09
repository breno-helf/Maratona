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
  int xx;
  set<int> ap;
}tree[4*MAXN];

int n, a[MAXN], m;


void build(int id, int l, int r){
  if(l==r){
    tree[id].xx = a[l];
    tree[id].on = a[l];
    tree[id].ap.insert(a[l]);
  }
  else{
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    tree[id].xx = (tree[2*id].xx)^(tree[2*id + 1].xx);
    tree[id].ap.insert(tree[2*id].ap.begin(), tree[2*id].ap.end());
    tree[id].ap.insert(tree[2*id +1].ap.begin(), tree[2*id + 1].ap.end());
    /*    for(auto sum : tree[id].ap){
      tree[id].on ^= sum;
    }
    */
  }
}

seg query(int id, int l, int r, int lo, int hi){
  seg ret;
  ret.xx = ret.on = 0;
  if(l>hi || r<lo) return ret;
  if(l>=lo && r<=hi) return tree[id];
  int mid = (l+r)/2;
  seg esq = query(2*id, l, mid, lo, hi);
  seg dir = query(2*id +1, mid +1, r, lo, hi);

  ret.xx = (esq.xx)^(dir.xx);
  ret.ap.insert(esq.ap.begin(), esq.ap.end());
  ret.ap.insert(dir.ap.begin(), dir.ap.end());
  /*  for(auto sum : ret.ap){
    ret.on ^= sum;
  }
  */
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++) scanf("%d", &a[i]);
  build(1,1,n);

  scanf("%d", &m);
  for(int i=0;i<m;i++){
    int s, e;
    scanf("%d%d", &s, &e);
    seg resp = query(1, 1, n, s, e);
    int p = 0;
    for(auto sum : resp.ap){
      p ^= sum;
    }
    
    printf("%d\n", (resp.xx)^(resp.on));
  }
  return 0;
}
  

