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

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

string s;
int mx, tam;
map<int, vector<string> > d;

int rec(int ini, int word, int nxt, int t, int p) {
  //debug("args %d %d %d %d %d\n", ini, word, nxt, t, p);
  //cout << "deb " << s.substr(ini, word - ini) << ' ';
  //cout << '\n';
  //fflush(stdout);
  int fil = stoi(s.substr(word + 1, nxt - word - 1));
  d[p].pb(s.substr(ini, word - ini));
  mx = max(mx, p);
  for(int k = 0; k < fil; k++) {
    int i = nxt;
    int c = 0, w = i;
    int j = i;
    while(c < 2) {
      if(s[j] == ',' || j == tam)
        c++;
      j++;
      if(c < 1) w++;
    }
    nxt = rec(nxt, w, j, t, p + 1);
  }
  return nxt;
}

int main() {
  cin >> s;
  mx = 1;
  tam = s.size();
  int t = 0, i = 0;
  while(i < tam) {
    int c = 0, w = i;
    int j = i;
    while(c < 2) {
      if(s[j] == ',' || j == tam)
        c++;
      j++;
      if(c < 1) w++;
    }
    i = rec(i, w, j, t++, 1); 
  }
  cout << mx << '\n';
  for(auto e : d) {
    for(auto k : e.second)
      cout << k << ' ';
    cout << '\n';
  }
}

