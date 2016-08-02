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

int n, m;
ll respn,respm;
set<int> x, y;

int main(){
  scanf("%d%d", &n, &m);
  respn = n; respm = n;
  for(int i=0;i<m;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    if(x.find(a)==x.end()) x.insert(a), respn--;
    if(y.find(b)==y.end()) y.insert(b), respm--;
    printf("%I64d%c", respm*respn, ((i==(m-1)) ? '\n' : ' '));
  }
  return 0;
}




