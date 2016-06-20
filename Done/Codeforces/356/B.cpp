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

int c[MAXN], n, a;

int main(){
  cin >> n >> a;
  for(int i=1;i<=n;i++){
    cin >> c[i];
  }
  int l = a, r = a, resp = 0;
  while(l>=1 || r<=n){
    if(l==a && r==a && c[a]==1) resp++;
    else{
      if(l>=1 && r<=n){
	if(c[l]==1 && c[r]==1) resp += 2;
      }
      else if(r<=n){
	if(c[r] == 1) resp++;
      }
      else{
	if(c[l]) resp++;
      }
    }
    l--, r++;
  }
  printf("%d\n", resp);
}

