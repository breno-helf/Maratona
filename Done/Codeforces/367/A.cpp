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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int a, b, n;

int main(){
  scanf("%d%d", &a, &b);
  scanf("%d", &n);
  double resp = INF;

  for(int i =0; i<n;i++){
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    x = x-a;
    y = y-b;
    double cur = (double)x*(double)x + (double)y*(double)y;
    cur = sqrt(cur);
    cur = cur/(double)v;
    resp = min(cur,resp);
  }

  printf("%lf\n", resp);
  return 0;
}




