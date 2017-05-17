//If you are trying to hack me I wish you can get it, Good Luck :D. I am such a noob
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


int p, x, y;

map<int, int> mrk;

bool test (int s) {
    int i = (s / 50) % 475;
    for (int k = 0; k < 25; k++) {
	i = (i * 96 + 42) % 475;
	if ((26 + i) == p) return true;
    }
    return false;
}

int main () {
    cin >> p >> x >> y;
    vector<int> num;
    int k = x;
    while (k >= y) {
	num.pb(k);
	k -= 50;
    }
    int resp = 0;
    while (true) {
	bool got = false;
	int tam = num.size();
	for (int s : num) {
	    if (test(s)) {
		got = true;
		break;
	    }
	}
	if (got) break;
	
	for (int i = 0; i < tam; i++) {
	    num[i] += 100;
	}
	resp++;
	if (resp == 1) {
	    for (int i = 0; i < tam; i++) {
		num.pb(num[i] - 50);
	    }	    
	}

    }

    cout << resp << '\n';
}
