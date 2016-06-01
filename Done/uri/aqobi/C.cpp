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

int p, ja, jb, r, a;
int resp = 0;

int main(){
  scanf("%d%d%d%d%d", &p, &ja, &jb, &r, &a);
  p ^= 1;
  if ( ( r && a) ) resp = 2;
  else if ( (r && !a) || (!r && a) ) resp = 1;
  else {
    if( (ja+jb)%2 == p ) resp = 1;
    else resp = 2;
  }
  printf("Jogador %d ganha!\n", resp);
  return 0;
}


