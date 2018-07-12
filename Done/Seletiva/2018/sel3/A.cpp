#include <bits/stdc++.h>
using namespace std;

string s, t;

string fix(string r) {
    string ret = "";
    ret += r[0];
    for (int i = 1; i < r.size(); i++) {
        if (r[i] != r[i - 1]) ret += r[i];
    }
    return ret;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> s >> t;
        
        s = fix(s);
        t = fix(t);
        //cout << s << '\n' << t << '\n';
        
        if (s == t) {
            cout << "Yes\n";
        } else cout << "No\n";

    }
    return 0;
}
