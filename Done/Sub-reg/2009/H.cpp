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

int a, c, x[MAXN], marc[MAXN];

pii mn;

int solve(int r) {
  int ret = 0;
  queue<pii> fila;
  fila.push(pii(mn.second, 0));
  marc[mn.second] = 1;
  while(!fila.empty()) {
    pii d = fila.front();
    int n = d.first, l = d.second;
    
    if(l > x[n]) {
      if(n - 1 >= 0) {
	if(!marc[n-1]) {
	  fila.push(pii(n-1, x[n]));
	  marc[n-1] = 1;
	}
      }
      if(n + 1 < r) {
	if(!marc[n+1]) {
	  fila.push(pii(n+1, x[n]));
	  marc[n+1] = 1;
	}
      }
    }
    else {
      ret += x[n] - l; 
      if(n - 1 >= 0) {
	if(!marc[n-1]) {
	  fila.push(pii(n-1, x[n]));
	  marc[n-1] = 1;
	}
      }
      if(n + 1 < r) {
	if(!marc[n+1]) {
	  fila.push(pii(n+1, x[n]));
	  marc[n+1] = 1;
	}
      }
    }
    fila.pop();
  }
  return ret;  
}

int main() {
  while(1) {
    mn = pii(0,0);
    memset(marc,0,sizeof(marc));
    memset(x,0,sizeof(x));
    scanf("%d%d", &a, &c);
    if(a == 0 && c == 0) break;
    for(int i = 0; i < c; i++) {
      scanf("%d", &x[i]);
      x[i] = a - x[i];
      mn = max(mn, pii(x[i], i));
    }

    printf("%d\n", solve(c));
  }
  return 0;
}
