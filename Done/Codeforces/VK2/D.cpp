//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

int n, q, d[MAXN];
int mve, mvo;

int main(){
  mve = 0;
  mvo = 0;
  scanf("%d%d", &n, &q);
  for(int i=0;i<q;i++){
    int a, b;
    scanf("%d", &a);
    if(a==2){
      if(mve%2)
	mve = (mve+1)%n;
      else
	mve = (mve-1)%n;
      if(mvo%2)
	mvo = (mvo-1)%n;
      else
	mvo = (mvo+1)%n;
    }
    else{
      scanf("%d", &b);
      mve = ((mve+b) + n)%n;
      mvo = ((mvo+b) + n)%n;
    }
  }
  int pos;
  for(int i=1;i<=n;i++){
    if(i%2){
      pos=(i+mvo)%n;
      if(!(pos)) pos = n;
      d[pos] = i;
    }
    else{
      pos=(i+mve)%n;
      if(!(pos)) pos = n;
      d[pos] = i;
    }
  }
  for(int i=1;i<=n;i++) printf("%d ", d[i]);
  printf("\n");
  return 0;
}


