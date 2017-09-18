//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1231122;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

set<string> S;

int main() {
    srand(time(NULL));
    while (S.size() < 70000) {
	string r = "";
	r += '1' + rand() % 9;
	for (int i = 1; i < 9; i++) r += '0' + rand() % 10;
	S.insert(r);
    }

    cout << S.size() << '\n';
    for (string r : S) {
	cout << r << '\n';
    }
}

