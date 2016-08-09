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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, g[MAXN][MAXN];

int l[MAXN], c[MAXN];
int tot;

int main(){
  scanf("%d%d", &n, &m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char a;
      scanf(" %c", &a);
      (a=='*') ? g[i][j] = 1 : g[i][j] = 0;
      if(g[i][j]==1){
	l[i]++;
	c[j]++;
	tot++;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int a = l[i] + c[j];
      if(g[i][j]==1) a--;
      if(a==tot){ 
	puts("YES");
	printf("%d %d\n", i+1, j+1);
	return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
  
    



