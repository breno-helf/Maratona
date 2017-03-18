//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k;
vector<string> names;
string resp[MAX];
bool good[MAX], used[MAX];
int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    for (char c = 'A'; c <= 'M'; c++) {
	for (char q = 'a'; q <= 'z'; q++) {
	    string s = "";
	    s += c; s += q;
	    names.pb(s);
	}
    }

    cin >> n >> k;
    for (int i = 0; i < (n - k + 1); i++) {
	string s;
	cin >> s;
	if (s == "YES") good[i] = true;
	else good[i] = false;
    }
    int cnt = 0;
    for (int i = 0; i < k; i++) {
	resp[i] = names[cnt++];
    }
    if (!good[0]) resp[k - 1] = resp[0];
    for (int j = 1; j < (n - k + 1); j++) {
	if (!good[j]) {
	    resp[k - 1 + j] = resp[j];
	} else {
	    resp[k - 1 + j] = names[cnt++];
	}	
    }

    for (int i = 0; i < n; i++)
	cout << resp[i] << ' ';
    cout << '\n';
}
