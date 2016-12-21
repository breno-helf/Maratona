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

ll n, m, k;
ll x, s;

ll a[MAXN], b[MAXN], c[MAXN], d[MAXN];

ll resp;

int main() {
  cin >> n >> m >> k;
  cin >> x >> s;
  resp = n*x;
  for(int i = 1; i <= m; i++) 
    cin >> a[i];
  for(int i = 1; i <= m; i++)
    cin >> b[i];

  for(int i = 1; i <= k; i++)
    cin >> c[i];
  for(int i = 1; i <= k; i++)
    cin >> d[i];

  for(int i = 1; i <= m; i++) {
    if(b[i] <= s) {      
      ll ini = 1, fim = k, r = s - b[i];
      while(ini < fim) {
        ll meio = (ini + fim + 1)/2;
        if(d[meio] <= r)
          ini = meio;
        else
          fim = meio - 1;
      }
      if(d[ini] <= r) {
        if(n >= c[ini])        
          resp = min(resp, a[i]*(n - c[ini]));
        else
          resp = 0;
      }
    }
  }
  for(int i = 1; i <= m; i++) {
    if(b[i] <= s)
      resp = min(resp, a[i]*n);
  }
  for(int i = 1; i <= k; i++) {
    if(d[i] <= s)
      resp = min(resp, x*(n - c[i]));
  }

  cout << resp << '\n';
}



