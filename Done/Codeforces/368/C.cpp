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

const int MAXN=12312;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll n;
ll a, b;

int main() {
  cin >> n;
  if(n <= 2) {
    cout << "-1" << '\n';
    return 0;
  }
  if(n%2) {
    a = ((n*n) - 1)/2;
    b = a + 1;
  }
  else {
    a = ((n*n)/2 - 2)/2;
    b = a + 2;
  }

  cout << a << ' ' << b << '\n';
  return 0;
}
