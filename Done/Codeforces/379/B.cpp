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

const int MAXN=5123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll k2, k3, k5, k6;
ll resp;

int main() {
  cin >> k2 >> k3 >> k5 >> k6;
  resp = 0;
  if(k2 && k5 && k6) {
    int add = (min(k2, min(k5, k6)));
    resp += 256*add;
    k2 -= add;
  }
  if(k3 && k2) {
    int add = min(k3, k2);
    resp += 32*add;
  }
  cout << resp << '\n';
}



