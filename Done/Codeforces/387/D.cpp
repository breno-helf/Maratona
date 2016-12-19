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


int n, k, a[MAXN];
vector<int> d;
int resp;
int main() {
  scanf("%d%d", &n, &k);
  int prev = -1, mp = 0;
  resp = INF;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] = (a[i] < 0);
    if(a[i] && mp) d.pb(i - prev - 1);
    if(a[i]) {
      prev = i;
      mp++;
    }
  }
  if(!mp) {
    puts("0");
    return 0;
  }
  sort(d.begin(), d.end());
  int last = n - prev - 1;
  k -= mp;
  if(k < 0) {
    puts("-1");
    return 0;
  }
  resp = 2 * mp;
  for(auto i : d) {
    if(i <= k) {
      k -= i;
      resp -= 2;
    }
  }
  if(last <= k) {
    k -= last;
    resp--;
  }

  printf("%d\n", resp);
}


