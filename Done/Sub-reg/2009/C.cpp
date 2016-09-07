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

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int a[MAXN], b[MAXN], n, m, ta, tb;

set<int> A;
set<int> B;

int main() {
  while(1) {
    scanf("%d %d", &n, &m);
    if( n== 0 && m == 0) break;
    ta = 0;
    tb = 0;
    A.clear();
    B.clear();
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      A.insert(a[i]);
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", &b[i]);
      B.insert(b[i]);
    }
    for(auto e : A) {
      if(B.find(e) == B.end()) {
	ta++;
      }
    }
    for(auto e : B) {
      if(A.find(e) == A.end()) {
	tb++;
      }
    }
    printf("%d\n", min(ta, tb));
  }
  return 0;
}
