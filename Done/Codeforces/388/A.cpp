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

int n, k;
vector<int> resp;

int main() {
  cin >> n;
  while(n > 3) {
    resp.pb(2);
    n -= 2;
  }
  if(n == 3)
    resp.pb(3);
  if(n == 2)
    resp.pb(2);
  printf("%d\n", (int)resp.size());
  for(int i : resp) {
    printf("%d ", i);
  }
  printf("\n");
}

