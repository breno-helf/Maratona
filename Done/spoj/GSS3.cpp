//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=5123456;
const int INF=0x3f3f3f3f;

struct seg{
  ll mx;
  ll pre;
  ll suf;
  ll sum;
}tree[4*MAXN];

int n, m, a[MAXN];

void build(int idx, int l, int r){
  if(l==r){
    tree[idx].mx = a[l];
    tree[idx].pre = a[l];
    tree[idx].suf = a[l];
    tree[idx].sum = a[l];
  }
  else{
    int mid = (l+r)/2;
    build(2*idx, l, mid);
    build(2*idx + 1, mid + 1, r);
    tree[idx].sum = tree[2*idx].sum + tree[2*idx+1].sum;
    tree[idx].pre = max(tree[2*idx].pre, tree[2*idx].sum + tree[2*idx + 1].pre);
    tree[idx].suf = max(tree[2*idx + 1].suf, tree[2*idx + 1].sum + tree[2*idx].suf);
    tree[idx].mx = max( max(tree[2*idx].mx, tree[2*idx + 1].mx), tree[2*idx].suf + tree[2*idx + 1].pre); 
  }
}

void up(int idx, int l, int r, int pos, int val){
  if(l==r){
    tree[idx].mx = val;
    tree[idx].pre = val;
    tree[idx].suf = val;
    tree[idx].sum = val;
  }
  else{
    int mid = (l+r)/2;
    if(pos <= mid) up(2*idx, l, mid, pos, val);
    else up(2*idx + 1, mid + 1, r, pos, val);
    tree[idx].sum = tree[2*idx].sum + tree[2*idx + 1].sum;
    tree[idx].pre = max(tree[2*idx].pre, tree[2*idx].sum + tree[2*idx + 1].pre);
    tree[idx].suf = max(tree[2*idx + 1].suf, tree[2*idx + 1].sum + tree[2*idx].suf);
    tree[idx].mx = max( max(tree[2*idx].mx, tree[2*idx + 1].mx), tree[2*idx].suf + tree[2*idx + 1].pre);
  }
}

seg query(int idx, int l, int r, int lo, int hi){
  seg ret;
  ret.mx = ret.pre = ret.suf = ret.sum = -INF;
  if(r<lo || l>hi) return ret; 
  if(l>=lo && r<=hi) return tree[idx];
  else{
    int mid = (l+r)/2;
    seg esq = query(2*idx, l, mid, lo, hi);
    seg dir = query(2*idx + 1, mid + 1, r, lo, hi);
    ret.sum = esq.sum + dir.sum;
    ret.pre = max(esq.pre, esq.sum + dir.pre);
    ret.suf = max(dir.suf, dir.sum + esq.suf);
    ret.mx = max( max(dir.mx, esq.mx), esq.suf + dir.pre);

    return ret;
  }
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%d", &a[i]);
  build(1, 0, n-1);

  scanf("%d", &m);
  for(int i=0;i<m;i++){
    int o, x, y;
    scanf("%d%d%d", &o, &x, &y);
    x--;
    if(o==0) up(1, 0, n-1, x, y);
    else{
      y--;
      ll p = (query(1, 0, n-1, x, y)).mx;
      printf("%lld\n", p);
    }
  }
  return 0;
}

