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

ll c[MAXN], resp, tot, ct;

int n, k, cp[MAXN];

map<int,int> im;



int main(){
  scanf("%d%d", &n, &k);
  resp = 0;
  tot = 0;
  ct = 0;
  for(int i=1;i<=n;i++){
    scanf("%I64d", &c[i]);
    tot += c[i];

  }
  for(int i=1;i<=k;i++){
    scanf("%d", &cp[i]);
    im[cp[i]] = 1;
    resp += c[cp[i]]*(tot-c[cp[i]]-ct);
    ct += c[cp[i]];
  }

  for(int i=1;i<=n;i++){
    if(i!=n){
      if(im[i] == 0 && im[i+1]==0){
	resp += c[i]*c[i+1];
      }
    }
    else{
      if(im[i] == 0 && im[1]==0){
	resp += c[i]*c[1];
      }
    }
  }
  printf("%I64d\n", resp);
  return 0;
}


