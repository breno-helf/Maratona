#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int g[MAX][MAX];
int t;
string s;
int dy[][4] = {
  {0, 1, 0, -1},
  {1, 0, -1, 0},
  {0, -1, 0, 1},
  {-1, 0, 1, 0},
};

int dx[][4] = {
  {1, 0, -1, 0},
  {0, -1, 0, 1},
  {-1, 0, 1, 0},
  {0, 1, 0, -1},
};

int r, d;

int valid (int x, int y) {
  return (x >= 0 && x < 100 && y >= 0 && y < 100);
}

bool walk (int st) {
  int dir = 0;
  int nd;
  int tam = s.size();
  g[st][0] = 1;
  int x = st, y = 1;
  for (int i = 1; i < tam; i++) {
    g[x][y] = 1;
    debug ("%c %d -- %d %d\n", s[i], dir, x, y);
    r = max(r, y);
    d = max(d, x);
    if (s[i] == 'R')  {
      nd = 0;
    }
    else if (s[i] == 'F')  {
      nd = 1;
    }
    else if (s[i] == 'L')  {
      nd = 2;
    }
    else if (s[i] == 'B')  {
      nd = 3;
    }

    for (int k = 0; k < nd; k++) {
      if (g[x + dx[dir][k]][y + dy[dir][k]] != 0) {
	debug ("desocupada %d %d\n", dx[dir][k], dy[dir][k]);
	return false;
      }
    }
    
    if (!valid(x + dx[dir][nd], y + dy[dir][nd])) return false;
    x = x + dx[dir][nd];
    y = y + dy[dir][nd];
    if (nd != 1) {
      if (nd == 0) dir = (dir + 3) % 4;
      else if (nd == 2) dir = (dir + 1) % 4;
      else dir = (dir + 2) % 4;
    }
  }
  return true;
}

int main () {
  cin.sync_with_stdio(false);
  cin >> t;
  cout << t << '\n';
  for (; t; t--) {
    cin >> s;
    for (int i = 1; i < 99; i++) {
      memset(g, 0, sizeof(g));
      r = 0;
      d = i;
      if (walk(i)) break;
    }
    cout << d + 2 << ' ' << r + 2 << '\n';

    for (int i = 0; i <= (d + 1); i++) {
      for (int j = 0; j <= (r + 1); j++) {
    	cout << (g[i][j] ? '.' : '#');
      }
      cout << '\n';
    }
  }
}
