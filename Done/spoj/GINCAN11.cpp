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

int n, m;

int pai[MAXN], h[MAXN], resp;

int raiz(int a){
  if(pai[a]==a) return a;
  return pai[a] = raiz(pai[a]);
}

bool find(int x, int y){
  if(raiz(x)==raiz(y)) return 1;
  return 0;
}

void une(int x, int y){
  x = raiz(x);
  y = raiz(y);
  if(h[x] > h[y]) swap(x,y);
  if(h[x] == h[y]) h[y]++;
  pai[x] = y;
}

int main(){
  scanf("%d%d", &n, &m);
  resp = n;
  for(int i=0;i<=n;i++) pai[i] = i; 
  for(int i=0;i<m;i++){
    int q, w;
    scanf("%d%d", &q, &w);
    if(!find(q,w)){
      une(q,w);
      resp--;
    }
  }
  printf("%d\n", resp);
  return 0;
}




