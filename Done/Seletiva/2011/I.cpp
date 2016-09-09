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

pair<pii, int> a[MAXN];
int n;
char ini[10], fim[10];
vector<int> resp;

pii trans(char* i, char* f) {
  int q = 0, w = 0;
  q += ((i[0] - '0')*10 + (i[1] - '0'))*60 + (i[3] - '0')*10 + (i[4] - '0');
  w += ((f[0] - '0')*10 + (f[1] - '0'))*60 + (f[3] - '0')*10 + (f[4] - '0');
  return pii(q,w);
}

int main() {
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++) {
    scanf(" %s %s", ini, fim);
    a[i].first = trans(ini, fim);
    a[i].second = i+1;
  }
  sort(a, a + n);
  int last = INF;
  for(int i = n-1; i >= 0; i--) {
    if(a[i].first.second <= last) {
      resp.pb(a[i].second);
      last = a[i].first.first;
    }
  }
  int tam = resp.size();
  for(int i = tam -1; i >= 0; i--) {
    printf("%d", resp[i]);
    if(i == 0) putchar('\n');
    else putchar(' ');
  }
}
