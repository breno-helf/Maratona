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

const int MAXN=50;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll fat[MAXN];

ll f(int x) {
  if(fat[x]) return fat[x];
  else return fat[x] = x*(f(x-1));
}

int main() {
  int n, m;
  fat[0] = 1;
  while(cin >> n >> m) {
    cout << (f(n) + f(m)) << '\n';
  }
}
  

