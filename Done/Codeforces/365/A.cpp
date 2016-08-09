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


int m[MAXN], c[MAXN], mi, ch;
int n;

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> m[i] >> c[i];
    if(m[i]>c[i]) mi++;
    else if(m[i]<c[i]) ch++;
  }
  if(mi>ch) puts("Mishka");
  else if(mi<ch) puts("Chris");
  else puts("Friendship is magic!^^");
  return 0;
}
  





