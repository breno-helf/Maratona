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

int n, v[MAXN], resp, a;

map<int,int> pos;

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &v[i]);
    pos[v[i]] = i;
  }
  a = 1;
  resp = INF;

  for(int i=1;i<=n;i++){
    if(pos[i+1] > pos[i]) a++;
    else a = 1;
    resp = min(resp,n-a);
  }
  
  printf("%d\n", resp);
  return 0;
}

