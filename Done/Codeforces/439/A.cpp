//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX], b[MAX];
int resp;
set<int> S;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	S.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
	cin >> b[i];
	S.insert(b[i]);
    }
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    if (S.find(a[i] ^ b[j]) != S.end()) resp++;
	}
    }

    if (resp % 2) cout << "Koyomi\n";
    else cout << "Karen\n";
}


