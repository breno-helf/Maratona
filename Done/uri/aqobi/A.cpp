//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1231;
const int INF=0x3f3f3f3f;

int s, t, f;
int resp;

int main(){
  scanf("%d%d%d", &s, &t, &f);
  resp = s+t+f;
  if(resp<0) resp+=24;
  resp %= 24;
  printf("%d\n", resp);
  return 0;
}





