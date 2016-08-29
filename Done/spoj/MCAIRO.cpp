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
const int MAXX=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int bit[MAXX][MAXX], n, resp;

pii pos[MAXN];

void up(int x, int y, int val) {
  for(int k = x; k < MAXX; k += (k&-k)) {
    for(int l = y; l < MAXX; l += (l&-l)) {
      bit[k][l] = max(bit[k][l], val);
    }
  }
}

int query(int x, int y) {
  int ret = 0;
  for(int k = x; k > 0; k -= (k&-k)) {
    for(int l = y; l > 0; l -= (l&-l)) {
      ret = max(ret, bit[k][l]);
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(pos,0,sizeof(pos));
    memset(bit,0,sizeof(bit));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d%d", &pos[i].first, &pos[i].second);
    }
    resp = 0;
    for(int i = 1; i <= n; i++) {
      int a = query(pos[i].first, pos[i].second) + 1;
      resp = max(resp, a);
      up(pos[i].first, pos[i].second, a);
    }

    printf("%d\n", resp);
  }
  return 0;
}
