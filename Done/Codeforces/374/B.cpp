//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, k;
string t[MAXN], p;
int s[MAXN];

int main() {
  //  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> t[i];
    s[i] = -t[i].size();
  }
  cin >> p;
  int tam = -p.size();
  sort(s, s + n);
  int num = upper_bound(s, s + n, tam) - (s + n);
  num = abs(num);
  debug("--> %d\n", num);
  int men = num + (num/k)*5 + 1;
  num = lower_bound(s, s + n, tam) - (s + n - 1);
  num = abs(num);
  debug("--> %d\n", num);
  int mx = num + (num/k)*5 + 1;
  cout << men << ' ' << mx << '\n';
}
