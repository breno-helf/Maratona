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

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int crivo[MAXN];
int n, m, p[50], t[50];

vector<int> prime;
vector<pii> dp[50];
vector<pii> dt[50];

map< map<int,int>, int> ex;

int main() {

  for(int i = 2; i*i <= 1000000000; i++) {
    if(crivo[i] == 0) {
      prime.pb(i);
      for(int k = i*i; k <= 1000000; k += i) crivo[k] = i;
    }
  }

  scanf("%d%d", &n, &m);

  int e = 0;
  for(int i = 0; i < n; i++){
    scanf("%d", &p[i]);
  }
  for(int i = 0; i < m; i++){
    scanf("%d", &t[i]);
  }

  for(int i = 0; i < n; i++) {
    int num = p[i];

    dp[i].pb(pii(1,0));
    for(int d : prime) {
      int cnt = 0;
      while(!(num%d)){
	cnt++;
	num /= d;
      }
      if(cnt > 0) dp[i].pb(pii(d,cnt));
    }
    if(num > 1) dp[i].pb(pii(num,1));
  }

  for(int i = 0; i < m; i++) {
    int num = t[i];

    dt[i].pb(pii(1,0));
    for(int d : prime) {
      int cnt = 0;
      while(!(num%d)){
	cnt++;
	num /= d;
      }
      if(cnt > 0) dt[i].pb(pii(d,cnt));
    }
    if(num > 1) dt[i].pb(pii(num,1));
  }


  for(int h = 1; h < (1<<n); h++) {
    map<int,int> cmb;
    
    for(int i = 0; i < n; i++) {
      if(h&(1<<i)) {
	for(auto g : dp[i]) {
	  cmb[g.first] += g.second;

	}
      }
    }
    ex[cmb] = h;

  }
  
  for(int h = 1; h < (1<<m); h++) {
    map<int,int> cmb;
    
    for(int i = 0; i < m; i++) {
      if(h&(1<<i)) {
	for(auto g : dt[i]) {
	  cmb[g.first] += g.second;

	}
      }
    }
    if(ex[cmb] != 0){

      printf("Y\n");
      int s = ex[cmb];
      int nums = __builtin_popcount(s), numh = __builtin_popcount(h);
      printf("%d %d\n", nums, numh);
      int cnt = 1;
      for(int i = 0; i < n; i++) {
	if(s&(1<<i)) {
	  printf("%d%c", p[i], (cnt==nums) ? '\n' : ' ');
	  cnt++;
	}
      }
      cnt = 1;
      for(int i = 0; i < m; i++) {
	if(h&(1<<i)) {
	  printf("%d%c", t[i], (cnt==numh) ? '\n' : ' ');
	  cnt++;
	}
      }
      
      return 0;
    }

  }
  
  printf("N\n");
  return 0;
}

