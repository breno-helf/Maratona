//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=5112345;
const int INF=0x3f3f3f3f;

int n, m;

struct tree{
  int e;
  int d;
};

tree seg[4*MAXN];
char br[MAXN];

void build(int id, int l, int r){
  if(l==r) (br[l]=='(') ? seg[id].e = 1 : seg[id].d = 1;
  else{
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    int nw = min(seg[2*id].e, seg[2*id + 1].d);
    seg[id].e = seg[2*id].e + seg[2*id + 1].e - nw;
    seg[id].d = seg[2*id].d + seg[2*id + 1].d - nw;
  }
}

void up(int id, int l, int r, int pos){
  //  seg[pos].e ^= 1;
  //  seg[pos].d ^= 1;
  if(l==r){
    seg[id].e ^= 1;
    seg[id].d ^= 1;
  }
  else{
    int mid = (l+r)/2;
    if(pos <= mid) up(id*2, l, mid, pos);
    else up(id*2 + 1, mid+1, r, pos);
    int nw = min(seg[2*id].e, seg[2*id + 1].d);
    seg[id].e = seg[2*id].e + seg[2*id + 1].e - nw;
    seg[id].d = seg[2*id].d + seg[2*id + 1].d - nw;
  }
}

int main(){
  for(int t=1;t<=10;t++){
    memset(br,0,sizeof(br));
    printf("Test %d:\n", t);
    scanf("%d", &n);
    scanf("%s", br);
    scanf("%d", &m);
    memset(seg,0,sizeof(seg));
    build(1,0,n-1);

    for(int i=0;i<m;i++){
      int o;
      scanf("%d", &o);
      if(o==0){
	if(seg[1].d==0 && seg[1].e==0) printf("YES\n");
	else printf("NO\n");
      }
      else{
	up(1, 0, n-1, o-1);
      }
    }
    
  }
 return 0;
}
