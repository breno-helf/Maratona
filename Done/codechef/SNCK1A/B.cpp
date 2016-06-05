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

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int vet[MAXN], n;

char resp[MAXN];

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    memset(resp,0,sizeof(resp));
    int alf = 0, tam = 0;;
    while(n--){
      resp[tam++] = 'a'+alf;
      alf++;
      if(alf==26) alf = 0;
    }
    printf("%s\n", resp);
  }
    return 0;
}
