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

int n, a[MAXN];
set<int> s;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s.insert(a[i]);
  }
  if(s.size() > 3) {
    puts("NO");
  }
  else {
    if(s.size() < 3) 
      puts("YES");
    else {
      int d[5], cnt = 0;;
      for(auto i : s) {
	d[cnt++] = i;
      }
      if(d[1] - d[0] == d[2] - d[1]) {
	puts("YES");
      }
      else {
	puts("NO");
      }
    }
  }
}


