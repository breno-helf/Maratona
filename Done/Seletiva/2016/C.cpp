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

int h, w;

int r[MAXN], mx;

int main() {
  scanf("%d%d", &h, &w);
  for(int i = 0; i < h; i++) scanf("%d", &r[i]);
  mx = 0;
  for(int i = 0; i < h; i++) {
    int a;
    scanf("%d", &a);
    a += r[i];
    mx = max(mx, a);
  }
  printf("%lf\n", ((double)(w - mx))/(2.0));
  return 0;
}
    
