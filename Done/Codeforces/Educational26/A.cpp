#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1231;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
int resp = 0;

int count(string &s) {
    int ret = 0;
    for (char c : s) {
	if (c >= 'A' && c <= 'Z') ret++;
    }
    return ret;
}

int main() {
    string s;
    cin >> n;
    while (cin >> s) {
	resp = max(resp, count(s));
    }
    cout << resp << '\n';
}


