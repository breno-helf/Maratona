#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int dp[MAX][MAX];
string s;
int pal[MAX][MAX];
int resp[MAX];

int palindrome(int l, int r) {
    int &res = pal[l][r];
    if (l == r) return res = 1;

    if (r - l == 1) return res = s[l] == s[r] ? 1 : 0;

    if (res != -1) return res;

    if (s[l] == s[r]) return res = palindrome(l + 1, r - 1);

    return res = 0;
}

int solve(int l, int r) {
    int &res = dp[l][r];

    if (l == r) return res = 1;

    if (res != -1) return res;
    
    if (palindrome(l, r)) {
	int mid = (l + r) / 2;
	return res = 1 + solve(mid + 1, r);
    }

    return res = 0;
}


int main() {
    cin >> s;
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    memset(pal, -1, sizeof(pal));
    for (int i = 0; i < n; i++) {
	for (int j = i; j < n; j++) {
	    resp[solve(i, j)]++;
	}
    }
    for (int i = n; i >= 0; i--) resp[i] += resp[i + 1];
    for (int i = 1; i <= n; i++) cout << resp[i] << ' ';
    cout << '\n';
}





