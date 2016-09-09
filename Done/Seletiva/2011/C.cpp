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

const int MAXN=22;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll t, n, a[MAXN], x;

int main() {
  scanf("%lld", &t);
  while(t--) {
    scanf("%lld%lld", &n, &x);
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= n; i++) scanf("%lld", &a[i]);
    ll p = a[n];
    for(int i = n - 1; i >= 0; i--) {
      a[i] = x*p + a[i];
      p = a[i];
    }
    printf("%lld\n", a[0]);
    for(int i = 1; i <= n ; i++) printf("%lld%c", a[i], (i == n) ? '\n' : ' ');
  }
  return 0;
}


