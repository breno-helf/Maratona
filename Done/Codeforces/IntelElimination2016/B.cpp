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

int n, p[MAXN];

char s[MAXN][MAXN];
int nv[MAXN];
int resp;
int main() {
  resp = 1;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> p[i];
  char c;
  c = getchar();
  for(int i = 0; i < n; i++) {
    int k = 0;
    while((c = getchar())) {
      if(c == '\n') break;
      s[i][k++] = c;
      if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') nv[i]++;
    }
  }
  for(int i = 0; i < n; i++) {
    //    debug("--> %s\n", s[i]);

    if(p[i] != nv[i]) resp = 0;

  }
  if(resp) cout << "YES" << '\n';
  else cout << "NO" << '\n';
}

