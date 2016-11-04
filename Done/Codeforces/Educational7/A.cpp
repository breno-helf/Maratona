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

const int MAXN=211221;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll n;

int main() {
  cin >> n;
  ll k = 1, a = 1;
  while(k < n) {
    k += a;
    a++;
  }
  // (k - 1) --> (a - 1)
    
  //debug("%lld %lld %lld\n", n, k, a);
  ll resp = (a - (k - n));
  if(resp == a) resp = 1;
  cout << resp << '\n';
}

