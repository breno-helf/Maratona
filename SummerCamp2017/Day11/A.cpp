#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 110;

int n, m;
int b[MAXN][MAXN];
bool ok[MAXN][MAXN];
int x = 0, y = 0;
int dx = 0, dy = 1;

inline void rotateRight() {
	if (dy == 1) {
		dx = 1;
		dy = 0;
	} else if (dx == 1) {
		dx = 0;
		dy = -1;
	} else if (dy == -1) {
		dx = -1;
		dy = 0;
		return;
	} else if (dx == -1) {
		dx = 0;
		dy = 1;
	}
}

inline void rotateLeft() {
	rotateRight();
	dx *= -1;
	dy *= -1;
}

inline int get(int i, int j) {
	if (ok[i][j]) {
		return b[i][j]/2;
	} else {
		ok[i][j] = true;
		return b[i][j];
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			scanf("%1d", &b[i][k]);
		}
	}

	int ans = 0;
	char c;
	while (scanf(" %c", &c) != EOF) {
		if (c == 'L') rotateLeft();
		else if (c == 'R') rotateRight();
		else {
			if (dx == 1) {
				ans += get(x+1, y);
				ans += get(x+1, y+1);
			} else if (dx == -1) {
				ans += get(x, y);
				ans += get(x, y+1);
			} else if (dy == 1) {
				ans += get(x, y+1);
				ans += get(x+1, y+1);
			} else {
				ans += get(x, y);
				ans += get(x+1, y);
			}

			x += dx;
			y += dy;
		}
	}

	printf("%d\n", ans);
}
