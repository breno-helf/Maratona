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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, d;

ll x;

char c;

int resp;

int main(){
  scanf("%d%I64d", &n, &x);
  resp = 0;
  for(int i=0;i<n;i++){
    scanf(" %c %d", &c, &d);
    if(c=='+'){
      debug("Somei\n");
      x += d;
    }
    else{
      debug("Subtrai\n");
      if(x >= d) x -= d;
      else resp++;
    }
  }
  printf("%I64d %d\n", x, resp);
  return 0;
}
    



