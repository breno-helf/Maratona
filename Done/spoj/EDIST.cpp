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

const int MAXN=2123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

string A, B;
int nA, nB;
int dp[MAXN][MAXN];

int solve(int idxA, int idxB) {
  if(idxA == nA && idxB == nB) return 0;
  else if(idxA == nA || idxB == nB) {
    if(idxA == nA) return (nB - idxB);
    else return (nA - idxA);
  }
  else {
    int &res = dp[idxA][idxB];
    if(res != -1) return res;
    if(A[idxA] == B[idxB]) return res = solve(idxA + 1, idxB + 1);
    else return res = min(solve(idxA + 1, idxB + 1) + 1, min(solve(idxA + 1, idxB) + 1, solve(idxA, idxB + 1) + 1));
  }
}

int main() {
  int t;
  for(cin >> t; t; t--) {
    cin >> A >> B;
    nA = A.size();
    nB = B.size();
    memset(dp, -1, sizeof(dp));
    cout << solve(0,0) << '\n';
  }
  return 0;
}


