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

const int MAXN=112345;
const ll INF=(long long int)1e15;

struct seg{
  pair<ll,int> mx;
  pair<ll,int> pre;
  pair<ll,int> suf;
  pair<ll,int> sum;
}tree[4*MAXN];

int t, n, q, c[MAXN];

void build(int id, int l, int r){
  if(l==r){
    tree[id].mx = mp(c[l],1);
    tree[id].pre = mp(c[l],1);
    tree[id].suf = mp(c[l],1);
    tree[id].sum = mp(c[l],1);
  }
  else{
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    tree[id].sum = mp(((tree[2*id].sum).first + (tree[2*id +1].sum).first), ((tree[2*id].sum).second + (tree[2*id +1].sum).second));
    tree[id].pre = max(tree[2*id].pre, mp(((tree[2*id].sum).first + (tree[2*id+1].pre).first), ((tree[2*id].sum).second + (tree[2*id+1].pre).second)));
    tree[id].suf = max(tree[2*id +1].suf, mp(((tree[2*id +1].sum).first + (tree[2*id].suf).first),((tree[2*id +1].sum).second + (tree[2*id].suf).second)));
    tree[id].mx = max(max(tree[2*id].mx, tree[2*id +1].mx), mp(((tree[2*id].suf).first + (tree[2*id+1].pre).first), ((tree[2*id].suf).second + (tree[2*id+1].pre).second)));
  }
}

seg query(int id, int l, int r, int lo, int hi){
  seg ret;
  ret.mx = ret.suf = ret.pre = ret.sum = mp(-INF,0);
  if(l>hi || r<lo) return ret;
  if(l>=lo && r<=hi) return tree[id];
  int mid = (l+r)/2;
  seg esq = query(2*id, l, mid, lo, hi);
  seg dir = query(2*id +1, mid +1, r, lo, hi);
  ret.sum = mp((esq.sum).first + (dir.sum).first, (esq.sum).second + (dir.sum).second);
  ret.pre = max(esq.pre, mp((esq.sum).first + (dir.pre).first, (esq.sum).second + (dir.pre).second));
  ret.suf = max(dir.suf, mp((dir.sum).first + (esq.suf).first, (dir.sum).second + (esq.suf).second));
  ret.mx = max( max(esq.mx, dir.mx), mp((esq.suf).first + (dir.pre).first, (esq.suf).second + (dir.pre).second));
  return ret;
}

int main(){
  scanf("%d", &t);
  for(int tt=1;tt<=t;tt++){
    scanf("%d", &n);
    memset(tree,0,sizeof(tree));
    memset(c,0,sizeof(c));  
    for(int i=1;i<=n;i++) scanf("%d", &c[i]);
    build(1,1,n);
    scanf("%d", &q);
    for(int i=0;i<q;i++){
      int a, b;
      scanf("%d%d", &a, &b);
      if(b<a) swap(a,b);
      seg resp = query(1, 1, n, a, b);
      printf("%lld %d\n", (resp.mx).first, (resp.mx).second);
    }
  }
  return 0;
}
