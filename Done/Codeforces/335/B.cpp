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
const int MAXS=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

char s[MAXS];

int g[MAXN][MAXN], n, m, x, y, p;

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

map<char,int> d;

int main(){
  scanf("%d%d%d%d", &n, &m, &x, &y);
  scanf("%s", s);
  d['U'] = 3;
  d['L'] = 2;
  d['D'] = 1;
  d['R'] = 0;
  int tam = strlen(s);
  p = 1;
  printf("%d ", 1);
  g[x][y] = 1;
  for(int i=0;i<tam-1;i++){
    x += dx[d[s[i]]];
    y += dy[d[s[i]]];
    if(x>n || x<1 || y>m || y<1 || g[x][y] == 1){
      printf("0 ");
      if(x>n) x = n;
      if(x==0) x = 1;
      if(y>m) y = m;
      if(y==0) y = 1;
    }
    else printf("1 "), p++, g[x][y]++;
  }
  printf("%d\n", n*m - p);
  return 0;
}
