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

const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


int n, x, l[MAXN], r[MAXN];

int main(){
  scanf("%d%d", &n, &x);
  for(int i=0;i<n;i++) scanf("%d%d", &l[i], &r[i]);
  int m = 0;
  int t = 1;
  int resp = 0;
  while(m<n){
    debug("--> %d\n", t);
    if(t==l[m]){
      debug("kk %d\n", r[m] - l[m] + 1); 
      resp += r[m] - l[m] + 1;
      t = r[m] + 1;
      m++;
    }
    if(m==n) break;
    if( t+x <= l[m]) t += x;
    else{
      debug("ll %d\n", l[m] - t);
      resp += (l[m] - t);
      t = l[m];
    }
  }
  printf("%d\n", resp);
  return 0;
}



