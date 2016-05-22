//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=123124;
const int INF=0x3f3f3f3f;


int a, b, c, resp=0;


int main(){
  scanf("%d%d%d", &a, &b, &c);
  if(c==0){
    if(a==b) printf("YES\n");
    else printf("NO\n");
  }
  else{
    if((b-a)/c>=0 && (b-a)%c==0 ) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}



