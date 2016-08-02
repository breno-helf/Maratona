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

int n, p;

pii c[MAXN];

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &c[i].first);
    c[i].second = i;
  }
  sort(&c[1],&c[n+1]);
  p = n/2;
  for(int i=1;i<=p;i++){
    printf("%d %d\n", c[i].second, c[n-i+1].second);
  }
  return 0;
}
