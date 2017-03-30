//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

vector<int> primes;
vector<int> ans;
int crivo[MAX];

int main () {
  for (int i = 2; i * i <= 100000000; i++) {
    if (!crivo[i]) {
      primes.pb(i);
      for (int k = i*i; k <= 10000; k += i) crivo[k] = i;
    }    
  }

  for (int i = 1; i <= 3000; i++) {
    int n = i;
    int p = 0;
    for (int id = 0; n > 1; id++) {
      if (n % primes[id] == 0) p++;
      while (n % primes[id] == 0) {
	n /= primes[id];
      }
    }
    if (p > 2) {
      ans.pb(i);
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    n--;
    cout << ans[n] << '\n';
  }
}
