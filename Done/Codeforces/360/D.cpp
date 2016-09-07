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

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, t;
int c[MAXN], crivo[MAXN];

map<int, int> an;
map<int, int> fac;

int main() {  
  int resp = 1;
  for(int i = 2; i*i < MAXN; i++)
    if(crivo[i] == 0) for(int k = i*i; k < MAXN; k += i) crivo[k] = i;
  
  scanf("%d%d", &n, &t);
  for(int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    int aux = c[i];
    map<int, int> at;
    while(aux > 1) {
      int fat;
      if(crivo[aux] == 0) fat = aux;
      else fat = crivo[aux];
      at[fat]++;
      aux /= fat;
    }
    for(auto e : at) an[e.first] = max(an[e.first], e.second);
  }
  int aux = t;

  while(aux > 1) {
    int fat;
    if(crivo[aux] == 0) fat = aux;
    else fat = crivo[aux];

    fac[fat]++;
    aux /= fat;
  }

  for(auto e : fac) {
    if(an[e.first] < e.second) resp = 0;
  }
  
  if(resp) puts("Yes");
  else puts("No");
}
