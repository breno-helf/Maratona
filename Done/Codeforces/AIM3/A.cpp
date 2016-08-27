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

int a[MAXN];

int n, b, d;

int resp;

int main() {
  scanf("%d%d%d", &n, &b, &d);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  resp = 0;
  int tot = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] <= b ) tot += a[i];
    if(tot > d) resp ++, tot = 0;
  }

  printf("%d\n", resp);

  return 0;
}

