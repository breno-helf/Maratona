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

int n, acc, r[2], b[2];
string c;
int resp1[2], resp2[2];

int main() {
  cin >> n;
  cin >> c;
  //resp1 = resp2 = 0;
  for(int i = 0; i < n; i++) {
    if(i%2) {
      if(c[i] == 'r') resp2[0]++;
      else resp1[0]++;
    }
    else {
      if(c[i] == 'b') resp2[1]++;
      else resp1[1]++;
    }
  }
  cout << min(max(resp1[0],resp1[1]),max(resp2[0], resp2[1])) << '\n';
}
