//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

int n,mx,mn;

int main(){
  scanf("%d", &n);
  mx=mn=0;
  for(int i=1;i<=n;i++){
    if(i%7<=2 && i%7>0) mx++;
    if(i%7==0 || i%7==6) mn++;
  }
  printf("%d %d\n", mn, mx);
  return 0;
}




