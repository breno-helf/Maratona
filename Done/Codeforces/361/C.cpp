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
const ll INF=(ll)1e16;
const ll  MOD=1000000007;

ll m, resp;

ll go(ll x){
  ll ret = 0;
  for(ll i = 2; i*i*i <=x;i++) ret += x/(i*i*i);
  return ret;
}

int main(){
  scanf("%I64d", &m);
  ll ini = 0, fim = INF, mid;
  while(ini<fim){
    mid = (ini+fim)/2;
    if(go(mid) >= m) fim = mid;
    else ini = mid + 1;
  }
  resp = (go(fim) == m) ? fim : -1;
  printf("%I64d\n", resp);
  return 0;
}




