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

const int MAXN=512345;
const int INF=0x3f3f3f3f;

struct seg{
  ll mx;
  ll pre;
  ll suf;
  ll sum;
}tree[4*MAXN];
 
int t, n, a[MAXN];

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
int main(){
  scanf("%d", &t);
  for(int tt=0;tt<t;tt++){
    scanf("%d", &n);
    memset(tree, 0,sizeof(tree));
    memset(a, 0, sizeof(a));
    bool ok = false;
    int mx=-INF;
    for(int i=0;i<n;i++){
      scanf("%d", &a[i]);
      if(a[i]>0) ok = true;
      mx = max (mx, a[i]);
    }
    if(!ok){
      printf("%d\n", mx);
      continue;
    }
    build(1, 0, n-1);
    ll resp = -INF;
    resp = max( resp, tree[1].mx );
    for(int i=0;i<n;i++){
      up(1, 0, n-1, i, 0);
      resp = max ( resp, tree[1].mx);
      up(1, 0, n-1, i, a[i]);
    }
    printf("%lld\n", resp);
  }
  return 0;
}

