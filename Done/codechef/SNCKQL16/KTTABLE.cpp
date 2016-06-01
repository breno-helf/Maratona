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

int n, t, a[MAXN], b[MAXN], c[MAXN];

int main(){
  scanf("%d", &t);
  for(int tt=0;tt<t;tt++){
    scanf("%d", &n);
    int resp = 0;
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
      scanf("%d", &a[i]);
      c[i-1] = a[i] - a[i-1];
    }
    for(int i=0;i<n;i++) scanf("%d", &b[i]);
    for(int i=0;i<n;i++) if(b[i]<=c[i]) resp++;
    printf("%d\n", resp);
  }
  return 0;
}





