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
const ll  INF=(ll)1e16;
const ll  MOD=1000000007;

ll n, c[MAXN];

string s[MAXN], r[MAXN];

ll mem[MAXN][2];

ll dp (int id, int k) {
  ll cost = INF;
  if (id == n-1) {
    return 0;
  }
  if (mem[id][k] != -1) return mem[id][k];
  if (k) {
    if(r[id] <= s[id+1]) cost = min(cost, dp(id+1, 0));
    if(r[id] <= r[id+1]) cost = min(cost, dp(id+1, 1) + c[id+1]);
  }
  else{
    if(s[id] <= s[id+1]) cost = min(cost, dp(id+1, 0));
    if(s[id] <= r[id+1]) cost = min(cost, dp(id+1, 1) + c[id+1]);
  }
  return mem[id][k] = cost;
}



int main(){
  std::ios::sync_with_stdio(false);
  cin >> n;
  memset(mem,-1,sizeof(mem));
  for(int i = 0; i < n; i++) cin >> c[i];
  for(int i = 0; i < n; i++){
    cin >> s[i];
    for(auto it = s[i].rbegin(); it != s[i].rend(); it++){
      r[i] += *it;
    }
  }
  ll resp = INF;
  resp = min(dp(0,0), dp(0,1) + c[0]);
  if(resp == INF) resp = -1;
  cout << resp << '\n';
  return 0;
}









