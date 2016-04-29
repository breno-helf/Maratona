#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;

int n,a,h,resp;

int main(){
  scanf("%d%d", &n, &a);
  h=n/2;
  if(a%2==0) resp=h-a/2+1;
  else resp=a/2+1;
  printf("%d\n", resp);
  return 0;
}


