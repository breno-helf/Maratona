//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
ll k;
int a[MAX];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
	cin >> a[i];

    if (k >= n) {
	
	cout << n << '\n';

    } else {
	int cnt = 3 * n;
	queue<int> Q;
	int p1 = 1;
	int p2 = 2;
	for (int i = 3; i <= n; i++) Q.push(i);
	int winner = -1;
	int wins = 0;

	int best = 0;
	int guy = -1;
	while (cnt--) {
	    if (a[p1] > a[p2]) {
		if (winner == p1) wins++;
		else {
		    winner = p1;
		    wins = 1;
		}
	    } else {
		if (winner == p2) wins++;
		else {
		    winner = p2;
		    wins = 1;
		}
	    }

	    if (wins > best) {
		best = wins;
		guy = winner;
	    }

	    if (best == k) break;

	    if (winner == p1) {
		Q.push(p2);
		p2 = Q.front();
		Q.pop();
	    } else {
		Q.push(p1);
		p1 = Q.front();
		Q.pop();
	    }
	}

	if (best == k) cout << a[guy] << '\n';
	else cout << n << '\n';
    }
}


