#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, start;
vector<int> g[MAXN];
int ans[MAXN];

void dfs(int cur) {
	for (int nx : g[cur]) {
		if (ans[nx] != 0) continue;
		if (ans[cur] == 1) {
			ans[nx] = 2;
		} else {
			ans[nx] = 1;
		}
		dfs(nx);
	}
}

int main()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

    ifstream cin ("input.txt");
    ofstream cout ("output.txt");


	cin >> n >> start;
	for (int i = 1,a; i <= n; i++) {
		cin >> a;
		g[i].resize(a);
		while (a--) {
			cin >> g[i][a];
		}
	}

	ans[start] = 1;
	dfs(start);

	for (int i = 1; i <= n; i++) {
		if (g[i].size() > 1) continue;
		if (ans[i] == 0) {
			cout << "-" << endl;
		} else if (ans[i] == 1) {
			cout << "CW" << endl;
		} else {
			cout << "CCW" << endl;
		}
	}
}