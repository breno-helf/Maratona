//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define deb(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

ll n, k, a[MAXN], b[MAXN];

bool solve(ll x){
  ll aux = k;
  for(int i=0;i<n;i++){
    if((log(a[i]) + log(x)) > (18.*log(10))) return 0;
    if((b[i]-a[i]*x)<0){
      if(aux<0) return 0;
      aux += (b[i]-a[i]*x);
    }
  }
  if(aux<0) return 0;
  return 1;
}

int main(){
  scanf("%I64d%I64d", &n, &k);
  for(int i=0;i<n;i++) scanf("%I64d", &a[i]);
  for(int i=0;i<n;i++) scanf("%I64d", &b[i]);
  ll ini=0, fim = 2*(1e9) + 200;
  while(ini<fim){
    ll meio=(fim+ini+1)/2;
    if(solve(meio)) ini = meio;
    else fim = meio-1;
  }
  printf("%I64d\n", ini);
  return 0;
}
