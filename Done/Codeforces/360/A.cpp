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

int n, d;

char s[MAXN];

int main() {
  int resp = 0;
  int at = 0;
  
  scanf("%d%d", &n, &d);
  for(int i = 0; i < d; i++) {
    int num = 0;
    for(int k = 0; k < n; k++) {
      scanf(" %c", &s[k]);
      if(s[k] == '1') num++;
    }
    if(num == n) at = 0;
    else at++;
    resp = max(resp, at);
  }
  printf("%d\n", resp);
}
