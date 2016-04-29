#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=20;
const int INF=0x3f3f3f3f;

int main(){
  int n;
  int t=1;
  while(1){
    scanf("%d", &n);
    if(n==-1) break;
    printf("Teste %d\n", t++);
    printf("%d\n\n", ((1<<n)+1)*((1<<n)+1));
  }
  return 0;
}
