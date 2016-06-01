#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=3123;
const int INF=0x3f3f3f3f;

int f[MAXN];
int n;
int t;

int main(){
  scanf("%d", &t);
  for(int tt=1;tt<=t;tt++){
    scanf("%d", &n);
    memset(f,0,sizeof(f));
    for(int i=1;i<2*n;i++){
      for(int k=0;k<n;k++){
	int a;
	scanf("%d", &a);
	f[a]=(f[a]+1)%2;
      }
    }
    int p=0;
    int i=1;
    printf("Case #%d:", tt);
    while(p!=n){
      if(f[i]) printf(" %d", i),p++;
      i++;
    }
    printf("\n");
  }
  return 0;
}
