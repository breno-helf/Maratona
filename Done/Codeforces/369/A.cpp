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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

char c[MAXN][10];

int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf(" %s", c[i]);
  }
  int resp = 0;
  for(int i = 0; i < n; i++) {
    if((c[i][0] == 'O' && c[i][1] == 'O')) {
      resp = 1;
      c[i][0] = c[i][1] = '+';
      break;
    }
    if(c[i][3] == 'O' && c[i][4] == 'O') {
      resp = 1;
      c[i][3] = c[i][4] = '+';
      break;
    }
  }
  if(resp) {
    puts("YES");
    for(int i = 0; i < n; i++) {
      for(int k = 0; k < 5; k++) {
	putchar(c[i][k]);
      }
      printf("\n");
    }
  }
  else {
    puts("NO");
  }
  return 0;
}


