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

const int MAXN=5123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n;
ll dp[MAXN];
string s;

ll solve(int idx) {
  if(idx == n) return 1;
  else {
    ll &res = dp[idx];
    if(res != -1) return res;
    else {
      if(s[idx] == '0') return 0;
      else if(idx == (n-1)) return 1;
      else if(s[idx] == '1') {
	return res = solve(idx + 1) + solve(idx + 2);
      }
      else if(s[idx] == '2') {
	if(s[idx + 1] <= '6') return res = solve(idx + 1) + solve(idx + 2);
	else return res = solve(idx + 1);
      }
      else {
	return res = solve(idx + 1);
      }
    }
  }
}

int main() {
  while(cin >> s) {
    memset(dp, -1, sizeof(dp));
    if(s[0] == '0') break;
    n = s.size();

    cout << solve(0) << endl;
  }
  return 0;
}
