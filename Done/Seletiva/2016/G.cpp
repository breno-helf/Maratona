//This code was made by Sir. Breno Moura and Mr. Enzo Nakamura, Codeforces Handle: Brelf
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

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;
const int MAXB = 25;


int ini[MAXN], fim[MAXN], h[MAXN];

int q, pai[MAXN][MAXB], val[MAXN];

void start(int x) {  
  for(int i = 1; i < MAXB; i++)
    pai[x][i] = pai[pai[x][i-1]][i-1];
}

int la(int u, int up) {
  for(int i = 22; i >= 0; i--) {
    if((1<<i) <= up) {
      u = pai[u][i];
      up -= (1<<i);
    }
  }
  return u;
}

int main() {
  scanf("%d", &q); 
  
  for(int i = 1; i <= q; i++) {
    char c;
    scanf(" %c", &c);
    if(c == 'E') {
      int v, x;
      scanf(" %d %d", &v, &x);
      pai[i][0] = v;
      //if(!v) pai[i][0] = i;

      h[i] = h[v] + 1;
      start(i);
      val[i] = x;
      ini[i] = ini[v];

      //if(!v) ini[i] = i;
      fim[i] = i;
    }

    if(c == 'D') {
      int v;
      scanf(" %d", &v);
      int e = la(fim[v], h[fim[v]] - h[ini[v]] - 1);
      printf("%d\n", val[e]);
      ini[i] = e;
      fim[i] = fim[v];
      pai[i][0] = pai[v][0];
      val[i] = val[v];
      start(i);
      h[i] = h[v];
      
      //debug("-- %d %d %d [%d]\n", ini[v], fim[v], ini[i], h[fim[v]] - h[ini[v]] - 1);
    }
  }

  return 0;
}
