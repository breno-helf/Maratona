#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

int a,v,f[MAXN],mx;

int main(){
  int t=1;
  while(1){
    scanf("%d%d", &a, &v);
    if(a==0 && v==0) break;
    memset(f,0,sizeof(f));
    mx=-1;
    for(int i=0;i<v;i++){
      int x,y;
      scanf("%d%d", &x, &y);
      f[x]++;
      f[y]++;
      mx=max(mx,max(f[x],f[y]));
    }
    int e=0;
    printf("Teste %d\n", t++);
    for(int i=1;i<=a;i++){
      if(f[i]==mx){
	if(e) printf(" ");
	printf("%d", i);
	e++;
      }
    }
    printf("\n\n");
  }
  return 0;
}
