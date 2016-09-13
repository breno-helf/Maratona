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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


ll l[3], r[3], k;
ll resp;
ll ini, fim;
int main() {
  scanf("%lld%lld%lld%lld%lld", &l[1], &r[1], &l[2], &r[2], &k);
  ini = max(l[1], l[2]);
  fim = min(r[1], r[2]);
  resp = fim - ini + 1;
  if(k >= ini && k <= fim) resp--;
  resp = max(resp, 0LL);
  printf("%lld\n", resp);
}


