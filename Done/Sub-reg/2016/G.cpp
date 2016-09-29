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

const int MAXN=512;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int g[MAXN][MAXN], p[MAXN][MAXN], b[MAXN][MAXN];
int n, c;


int main() {
  scanf("%d%d", &n, &c);
  for(int i = 0; i < c; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x - 1][y - 1] = 1;
  }
  for(int i = 0; i < c; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x - 1][y - 1] = 2;
  }
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == 0 || j == 0) {
	if(i == 0 && j == 0) {
	  p[i][j] = (int)(g[i][j] == 1);
	  b[i][j] = (int)(g[i][j] == 2);
	}
	else if(i == 0) {
	  p[i][j] = p[i][j - 1] + (int)(g[i][j] == 1);
	  b[i][j] = b[i][j - 1] + (int)(g[i][j] == 2);
	}
	else {
	  p[i][j] = p[i - 1][j] + (int)(g[i][j] == 1);
	  b[i][j] = b[i - 1][j] + (int)(g[i][j] == 2);
	}
      }
      else {
	p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (int)(g[i][j] == 1);
	b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (int)(g[i][j] == 2);
      }
    }
  }
  ll rP = 0, rB = 0, cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k <= (min(n - i - 1, n - j - 1)); k++) {
	cnt++;
	if(i == 0 || j == 0) {
	  if(i == 0 && j == 0) {
	    int valP, valB;
	    valP = p[i + k][j + k];
	    valB = b[i + k][j + k];
	    debug("ij--> %d %d\n", valB, valP);
	    if((valP == 0) && (valB > 0)) rB++;
	    else if((valP > 0) && (valB == 0)) rP++;
	  }
	  else if(i == 0) {
	    int valP, valB;
	    valP = p[i + k][j + k] - p[i + k][j - 1];
	    valB = b[i + k][j + k] - b[i + k][j - 1];
	    debug("i--> %d %d\n", valB, valP);
	    if((valP == 0) && (valB > 0)) rB++;
	    else if((valP > 0) && (valB == 0)) rP++;
	  }
	  else {
	    int valP, valB;
	    valP = p[i + k][j + k] - p[i - 1][j + k];
	    valB = b[i + k][j + k] - b[i - 1][j + k];
	    debug("j--> %d %d\n", valB, valP);
	    if((valP == 0) && (valB > 0)) rB++;
	    else if((valP > 0) && (valB == 0)) rP++;
	  }
	}
	else {
	  int valP, valB;
	  valP = p[i + k][j + k] - p[i - 1][j + k] - p[i + k][j - 1] + p[i - 1][j - 1];
	  valB = b[i + k][j + k] - b[i - 1][j + k] - b[i + k][j - 1] + b[i - 1][j - 1];
	  if((valP == 0) && (valB > 0)) rB++;
	  else if((valP > 0) && (valB == 0)) rP++;
	}
      }
    }
  }
  debug("\n%lld\n\n", cnt);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      debug("%d ", g[i][j]);
    debug("\n");
  }
  debug("\n\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      debug("%d ", p[i][j]);
    debug("\n");
  }
  debug("\n\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      debug("%d ", b[i][j]);
    debug("\n");
  }
  debug("\n\n");
  printf("%lld %lld\n", rP, rB);
  return 0;
}
