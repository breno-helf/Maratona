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


int n, x[MAXN], q;

int main(){
  scanf("%d", &n);
  for (int i=0; i<n;i++) scanf("%d", &x[i]);
  sort(x, x+n);
  scanf("%d", &q);
  for(int i=0;i<q;i++){
    int m;
    scanf("%d", &m);
    int resp = upper_bound(x, x+n, m) - x;

    printf("%d\n", resp);
  }

  return 0;
}






