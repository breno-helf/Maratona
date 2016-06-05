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

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int v[MAXN], n, t, resp;
int q[3*MAXN];

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    int ini = 0, fim = 0;
    resp = 0;
    for(int i=1;i<=n;i++){
      scanf("%d", &v[i]);
      if((fim-ini)==3){
	int val = q[ini];
	int e = 0;
	for(int k=ini+1;k<fim;k++) if(q[k]!=val) e=1;
	if(!e) resp = 1;
	ini++;
      }
      q[fim++] = v[i];
    }
    if((fim-ini)==3){
      int val = q[ini];
      int e = 0;
      for(int k=ini+1;k<fim;k++) if(q[k]!=val) e=1;
      if(!e) resp = 1;
      ini++;
    }
    if(resp) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
