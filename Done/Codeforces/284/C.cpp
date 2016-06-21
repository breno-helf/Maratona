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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

struct point{
  ll x, y;
};

struct reta{
  ll a, b, c;
};

point home, uni;

ll n;

ll resp;

int main(){
  scanf("%lld%lld", &home.x, &home.y);
  scanf("%lld%lld", &uni.x, & uni.y);
  scanf("%lld", &n);
  resp = 0;
  for(int i=0;i<n;i++){
    reta nw;
    scanf("%lld%lld%lld", &nw.a, &nw.b, &nw.c);
    ll p1, p2;
    p1 = nw.a*home.x + nw.b*home.y + nw.c;
    p2 = nw.a*uni.x + nw.b*uni.y + nw.c;
    if( (p1>0 && p2<0) || (p2>0 && p1<0) ) resp++;
  }

  printf("%lld\n", resp);
}






