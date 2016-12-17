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

int n, m, num;
int g[MAXN][MAXN];
int x, y;
char c;

int main() {
  num = 0;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf(" %c", &c);
      if(c == 'X') {
        g[i][j] = 1;
        num++;
      }
    }
  }
  int aux = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(g[i][j] == 1) {
        x = i;
        y = j;
        aux = 1;
        break;
      }
    }
    if(aux) break;
  }
  aux = 0;
  int r = 0, d = 0;
  while(((x + r) < n) && g[x + r][y]) r++;
  while(((y + d) < m) && g[x][y + d]) d++;
  for(int i = x; i < (x + r); i++) {
    for(int j = y; j < (y + d); j++) {
      if(g[i][j]) aux++;      
    }
  }
  //  debug("[r][d] %d %d\n[aux -- num] %d -- %d\n", r, d, aux, num);
  if(aux == num && (r*d == num))
    puts("YES");
  else
    puts("NO");
}

