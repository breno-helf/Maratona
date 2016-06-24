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

int n, a[MAXN], s[MAXN];

vector<pii> op;


int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++) scanf("%d", &a[i]), s[i] = a[i];
  sort(&s[1],&s[n+1]);
  for(int j=n;j>=1;j--){
    for(int i=1;i<j;i++){
      if(a[i]>a[i+1]){
	swap(a[i],a[i+1]);
	printf("%d %d\n", i, i+1);
      }
    }
  }
  return 0;
}
