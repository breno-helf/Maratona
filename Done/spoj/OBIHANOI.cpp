//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;

int n;

int main(){
  int t = 1;
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    printf("Teste %d\n%lld\n\n", t++, (ll)((1<<n) - 1));
  }
  return 0;
}
    


