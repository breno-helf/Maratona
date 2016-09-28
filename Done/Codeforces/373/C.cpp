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

const int MAXN=212345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, t, ini, m;
char c[MAXN];
int up;
int main() {
  scanf("%d%d", &n, &t);
  ini = n;
  up = 0;
  for(int i = 0; i < n; i++) {
    scanf(" %c", &c[i]);
    if(c[i] == '.') ini = i;
  }
  m = ini;
  for(int i = ini + 1; i < n; i++) {
    if(c[i] >= '5') {
      m = i;
      break;
    }
  }
  int j = m;
  while(j > ini && (t>0)) {
    t--;
    if(c[j] >= '5') c[j] = '0';
    else break;
    int e = 0;
    for(int k = j - 1; k > ini; k--) {
      if(c[k] != '9') {
	c[k]++;
	e = 1;
	break;
      }
      else {
	c[k] = '0';
      }
    }
    if(!e) {
      up = 1;
      break;
    }
    j--;
  }
  if(up) {
    for(int k = (ini -1); k >= 0; k--) {
      if(c[k] != '9') {
	c[k]++;
	up = 0;
	break;
      }
      else {
	c[k] = '0';
      }
    }
    if(up) printf("1");
  }
  int end = (m==ini) ? (n - 1) : m;

  for(int i = 0; i < ini; i++) printf("%c", c[i]);
  for(int i = end; i >= ini; i--) {
    if(c[i] != '0') {
      end = i;
      break;
    }
  }
  //  debug("%d %d\n", m, end);
  if(end == ini) end--;
  for(int i = ini; i <= end; i++) printf("%c", c[i]);
  putchar('\n');
}
