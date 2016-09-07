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

int n, tempo, num;

map<string, vector<string> > adj;

set<string> food;

map<string, int> low, d, marc, comp;

stack<string> st;

void scc(string u) {
  st.push(u);
  low[u] = d[u] = tempo++;
  marc[u] = 1;
  for(auto v : adj[u]) {
    if(!marc[v]) {
      scc(v);
      low[u] = min(low[u], low[v]);
    }
    else {
      low[u] = min(low[u], d[v]);
    }
  }

  if(low[u] == d[u]) {
    string a = "";
    while(a != u) {
      a = st.top();
      d[a] = INF;
      comp[a] = num;
      st.pop();
    }
    num++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  while(cin >> n) {
    int resp = 1;
    adj.clear();
    food.clear();
    low.clear();
    marc.clear();
    d.clear();
    comp.clear();
    while(!st.empty()) st.pop();

    tempo = 1;
    num = 1;
    
    for(int i = 0; i < n; i++) {
      string a, b;
      cin >> a >> b;
      if(a[0] == '!') {
	int tam = a.size();
	adj[a.substr(1, tam - 1)].pb(b);
	food.insert(a.substr(1, tam - 1));
      }
      else {
	adj["!" + a].pb(b);
	food.insert(a);
      }

      if(b[0] == '!') {
	int tam = b.size();
	adj[b.substr(1, tam - 1)].pb(a);
	food.insert(b.substr(1, tam - 1));
      }
      else {
	adj["!" + b].pb(a);
	food.insert(b);
      }
    }

    for(auto i : food) {
      if(marc[i] == 0) scc(i);
      if(marc["!" + i] == 0) scc(i);
    }

    for(auto i : food) {
      if(comp[i] == comp["!" + i]) {
	resp = 0;
	break;
      }
    }

    cout << "Instancia " << t++ << '\n';
    
    if(resp) cout << "sim" << '\n' << '\n';
    else cout << "nao" << '\n' << '\n';
  }
  return 0;
}
