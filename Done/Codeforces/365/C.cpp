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

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, w, v, u;

double resp;

int main(){
  scanf("%d%d%d%d", &n, &w, &v, &u);

  resp = (double)w/(double)u;
  int go = 1;
  double espera = -INF, last;
  
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);

    double p = (double)a/(double)v - (double)b/(double)u;

    espera = max(p,espera);
    
    if (i > 0) if ( (last > 0 && p<0) || (p>0 && last<0) ) go = 0;
    last = p;
  }
    
    
  if (go) printf("%lf\n", resp);
  else printf("%lf\n", resp + espera);

  return 0;
}

