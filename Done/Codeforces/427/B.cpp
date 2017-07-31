#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int k;
string s;
int sum = 0;
vector<int> pos[15];

int main() {
    cin >> k >> s;
    int tam = s.size();
    for (int i = 0; i < tam; i++) {
	int num = s[i] - '0';
	pos[num].pb(i);
	sum += num;
    }

    if (sum >= k) cout << 0 << '\n';
    else {
	int cur = 0;
	int resp = 0;
	while (sum < k) {
	    while (pos[cur].empty()) cur++;
	    sum -= cur; sum += 9;
	    pos[cur].pop_back();
	    resp++;
	}
	cout << resp << '\n';
    }
    
}

