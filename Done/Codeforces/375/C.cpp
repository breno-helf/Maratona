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

const int MAXN=2123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, a[MAXN];
int d, c, t;
int op;
int qtd[MAXN];
queue<int> need;

int main() {
  scanf("%d%d", &n, &m);
  d = n/m;
  t = n/m + ((n%m == 0) ? 0 : 1);
  c = 0;
  op = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if(a[i] <= m) {
      qtd[a[i]]++;
    }
  }
  for(int i = 1; i <= m; i++) {
    if(qtd[i] < d)
      for(int k = qtd[i]; k < d; k++)
	need.push(i);
  }
  //for(int i = 1; i <= m; i++)
  //if(qtd[i] <= d) need.push(i);
  
  for(int i = 0; i < n; i++) {
    if(a[i] <= m) {
      if(qtd[a[i]] > d && !need.empty()) {
	c++;
	qtd[a[i]]--;
	a[i] = need.front();
	//qtd[a[i]]++;
	need.pop();
      }
    }
    else if(!need.empty()) {
      c++;
      a[i] = need.front();
      //qtd[a[i]]++;
      need.pop();
    }
  }
  printf("%d %d\n", d, c);
  for(int i = 0; i < n; i++)
    printf("%d%c", a[i], (i == (n-1)) ? '\n' : ' ');

  return 0;
}



