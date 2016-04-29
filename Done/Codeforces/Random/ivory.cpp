#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1213;
const int INF=0x3f3f3f3f;

int a,b,c;

int main(){
  int resp=0;
  int div=0;
  scanf("%d%d%d", &a, &b, &c);
  for(int i=0;i<=c;i+=a) if((c-i)%b==0) resp=1;
  if(resp) printf("Yes\n");
  else printf("No\n");
}

