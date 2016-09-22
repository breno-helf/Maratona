//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=51234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, a[MAXN];
int resp, h;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  resp = h = 1;
  for(int i = 0; i < n; i++) {
    h = min(h, a[i]);
    if(i + h > n) break;
    debug("[%d] - In %d with height %d\n", h, i, a[i]);
    int flag = 0;
    for(int j = i + 1; j < (i + h); j++) {
      debug("    Going down in %d with heigh %d\n", j, a[j]);
      if(a[j] < (h - j + i)) {
	debug("ERROR\n");
	i = j - 1;
	flag = 1;
	break;
      }
    }
    if(flag) continue;
    resp = max(resp, h);
    h++;
  }

  printf("%d\n", resp);
}
  


