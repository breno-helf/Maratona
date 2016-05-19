//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;

int n, m, a, b, c, d;

int main(){
  scanf("%d%d", &n, &m);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if(m<=n || n==4) printf("-1\n");
  else{
    printf("%d %d", a, c);
    for(int i=1;i<=n;i++) if(i!=a && i!=b && i!=c && i!=d) printf(" %d", i);
    printf(" %d %d\n", d, b);
    printf("%d %d", c, a);
    for(int i=1;i<=n;i++) if(i!=a && i!=b && i!=c && i!=d) printf(" %d", i);
    printf(" %d %d\n", b, d);
  }
  return 0;
}
