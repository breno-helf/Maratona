#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int L, S, M, D, B;
int s[MAX], m[MAX], d[MAX], b[MAX];
int u[MAX * MAX], v[MAX * MAX];

ll resp;

int bb (ll x, int *a, int tam) {
  int l = 1, r = tam;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if ((x + (ll)a[mid]) > (ll)L) r = mid - 1;
    else l = mid;
  }
  if ((ll)a[l] + x <= (ll)L) return l;
  else return 0;
}

int main () {
  cin.sync_with_stdio(false);
  cin.tie(0);
  
  while (true) {
    cin >> L >> S >> M >> D >> B;
    if (L == 0 && S == 0 && M == 0 && D == 0 && B == 0) break;

    
    for (int i = 1; i <= S; i++)
      cin >> s[i];

    for (int i = 1; i <= M; i++)
      cin >> m[i];

    for (int i = 1; i <= D; i++)
      cin >> d[i];

    for (int i = 1; i <= B; i++)
      cin >> b[i];

    int tamU = 1;

    for (int i = 1; i <= S; i++)
      for (int j = 1; j <= M; j++)
	u[tamU++] = s[i] + m[j];

    int tamV = 1;
    
    for (int i = 1; i <= D; i++)
      for (int j = 1; j <= B; j++)
	v[tamV++] = d[i] + b[j];


    for (int i = 1; i < tamU; i++) {
      debug ("%d ", u[i]);
    }
    debug ("\n");

    
    sort (u + 1, u + tamU);
    sort (v + 1, v + tamV);
    
    resp = 0;

    for (int i = 1; i < tamU; i++) {
      resp += (ll)(bb(u[i], v, tamV - 1));
    }

    cout << resp << '\n';
  }
  
  return 0;
}
