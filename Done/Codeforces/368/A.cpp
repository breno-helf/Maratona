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

int n, m, b, w, c;

int main() {
  b = w = c = 0;
  char k;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf(" %c", &k);
      if(k != 'B' && k != 'W' && k != 'G') c = 1;
    }
  }
  if(c) puts("#Color");
  else puts("#Black&White");
  return 0;
}



