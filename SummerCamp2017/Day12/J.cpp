#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int MAXN = 1e3+10;
const int MAX = 1e5+10;

int n, sizes, m;
int ans[MAXN];
string s[MAXN];
map<string, pii> mp;
set<int> v[MAX + MAXN];
int _v = 0;

void upd(string& st, int i, bool add) {
	if (add) {
		auto it = mp.find(st);
		if (it == mp.end()) {
			mp[st] = {1, _v++};
			it = mp.find(st);
		} else {
			it->second.first++;
		}

		v[it->second.second].insert(i);

		for (int p : v[it->second.second]) {
			ans[p] = max(ans[p], (int)v[it->second.second].size());
		}

		// cout << st << " is now " << mp[st].first << " " << mp[st].second << endl;

	} else {
		auto it = mp.find(st);
		it->second.first--;
		v[it->second.second].erase(i);

		// cout << st << " is now " << mp[st].first << " " << mp[st].second << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> n >> sizes >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		upd(s[i], i, 1);
	}

	int a, b, c, d;
	while (m--) {
		// for (auto p : mp) {
		// 	cout << p.first << " - " << p.second.first << " " << p.second.second << endl;
		// }
		// cout << "-----" << endl;

		cin >> a >> b >> c >> d;
		b--; d--;

		if (s[a][b] == s[c][d]) continue;
		
		upd(s[a], a, 0);
		if (a != c)
			upd(s[c], c, 0);
		
		swap(s[a][b], s[c][d]);

		upd(s[a], a, 1);
		if (a != c)
			upd(s[c], c, 1);
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
}

