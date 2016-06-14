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

const int MAXN=1234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll ho, ca, co, n;

int main(){
  int e = 0;
  ho = 1234567;
  ca = 123456;
  co = 1234;
  scanf("%I64d", &n);
  for(ll i=0;i<1000 && (n - ho*i)>=0;i++){
    for(ll j=0;j<10000 && (n - ho*i - ca*j)>=0; j++){
      if(!((n - ho*i - ca*j)%co)) e = 1;
    }
  }
  if(e) puts("YES");
  else puts("NO");
  return 0;
}








