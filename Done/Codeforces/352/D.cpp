//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=512345;
const int INF=0x3f3f3f3f;


int n, c[MAXN], d;

int ul[MAXN], ff[MAXN];
int mn;

int main(){
  scanf("%d%d", &n, &d);
  for(int i=0;i<n;i++) scanf("%d", &c[i]);
  sort(c, c+n);
  ul[n-1] = n-1;
  for(int i=n-2;i>=0;i--){
    if(c[i]==c[i+1]) ul[i] = ul[i+1];
    else ul[i] = i;
  }
  ff[0] = 0;
  for(int i=1;i<n;i++){
    if(c[i]==c[i-1]) ff[i] = ff[i-1];
    else ff[i] = i;
  }
  for(int i=0;i<d;i++){
    mn = c[0];
    c[n-1]--;
    if(c[n-1]<mn) c[n-1]++;
    else{
      c[0]++;
      debug("ff swapei %d com %d ( pos[%d]<-->[%d] )\n", c[0], c[ul[0]], 0, ul[0]);
      swap(c[0],c[ul[0]]);
      if(c[ul[ul[0]]]==c[ul[ul[0]]+1]) ul[ul[0]] = ul[ul[0]+1];
      if(c[ff[ul[0]]]==c[ff[ul[0]]-1]) ff[ul[0]] = ff[ul[0]-1];
      ul[0]++;
      debug("ll swapei %d com %d ( pos[%d]<-->[%d] )\n", c[n-1], c[ff[n-1]], n-1, ff[n-1]);
      swap(c[n-1],c[ff[n-1]]);
      if(c[ul[ff[0]]]==c[ul[ff[0]]+1]) ul[ff[0]] = ul[ff[0]+1];
      if(c[ff[ff[0]]]==c[ff[ff[0]]-1]) ff[ff[0]] = ff[ff[0]-1];
      ff[n-1]--;
    }
  }
  sort(c, c+n);
  printf("%d\n", c[n-1] - c[0]);
  return 0;
}




