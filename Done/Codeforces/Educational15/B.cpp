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

int n, a[MAXN];
ll resp;
map<int, ll> qtd;

int main() {
  resp = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    qtd[a[i]]++;
  }

  for(int i = 0; i < 31; i++) {
    if(qtd[(1<<i)] > 0) resp += (qtd[(1<<i)])*(qtd[(1<<i)] - 1)/2;
  }

  for(int i = 0; i < n; i++) {
    for(int k = 0; k < 31; k++) {
      if((1<<k) <= 2*a[i]) continue;

      resp += qtd[((1<<k) - a[i])];
    }
  }

  printf("%lld\n", resp);
}
