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

const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

string m[MAXN][MAXN];

int c, l, vl[MAXN], vc[MAXN];

map<string, int> resp;
map<string, int> line[MAXN], colu[MAXN];
set<string> cnt, numl[MAXN], numc[MAXN];

int main() {
  std::ios::sync_with_stdio(false);
  while(cin >> l >> c) {
    for(int i = 0; i < MAXN; i++) {
      line[i].clear();
      colu[i].clear();
      numl[i].clear();
      numc[i].clear();
    }
    resp.clear();
    
    for(int i = 0; i < l; i++) {
      for(int j = 0; j < c; j++) {
	cin >> m[i][j];
	line[i][m[i][j]]++;
	colu[j][m[i][j]]++;
	cnt.insert(m[i][j]);
	numl[i].insert(m[i][j]);
	numc[j].insert(m[i][j]);
      }
      cin >> vl[i];
    }

    for(int j = 0; j < c; j++) {
      cin >> vc[j];
    }
    int tot = cnt.size();
    cnt.clear();
    int cur = 0;
    while(cur < tot) {
      string h;
      int num, val;
      int find = 0;
      for(int i = 0; i < l; i++) {
	if((int)numl[i].size() == 1) {
	  for(auto e : line[i]) {
	    if(e.second != 0) {
	      h = e.first;
	      num = e.second;
	      find++;
	      break;
	    }
	  }
	  val = vl[i]/num;
	  break;
	}
      }
      if(!find) {
	for(int j = 0; j < c; j++) {
	  if((int)numc[j].size() == 1) {
	    for(auto e : colu[j]) {
	      if(e.second != 0) {
		h = e.first;
		num = e.second;
		find++;
		break;
	      }
	    }
	    val = vc[j]/num;
	    break;
	  }
	}
      }

      cur++;
      resp[h] = val;
      for(int i = 0; i < l; i++) {
	for(int j = 0; j < c; j++) {
	  if(m[i][j] == h) {
	    vl[i] -= val;
	    vc[j] -= val;
	    line[i][h]--;
	    colu[j][h]--;
	  }
	}
      }

      for(int i = 0; i < l; i++) if(numl[i].find(h) != numl[i].end()) numl[i].erase(h);

      for(int j = 0; j < c; j++) if(numc[j].find(h) != numc[j].end()) numc[j].erase(h);
    }

    for(auto p : resp) {
      cout << p.first << ' ' << p.second << '\n';
    }
  }
  return 0;
}

    
