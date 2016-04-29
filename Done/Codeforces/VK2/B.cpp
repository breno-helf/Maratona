#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

char s[MAXN];

int n,tam[MAXN],v[MAXN],resp,c;


int main(){
  resp=0;
  c=0;
  v[0]=1;
  scanf("%d", &n);
  scanf("%s", s);
  for(int i=0;i<n;i++) scanf("%d", &tam[i]);
  while(1){
    if(s[c]=='>'){
      c+=tam[c];
      if(c>=n){
	resp=1;
	break;
      }
      if(v[c]==1) break;
      v[c]=1;
    }
    else{
      c-=tam[c];
      if(c<0){
	resp=1;
	break;
      }
      if(v[c]==1) break;
      v[c]=1;
    }
  }
  resp ? printf("FINITE\n") : printf("INFINITE\n");
  return 0;
}
    



