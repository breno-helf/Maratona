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

ll n, k, a[MAXN];
ll resp;

int main() {
  scanf("%I64d%I64d", &n, &k);
  for(int i = 0; i < n; i++) scanf("%I64d", &a[i]);

  sort(a, a + n);

  ll ini = 0, fim = 2*((ll)1e9);

  while(ini < fim) {
    ll meio = (fim - ini)/2 + ini;

    ll c = 0;
    for(int i = 0; i < n - 1;  i++) {
      ll lo = i+1, hi = n - 1;
      if(a[lo] + a[i] > meio) continue;
      while(lo < hi) {
	ll mi = (lo+hi+1)/2;
	if((a[i] + a[mi]) <= meio) lo = mi;

	else hi = mi - 1;
      }
      c += lo - i;
    }

    if(c >= k) fim = meio;
    else ini = meio + 1;
  }
  assert(ini==fim);
  resp = ini;
  printf("%I64d\n", resp);
  return 0;
}
