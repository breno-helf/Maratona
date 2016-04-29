#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=50;
const int INF=0x3f3f3f3f;

char s[MAXN][10];
int n,p;
ll apple;
ll resp;

int main(){
  scanf("%d%d", &n, &p);
  resp=0;
  for(int i=0;i<n;i++) scanf("%s", s[i]);
  for(int i=n-1;i>=0;i--){
    if(s[i][4]=='p'){
      resp+=apple*p + p/2;
      apple*=2;
      apple++;
    }
    else{
      resp+=apple*p;
      apple*=2;
    }
  }
  printf("%I64d\n", resp);
  return 0;
}









