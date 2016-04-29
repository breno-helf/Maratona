#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

char a[MAXN],b[MAXN];

int main(){
  scanf("%s", a);
  scanf("%s", b);
  if(strcmp(a,b)==0) printf("%s\n", a);
  else printf("1\n");
  return 0;
}


