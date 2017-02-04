#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int m;
ld s, p;

int main() 
{
	ifstream cin ("input.txt");
	ofstream cout ("output.txt");

	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie (0);

	cin >> s >> m >> p;
	p /= 100;

	ld val;
	ld l = s * p;
	ld r = 3e6;
	ld x;
	int run = 1e4;
	while (run--) {
		x = (l + r)/2;
		val = s;
		for (int i = 0; i < m; i++) {
			val = val + val*p - x;
		}

		if (val < 0) {
			r = x;
		} else {
			l = x;
		}
	}

	cout << fixed << setprecision(10) << l << endl;
	return 0;
}