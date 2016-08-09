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

int n, v[MAXN];
int mem[MAXN][3];
int resp;
int dp(int a, int b){
  if(mem[a][b]!=-1) return mem[a][b];
  
  if(b==2 && (v[a]==0 || v[a]==1)) return mem[a][b] = max(dp(a-1,1), dp(a-1,0));
  if(b==1 && (v[a]==0 || v[a]==2)) return mem[a][b] = max(dp(a-1,0), dp(a-1,2));

  if(b==0) return mem[a][b] = max(dp(a-1,1),dp(a-1,2));
  if(b==1) return mem[a][b] = max(dp(a-1,0)+1,dp(a-1,2)+1);
  else return mem[a][b] = max(dp(a-1,1)+1, dp(a-1,0)+1);
  return 0;
}


int main(){
  scanf("%d", &n);
  memset(mem,-1,sizeof(mem));
  for(int i=1;i<=n;i++) scanf("%d", &v[i]);
  mem[1][0] = 0;
  mem[0][0] = mem[0][1] = mem[0][2] = 0;

  resp = n - max(dp(n,0), max(dp(n,1), dp(n,2)));
  
  printf("%d\n", resp);
  return 0;
}
