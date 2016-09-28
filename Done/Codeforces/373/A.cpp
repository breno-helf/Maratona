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

const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, a[MAXN];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  if(n == 1) {
    if(a[0] == 0) puts("UP");
    else if(a[0] == 15) puts("DOWN");
    else puts("-1");
  }
  else {
    if(a[n-1] == 0) puts("UP");
    else if(a[n-1] == 15) puts("DOWN");
    else if(a[n-1] > a[n-2]) puts("UP");
    else puts("DOWN");
  }
}
