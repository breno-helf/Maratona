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

int n, a;

int main() {
  int at = 1, resp = -1, last = INF;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    if(a > last) at++;
    else at = 1;
    last = a;
    resp = max(resp, at);
  }
  cout << resp << endl;
}


