//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const ll MAXM=2000000009;

ll n,k,resp;
int id[MAXN];

int main(){
  scanf("%I64d%I64d", &n, &k);
  for(int i=1;i<=n;i++) scanf("%d", &id[i]);
  
  ll ini = 0;
  ll fim = n;
  ll meio;
  while(ini<fim){
    meio = (ini + fim + 1)/2;
    ll f = (meio*(meio-1))/2,  l = (meio*(meio+1))/2;
    // if(k>=f && k<=l){
    //    resp = meio;
    //    break;
    // }
    if(l>=k) fim = meio - 1;
    else ini = meio;
  }
  resp = ini;
  int num = k - resp*(resp+1)/2;
  debug("%d\n", num);
  printf("%d\n", id[num]);
  return 0;
}



