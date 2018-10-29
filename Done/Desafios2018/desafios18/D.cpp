#include<bits/stdc++.h>
using namespace std;

map<char, int> H;

bool test() {
    return (H['R'] == 1 && H['B'] == 1 && H['L'] == 1);
}


int main() {
    string s;
    string ans = "";
    cin >> s;

    set<char> S;

    map<char, char> M;

    M['R'] = 'S';
    M['B'] = 'K';
    M['L'] = 'H';
    
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += M[s[i]];

        H[s[i]]++;
        if (k >= 3) H[s[i - 3]]--;
        
        if (test()) {
            for (int j = 0; j < 3; j++) ans.pop_back();

            H['R'] = H['B'] = H['L'] = 0;
            k = -1;
            ans += 'C';
        }
        k++;
        //cout << ans << ' ' << H['R'] << ' ' << H['B'] << ' ' << H['L'] << endl;
    }

    cout << ans << '\n';
}
