#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;

char s[MAXN],resp[MAXN],fst;

int t,ind[MAXN],ini;

int main(){
  scanf("%d", &t);
  for(int tt=1;tt<=t;tt++){
    memset(s,0,sizeof(s));
    memset(resp,0,sizeof(resp));
    fst=0;
    memset(ind,0,sizeof(ind));
    scanf("%s", s);
    int tam=strlen(s);
    int fim=0;
    ini=0;
    int updt=0;
    for(int i=0;i<tam;i++){
      if(i==0){
	ind[i]=0;
	ini=0;
	fst=s[i];
      }
      else{
	if(s[i]>=fst){
	  ind[i]=ini-1;
	  ini--;
	  updt++;
      	  fst=s[i];
	}
	else{
	  ind[i]=fim+1;
	  fim++;
	}
      }
    }
    for(int i=0;i<tam;i++){
      resp[ind[i]+updt]=s[i];
      // debug("O indice %d tem %c\n", ind[i]+updt, s[i]);
    }
    printf("Case #%d: %s\n", tt, resp);
  }
  return 0;
}




    



