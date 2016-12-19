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

int n, q, a[MAXN], l;

struct task {
  int t, k, d;
} v[MAXN];

int cmp(task f, task b) {
  return f.t < b.t;
}

int main() {
  scanf("%d%d", &n, &q);
  for(int i = 0; i < q; i++) {
    scanf("%d%d%d", &v[i].t, &v[i].k, &v[i].d);    
  }
  sort(v, v + q, cmp);
  l = n;
  int i = 0;
  for(int w = 0; w <= 1000000; w++) {
    if(v[i].t != w) {
      for(int j = 0; j < n; j++) {
        if(a[j] == 1)
          l++;
        (a[j] > 0) ? a[j]-- : a[j] = 0;
      }
      continue;
    }
    if(l < v[i].k)
      printf("-1\n");
    else {
      int resp = 0;
      l -= v[i].k;
      for(int j = 0; j < n; j++) {
        if(a[j] == 0) {
          a[j] = v[i].d;
          resp += (j + 1);
          v[i].k--;
        }
        if(!v[i].k)
          break;
      }
      printf("%d\n", resp);
    }
    for(int j = 0; j < n; j++) {
      if(a[j] == 1)
        l++;
      (a[j] > 0) ? a[j]-- : a[j] = 0;
    }
    i++;
  }
  return 0;
}
