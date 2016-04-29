#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;

int n,v[MAXN],acc[MAXN],resp;


int main(){
  int t=1;
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    memset(acc,0,sizeof(acc));
    int l=0,r=0;
    int a=1;
    resp=-1;
    int mx=0;
    for(int i=1;i<=n;i++){
      int x,y;
      scanf("%d%d", &x, &y);
      v[i]=x-y;
      mx+=v[i];
      if(mx<0){
	a=i+1;
	mx=0;
      }
      else if(mx>0 && (mx>resp || (mx==resp && i-a>=r-l))){
	  resp=mx;
	  l=a;
	  r=i;
      }
    }
    printf("Teste %d\n", t++);
    (resp==-1) ? printf("nenhum\n") : printf("%d %d\n", l, r);
  }
  return 0;
}
