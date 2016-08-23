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

const int MAXN=312345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, a[MAXN];

set<int> s;

vector<int> v;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }
 
  sort(a+1,  a+n+1);
  printf("%d\n", a[(n+1)/2]);
  return 0;
}
