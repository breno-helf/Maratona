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

char s[MAXN][15];
int n, b[MAXN], a[MAXN];

int main(){
  int e = 0;
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%s%d%d", s[i], &b[i], &a[i]);
    if(b[i]>=2400 && a[i]>b[i]) e = 1;
  }
  if(e) puts("YES");
  else puts("NO");
  return 0;
}
      

