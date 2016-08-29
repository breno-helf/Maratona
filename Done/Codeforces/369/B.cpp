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

const int MAXN=512;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


ll n, g[MAXN][MAXN];

ll r[MAXN], c[MAXN], d[2];

ll z[2], sum, f[10];

int main() {
  scanf("%I64d", &n);

  if(n == 1) {
    puts("1");
    return 0;
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf(" %I64d", &g[i][j]);
      if(!g[i][j]) {
	z[0] = i;
	z[1] = j;
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      r[i] += g[i][j];
      c[j] += g[i][j];
      if(i == j) d[0] += g[i][j];
      if((j+i) == (n+1)) d[1] += g[i][j];
    }
  }


  if(z[0] == 1) sum = r[2];
  else sum = r[1];

  f[1] = 1;
  f[2] = f[3] = 0;
  
  if(z[0] == z[1]) {
    f[2] = 1;
  }
  if((z[0] + z[1]) == (n+1)) {
    f[3] = 1;
  }
  
  ll q;

  q = r[z[0]];

  ll resp = sum - q;

  if(resp <= 0) {
    puts("-1");
    return 0;
  }

  g[z[0]][z[1]] = resp;
  
  /*  
  if(f[1]) {
    if(c[z[1]] != q) {
      puts("-1");
      return 0;
    }
  }
  if(f[2]) {
    if(d[0] != q) {
      puts("-1");
      return 0;
    }
  }
  if(f[3]) {
    if(d[1] != q) {
      puts("-1");
      return 0;
    }
  }
  */

  memset(r,0,sizeof(r));
  memset(c,0,sizeof(c));
  memset(d,0,sizeof(d));
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      r[i] += g[i][j];
      c[j] += g[i][j];
      if(i == j) d[0] += g[i][j];
      if((j+i) == (n+1)) d[1] += g[i][j];
    }
  }

  
  
  if(d[0] != sum || d[1] != sum) {
    puts("-1");
    return 0;
  }
  
  for(int i = 1; i <= n; i++) {
    if(r[i] != sum || c[i] != sum) {
      puts("-1");
      return 0;
    }
  }
  
  printf("%I64d\n", resp);
  return 0;
}
  
