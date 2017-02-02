#include <bits/stdc++.h>
using namespace std;
	
typedef pair<int, int> pii;
const int MAXN = 205;

int n, m;
set<pii> s;
bitset<MAXN> v[MAXN];

int proc() {
	for (int i = 1; i <= n; i++) {
		v[i].reset();
		v[i].set(i);
	}

	for (auto it = s.rbegin(); it != s.rend(); it++) {
		v[it->second] |= v[it->first];
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += v[i].count() - 1;
	}

	return cnt;
}

int main()
{
	ifstream cin("settling.in");
	ofstream cout("settling.out");
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		s.insert(pii(b, a));
	}

	cout << proc() << "\n";

	char op;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> op >> a >> b;
		if (op == '+') {
			s.insert(pii(b, a));
			cout << proc() << "\n";
		} else if (op == '-') {
			s.erase(s.find(pii(b, a)));
			cout << proc() << "\n";
		} else {
			if (v[a][b]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}