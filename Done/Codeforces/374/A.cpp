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

int n;
char a[MAXN];
vector<int> resp;

int main() {
  scanf("%d", &n);
  scanf(" %s", a);
  int cur = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == 'B') cur++;
    else {
      if(cur > 0) resp.pb(cur);
      cur = 0;
    }
  }
  if(cur > 0) resp.pb(cur);
  int tam = resp.size();
  printf("%d\n", tam);
  for(int i = 0; i < tam; i++) {
    printf("%d%c", resp[i], ((i+1)==tam) ? '\n' : ' ');
  }
}

