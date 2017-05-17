//If you are trying to hack me I wish you can get it, Good Luck :D. I am such a noob
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

pii a[MAX], b[MAX];
int n;
bool rated;

bool cmp (pii x, pii y) {
    return x > y;
}

int main () {
    rated = false;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
	cin >> a[i].first >> a[i].second;
	b[i] = a[i];
	if (a[i].first != a[i].second) rated = true;
    }

    if (rated) {
	cout << "rated\n";
    } else {
	sort(b, b + n, cmp);
	bool unrated = true;
	for (int i = 0; i < n; i++) {
	    if (a[i] != b[i]) {
		//debug ("%d %d != %d %d -- %d\n", a[i].first, a[i].second, b[i].first, b[i].second, i);
		unrated = false;
	    }
	}

	if (!unrated) {
	    cout << "unrated\n";
	} else {
	    cout << "maybe\n";
	}
    }

    return 0;
}


