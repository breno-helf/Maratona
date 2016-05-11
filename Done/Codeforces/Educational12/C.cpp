#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=212345;
const int INF=0x3f3f3f3f;

char s[MAXN];

int main(){
  scanf("%s", s);
  int tam=strlen(s);
  int eq=1;
  for(int i=1;i<tam;i++){
    if(s[i]==s[i-1]){
      eq++;
      if(eq==3){
	char k='a';
	while(k==s[i]) k++;
	s[i-1]=k;
	eq=1;
      }
    }
    else{
      if(eq>1){
	char k='a';
	while(k==s[i-2] || k==s[i]) k++;
	s[i-1]=k;
	eq=1;
      }
    }
  }
  if(eq>1){
    char k='a';
    while(k==s[tam-2]) k++;
    s[tam-1]=k;
  }
  //  debug("%d\n", eq);
  printf("%s\n", s);
  return 0;
}


