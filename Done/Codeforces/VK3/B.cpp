//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int n, m, resp, A, B;

int main(){
  resp = 0;
  scanf("%d%d", &n, &m);
  A = 1;
  B = n;
  for(int i=0;i<m;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a>b) swap(a,b);
    A = max(A,a);
    B = min(B,b);
  }
  printf("%d\n", max(0,B-A));
  return 0;
}
    


