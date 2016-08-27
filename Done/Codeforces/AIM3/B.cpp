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

int n, a;

int v[MAXN];

int main() {
  scanf("%d%d", &n, &a);

  for(int i = 0; i < n; i++) {
    int b;
    scanf("%d", &b);
    v[i] = b;
  }

  if(n == 1) {
    puts("0");
    return 0;
  }
  sort(v, v + n);

  int resp = INF;

  resp = min(resp, abs(v[0] - a) + abs(v[0] - v[n-2]));

  resp = min(resp, abs(v[1] - a) + abs(v[1] - v[n-1]));
    
  resp = min(resp, abs(v[n-2] - a) + abs(v[n-2] - v[0]));
  
  resp = min(resp, abs(v[n-1] - a) + abs(v[n-1] - v[1]));
  
  printf("%d\n", resp);

  return 0;
}


  
  
