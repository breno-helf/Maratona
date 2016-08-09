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

const int MAXN=212345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, x[MAXN], resp;

char s[MAXN];

int main(){
  resp = INF;
  int c = 1;
  scanf("%d", &n);
  scanf("%s", s);
  if(n==1){
    puts("-1");
    return 0;
  }
  for(int i=0;i<n;i++){
    scanf("%d", &x[i]);
    if(s[i]=='L' && i!=0){
      if(s[i-1]=='R'){
	resp = min(resp, (x[i] - x[i-1])/2);
	c = 0;
      }
    }
  }
  if(!c) printf("%d\n", resp);
  else printf("-1\n");
  return 0;
}




