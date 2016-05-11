//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=65;
const int INF=0x3f3f3f3f;

int m[MAXN][MAXN], b;
int t;
ll w;

int main(){
  fac[0]=1;
  fac[1]=1;
  scanf("%d", &t);
  for(int tt=1;tt<=t;tt++){
    memset(m,0,sizeof(m));
    scanf("%d%lld", &n, &w);
    printf("Case #%d:", tt);
    if(w==1){
      m[1][n]=1;
      printf(" POSSIBLE\n");
      for(int i=1;i<=n;i++){
	printf("\n");
	for(int k=1;k<=n;k++){
	  printf("%d", m[i][k]);
	}
      }
      printf("\n");
      continue;
    }
    ll num = 1;
    int ar;
    for(int i=2; ; i++){
      num *= (n-i)/(i-1);
      if(num>=m){
	ar = i;
	break;
      }
      if(num<=0){
	ar = -1;
	break;
      }
    }
    if(ar==-1) printf(" IMPOSSIBLE\n");
    else{
      
