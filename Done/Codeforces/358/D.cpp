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
const int MAXK=15;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

char s[MAXN], t[MAXN];

int n, m, kk;

int dp[MAXN][MAXN][MAXK][2], resp;

int solve(int i, int j, int k, int peguei){
  if(dp[i][j][k][peguei]!=-1) return dp[i][j][k][peguei];
  if(i==n || j==m) return 0;
  if(s[i]==t[j]){
    if(peguei) dp[i][j][k][peguei] = solve(i+1,j+1,k,peguei) + 1;
    else if(k) dp[i][j][k][peguei] = solve(i+1,j+1,k-1,1) + 1;    
  }
  return dp[i][j][k][peguei] = max(dp[i][j][k][peguei],max(solve(i+1,j,k,0),solve(i,j+1,k,0)));  
}

int main(){
  scanf("%d%d%d", &n, &m, &kk);
  memset(dp,-1,sizeof(dp));
  scanf(" %s", s);
  scanf(" %s", t);
  resp = solve(0,0,kk,0);
  printf("%d\n", resp);
}
