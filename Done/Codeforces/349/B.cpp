#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int n,l[MAXN];
int resp;
int a,b,c;

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%d", &l[i]);
  sort(&l[0],&l[n]);
  a=l[n-1];
  b=0;
  for(int i=0;i<n-1;i++) b+=l[i];
  resp=abs(a-b)+1;
  printf("%d\n", resp);
  return 0;
}

