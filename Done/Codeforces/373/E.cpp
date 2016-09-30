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

struct matrix{
  ll a[2][2];
  matrix() {
    a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
  }

  matrix operator+(matrix q) {
    matrix ret;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
	ret.a[i][j] = (a[i][j] + q.a[i][j])%MOD;

    return ret;
  }

  matrix operator*(matrix q) {
    matrix ret;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
	for(int k = 0; k < 2; k++)
	  ret.a[i][j] += (a[i][k]*(q.a[k][j]))%MOD;

	ret.a[i][j] %= MOD;
      }
    } 
    return ret;
  }

  bool operator==(matrix q) {
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
	if(a[i][j] != q.a[i][j]) return 0;
    return 1;
  }
};

struct seg{
  matrix no;
  matrix lazy;
}tree[4*MAXN];

matrix id, fib;
int n, m, v[MAXN];

matrix fexp(matrix a, int e) {
  matrix ret;
  ret = id;
  matrix pow = a;
  for(int i = 0; i < 32; i++) {
    if(e&(1<<i)) ret = ret*pow;
    pow = pow*pow;
  }
  return ret;
}

void build(int idx, int l, int r) {
  // debug("--> %d %d %d\n", idx, l, r);
  assert(idx != 0);
  
  if(l == r) {
    tree[idx].no = fexp(fib, v[l]);
    tree[idx].lazy = id;
  }
  else {
    int mid = (l + r)/2;
    int esq = 2*idx;
    int dir = 2*idx + 1;
    build(esq, l, mid);
    build(dir, mid + 1, r);
    tree[idx].no = (tree[esq].no) + (tree[dir].no);
    tree[idx].lazy = id;
  }

}

void propagate(int idx, int l, int r) {
  if(!(tree[idx].lazy == id)) {
    tree[idx].no = (tree[idx].no)*(tree[idx].lazy);
    if(l != r) {
      int esq = 2*idx, dir = 2*idx + 1;
      tree[esq].lazy = (tree[esq].lazy)*(tree[idx].lazy);
      tree[dir].lazy = (tree[dir].lazy)*(tree[idx].lazy);
    }
    tree[idx].lazy = id;
  }
}

void update(int idx, int l, int r, int lo, int hi, matrix val) {
  if(l >= lo && r <= hi) {
    tree[idx].lazy = (tree[idx].lazy)*val;
    return;
  }
  propagate(idx, l, r);
  int mid = (l + r)/2;
  int esq = 2*idx, dir = 2*idx + 1;
  if(mid >= lo) update(esq, l, mid, lo, hi, val);
  if(mid < hi) update(dir, mid + 1, r, lo, hi, val);
  propagate(esq, l, mid);
  propagate(dir, mid + 1, r);
  tree[idx].no = tree[esq].no + tree[dir].no;
}

ll query(int idx, int l, int r, int lo, int hi) {
  propagate(idx, l, r);
  if(l >= lo && r <= hi) return tree[idx].no.a[1][0];
  int mid = (l + r)/2;
  int esq = 2*idx;
  int dir = 2*idx + 1;
  ll ret = 0;
  if(mid >= lo) ret = query(esq, l, mid, lo, hi);
  if(mid < hi) ret += query(dir, mid + 1, r, lo, hi);
  ret %= MOD;
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) scanf("%d", v + i);
  id.a[0][0] = id.a[1][1] = 1;
  fib.a[0][1] = fib.a[1][0] = fib.a[1][1] = 1;
  build(1, 1, n);
  int tp, l, r, x;
  for(int w = 0; w < m; w++) {
    scanf("%d", &tp);
    if(tp == 1) {
      scanf("%d%d%d", &l, &r, &x);
      matrix upd = fexp(fib, x);
      update(1, 1, n, l, r, upd);
    }
    else {
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(1, 1, n, l, r));
    }
  } 
  return 0;
}



