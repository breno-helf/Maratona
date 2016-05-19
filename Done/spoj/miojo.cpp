//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1234;
const int INF=0x3f3f3f3f;

int a, b, c, resp;

int xEuclid(int x, int y, int k){
  int ret1=INF, ret2=INF;
  for(int i=0; i<y ; i++){
    if( (x*i)%y==k ){
      ret1 = x*i;
      break;
    }
  }
  for(int i=0; i<x ; i++){
    if( (y*i)%x==k ){
      ret2 = y*i;
      break;
    }
  }
  return min(ret1, ret2);
}

int main(){
  scanf("%d%d%d", &c, &a, &b);
  resp = xEuclid(a, b, c);
  printf("%d\n", resp);
  return 0;
}




