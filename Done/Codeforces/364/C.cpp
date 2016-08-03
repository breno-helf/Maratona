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

char s[MAXN];

int n, resp;

set<char> pk;

map<char,int> num;

int main(){
  scanf("%d", &n);
  scanf("%s", s);
  for(int i=0;i<n;i++) pk.insert(s[i]);
  int ini = 0, fim = 0, all = pk.size(), cur = 0;
  resp = INF;
  while(ini<=fim && fim <= n){
    if(cur < all){
      num[s[fim]]++;
      if(num[s[fim]]==1) cur++;
      fim++;
    }
    else{
      num[s[ini]]--;
      if(num[s[ini]]==0) cur--;
      ini++;
    }
    if(cur==all) resp = min(resp, fim - ini);
  }
  printf("%d\n", resp);
  return 0;
}






