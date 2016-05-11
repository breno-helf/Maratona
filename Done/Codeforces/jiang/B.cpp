#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

char s[MAXN],t[MAXN];

int c,resp,k0,k1,kq,nums,numt;

int main(){
  scanf("%d", &c);
  for(int tt=1;tt<=c;tt++){
    k0=0;
    k1=0;
    kq=0;
    resp=0;
    nums=0;
    numt=0;
    scanf("%s", s);
    scanf("%s", t);
    int tam=strlen(s);
    for(int i=0;i<tam;i++){
      if(s[i]=='1') nums++;
      if(t[i]=='1') numt++;
      if(s[i]!=t[i]){
	if(s[i]=='0') k0++;
	else if(s[i]=='1') k1++;
	else kq++;
      }
    }
    if(nums>numt){
      printf("Case %d: ", tt);
      printf("-1\n");
      continue;
    }
    printf("Case %d: ", tt);
    resp=min(k0,k1)+( (k1>k0) ? k1-k0+kq : k0-k1+kq);
    printf("%d\n", resp);
  }
  return 0;
}

