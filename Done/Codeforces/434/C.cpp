//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 3123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;

bool vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i'
	    || c == 'o' || c == 'u');
}

int main() {
    cin >> s;
    string r = "";
    set<char> T;
    int n = s.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
	if (vowel(s[i])) {
	    T.clear();
	    cnt = 0;
	} else {
	    cnt++;
	    T.insert(s[i]);
	}

	if (T.size() > 1 && cnt >= 3) {
	    T.clear();
	    T.insert(s[i]);
	    cnt = 1;
	    r += " ";
	}
	
	r += s[i];
    }

    cout << r << '\n';
}

