#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int lim[20];
ll dp[20]/**/[3][3][3][3][3]/**/[3][3][3][3][3]/**/[2][2];

vector<int> cnt(10, 0);
ll f(int i, bool over, bool lastzero) {
	if (i == n)
		return (!over && !lastzero);
	
	ll& ret = dp[i][cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]][cnt[7]][cnt[8]][cnt[9]][over][lastzero];
	if (ret != -1) return ret;

	if (!lastzero)
		ret = 1;
	else
		ret = 0;

	for (int k = 0; k < 10; k++) {
		if (cnt[k] == 2) continue;

		cnt[k]++;
		ret += f(i+1, k > lim[i] || (k == lim[i] && over), k == 0);
		cnt[k]--;
	}

	return ret;
}

int main()
{
	ifstream cin("exchange.in");
	ofstream cout("exchange.out");

	ll ans = 0;
	ll aux;
	string s;

	cin >> aux;
	aux--;
	s = to_string(aux);
	reverse(s.begin(), s.end());
	
	n = 0;
	while (aux > 0) {
		n++;
		aux /= 10;
	}

	for (int i = 0; i < 20; i++) {
		if (i < s.size()) {
			lim[i] = s[i] - '0';
		} else {
			lim[i] = 0;
		}
		// cout << lim[i];
	}
	// cout << endl;
	// printf("n == %d\n", n);

	for (int i = 0; i < 10; i++) cnt[i] = 0;
	memset(dp, -1, sizeof(dp));
	ans -= f(0, 0, 0);
	// cout << ans << endl;


	cin >> aux;
	s = to_string(aux);
	reverse(s.begin(), s.end());

	n = 0;
	while (aux > 0) {
		n++;
		aux /= 10;
	}

	for (int i = 0; i < 20; i++) {
		if (i < s.size()) {
			lim[i] = s[i] - '0';
		} else {
			lim[i] = 0;
		}
		// cout << lim[i];
	}
	// cout << endl;
	// printf("n == %d\n", n);

	for (int i = 0; i < 10; i++) cnt[i] = 0;
	memset(dp, -1, sizeof(dp));
	ans += f(0, 0, 0);

	cout << ans << endl;
}