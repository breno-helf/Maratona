//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;
set<string> V;

int main() {
    V.insert("Danil");
    V.insert("Olya");
    V.insert("Slava");
    V.insert("Ann");
    V.insert("Nikita");

    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
	string cur = "";
	for (int j = i; j < n; j++) {
	    cur += s[j];
	    if(V.find(cur) != V.end()) {
		cnt++;
	    }
	}
    }
    if (cnt != 1)
	puts("NO");
    else puts("YES");
}

