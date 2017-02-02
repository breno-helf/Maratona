#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MAXN = 1e5+10;
const int MAX = 1000001;

int n;
int a[MAXN], b[MAXN];
vector<int> v;
int d1[MAXN], _d1 = 0, d2[MAXN], _d2 = 0;
int g1[MAXN], g2[MAXN];
vector<int> ans1, ans2;
int e1[MAXN], e2[MAXN];

bool comp(int p, int q) {
	if (a[p] != a[q]) return a[p] < a[q];
	else return b[p] > b[q];
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		v.push_back(i);
		d1[i] = 10*MAX;
		d2[i] = -10*MAX;
	}

	sort(v.begin(), v.end(), comp);

	d1[0] = -10*MAX;
	for (int i = 0; i < n; i++) {
		int l = 0, r = _d1, m;
		while (l < r) {
			m = (l + r + 1) >> 1;
			// printf("i %d l %d r %d m %d testing %d > %d\n", i, l, r, m, b[v[i]], d1[m]);
			// printf("i %d l %d r %d m %d\n", i, l, r, m);
			if (b[v[i]] > d1[m])
				l = m;
			else
				r = m-1;
		}
		// printf("m %d\n", m);

		g1[v[i]] = l;
		d1[l+1] = min(d1[l+1], b[v[i]]);
		_d1 = max(_d1, l+1);
	}

	d2[0] = 10*MAX;
	int ans = 0;
	for (int i = n-1; i >= 0; i--) {
		int l = 0, r = _d2, m;
		while (l < r) {
			m = (l + r + 1) >> 1;
			if (b[v[i]] < d2[m])
				l = m;
			else
				r = m-1;
		}

		g2[v[i]] = l;
		ans = max(ans, g1[v[i]] + g2[v[i]]);
		d2[l+1] = max(d2[l+1], b[v[i]]);
		_d2 = max(_d2, l+1);
	}

	// for (int i = 0; i < n; i++) {
	// 	printf("Ii %d g1 %d g2 %d\n", v[i], g1[v[i]], g2[v[i]]);
	// }

	for (int i = 0; i < n; i++) {
		if (g1[i] + g2[i] == ans) {
			e1[g1[i]]++;
			e2[g2[i]]++;
		}
	}

	// for (int i = 0; i < n; i++)
	// 	printf("i %d e1 %d e2 %d\n", i, e1[i], e2[i]);

	for (int i = 0; i < n; i++) {
		if (g1[i] + g2[i] == ans) {
			ans1.push_back(i+1);
			if (e1[g1[i]] == 1 && e2[g2[i]] == 1)
				ans2.push_back(i+1);
		}
	}

	cout << ans1.size();
	for (int p : ans1) cout << " " << p;
	cout << endl;

	cout << ans2.size();
	for (int p : ans2) cout << " " << p;
	cout << endl;
}