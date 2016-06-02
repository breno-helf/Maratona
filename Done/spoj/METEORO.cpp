//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

struct point{
  int x;
  int y;
};

point e, d, m;

int n, resp;

bool hit(point a){
  if(a.y>=d.y && a.y<=e.y && a.x>=e.x && a.x<=d.x) return 1;
  else return 0;
}

int main(){
  int t = 1;
  while(1){
    scanf("%d%d%d%d", &e.x, &e.y, &d.x, &d.y);
    if(e.x==0 && e.y==0 && d.x==0 && d.y==0) break;
    scanf("%d", &n);
    resp = 0;
    for(int i=0;i<n;i++){
      scanf("%d%d", &m.x, &m.y);
      if(hit(m)) resp++;
    }
    printf("Teste %d\n%d\n\n", t++, resp);
  }
  return 0;
}
