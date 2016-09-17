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

int n, c, a[MAXN];
int resp, at;


int main() {
  scanf("%d%d", &n, &c);
  resp = at = 1;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 1; i < n; i++) {
    if((a[i] - a[i-1]) > c) at = 1;
    else at++;
  }
  printf("%d\n", at);
}
