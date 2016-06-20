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

ll m;

pll go(ll x){
  if(x==0) return mp(0ll,0ll);
  if(x==1) return mp(1ll,0ll);
  ll i;
  for(i=1;i<MAXN;i++){
    if((i*i*i) > x) break;
  }
  i--;
  pll ff = go(x-i*i*i);
  pll ss = go(3*i*(i-1));

  ff.first++;
  ss.first++;
  ss.second += x - i*i*i + 1;

  if(ff.first > ss.first) return ff;
  else if( ff.first < ss.first) return ss;
  else{
    if(ff.second < ss.second) return ff;
    else return ss;
  }
}


int main(){
  scanf("%I64d", &m);
  pll resp = go(m);
  printf("%I64d %I64d\n", resp.first, m - resp.second);
  return 0;
}

