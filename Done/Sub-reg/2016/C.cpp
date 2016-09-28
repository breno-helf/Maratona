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

const int MAXN=212;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

vector<int> ini;
vector<int> fim;
int sw1[10] = {0, 1, 2, 4, 5, 6, 0, 1, 2, 3};
int sw2[10] = {1, 2, 3, 5, 6, 7, 4, 5, 6, 7};

map< vector<int>, int > dist;

bool eq(vector<int> g, vector<int> h, int sz) {
  /*  
  bool ret = 1;
  for(int i = 0; i < sz; i++)
    if(g[i] != h[i]) ret = 0;

  return ret;
  */
  return (g == h);
}

void dijk() {
  set< pair<int, vector<int> > > q;
  map<vector<int>, int> marc;
  q.insert(mp(0, ini));
  while(!(q.empty())) {
    vector<int> cur;
    cur = q.begin()->second;
    int d = q.begin()->first;
    marc[cur] = 1;
    if(eq(cur, fim, 8)) break;
    vector<int> nxt;
    for(int k = 0; k < 10; k++) {
      int w;
      nxt = cur;
      swap(nxt[sw1[k]], nxt[sw2[k]]);
      w = nxt[sw1[k]] + nxt[sw2[k]];
      if(!(eq(nxt, ini, 8))) {
	if(dist[nxt] == 0) {
	  q.insert(mp((w + d), nxt));
	  dist[nxt] = w + d;
	}
	else if(dist[nxt] > (w + d)) {
	  q.erase(mp(dist[nxt], nxt));
	  dist[nxt] = w + d;
	  q.insert(mp(dist[nxt], nxt));
	}
      }
    }
    q.erase(q.begin());
  }  
}

int main() {
  for(int i = 0; i < 8; i++) {
    int a;
    scanf("%d", &a);
    ini.pb(a);
  }

  for(int i = 0; i < 8; i++) {
    int a;
    scanf("%d", &a);
    fim.pb(a);
  }

  dijk();

  printf("%d\n", dist[fim]);
}
  
