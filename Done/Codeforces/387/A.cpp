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

const int MAXN=1231;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


int n, a, b;
int aa, bb;

int main() {
  cin >> n;
  a = 1;
  b = n;
  for(int i = 1; i*i <= n; i++) {
    bb = n/i;
    if(i*bb == n) {
      a = i;
      b = bb;
    }    
  }
  cout << a << ' ' << b << '\n';
}



