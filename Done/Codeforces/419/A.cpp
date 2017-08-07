//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 32113;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;

pii calc(string w) {
    string r = "";
    for (int i = 0; i < 2; i++) r += w[i];
    pii ret;
    ret.first = stoi(r);
    r = "";
    for (int i = 3; i < 5; i++) r += w[i];
    ret.second = stoi(r);
    return ret;
}

bool test(pii a) {
    string r = to_string(a.first);
    string w = to_string(a.second);
    while(r.size() < 2) r = "0" + r;
    while(w.size() < 2) w = "0" + w;
    reverse(w.begin(), w.end());
    //cout << r << ' ' << w << '\n';
    return w == r;
}

pii nxt(pii cur) {
    cur.second++;
    if (cur.second == 60) {
	cur.first++;
	cur.second = 0;
    }

    if (cur.first == 24) cur.first = 0;
    return cur;
}

int main() {
    cin >> s;
    pii cur = calc(s);
    int resp = 0;
    for (; !test(cur); cur = nxt(cur)) resp++;
    cout << resp << '\n';
}

