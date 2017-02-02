#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int MAXM = 20010;

bool v[MAXN][MAXN];
vector<int> g[MAXN];
int e[MAXM][2];
int ok[MAXN], _ok = 0;
int ans[MAXM];
int start;

void dfs(int cur) {
	if (ok[cur] != _ok)
		ok[cur] = _ok;
	else
		return;
	v[start][cur] = true;
	for (const int& p : g[cur])
		dfs(p);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	int n, m;
	cin >> n >> m;
	for (int i = 1,a,b; i <= m; i++) {
		cin >> a >> b;
		e[i][0] = a;
		e[i][1] = b;
		g[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		start = i;
		_ok++;
		dfs(start);
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int k = 1; k <= n; k++) {
	// 		printf("%d, %d: %d\n", i, k, v[i][k]);
	// 	}
	// }

	int greatest = 0;
	for (int i = 1,cur; i <= n; i++) {
		cur = 0;
		for (int k = 1; k <= n; k++) 
			if (v[i][k] && v[k][i]) cur++;
		greatest = max(greatest, cur);
	}

	int best = greatest;
	for (int i = 1,a,b,cur; i <= m; i++) {
		cur = 2;
		a = e[i][0];
		b = e[i][1];
		for (int k = 1; k <= n; k++) {
			if (k == a || k == b) continue;
			if ((v[a][k] || v[b][k]) && (v[k][a] || v[k][b])) cur++;
		}
		ans[i] = max(greatest, cur);
		best = max(best, ans[i]);
	}


	int cnt = 0;
	for (int i = 1; i <= m; i++)
		if (ans[i] == best)
			cnt++;

	cout << best << endl << cnt << endl;
	for (int i = 1; i <= m; i++)
		if (ans[i] == best)
			cout << i << " ";
	cout << endl;
}