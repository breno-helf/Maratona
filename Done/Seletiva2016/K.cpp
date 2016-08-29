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

int n, resp;

double prob;
double cur;

int main() { 
  scanf("%d", &n);
  prob = 0;
  for(int i = 2; ; i++) {
    prob = 1;
    for(int k = 1; k < i; k++) {
      prob *= (n - (double)k)/n;
    }
    debug("%lf\n", prob);
    if((1 - prob) > 0.5) {
      printf("%d\n", i);
      return 0;
    }
  }
}
