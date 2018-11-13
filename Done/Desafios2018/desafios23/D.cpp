#include<bits/stdc++.h>
using namespace std;

const int MAX = 50;

int T;
char M[MAX][MAX];
string s;

bool vowel(char c) {
    return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

int play(string& r, int p) {
    if (r.size() == 1) {
        if (vowel(r[0])) return 0;
        else return 1;
    }

    string L, R;
    L = R = "";
    
    for (int i = 0; i < r.size(); i += 2) {
        if (i + 1 < r.size()) {
            L += M[r[i] - 'a'][r[i + 1] - 'a'];
        } else L += r[i];
    }

    for (int i = r.size() - 1; i >= 0; i -= 2) {
        if (i - 1 >= 0) {
            R += M[r[i] - 'a'][r[i - 1] - 'a'];
        } else R += r[i];
    }

    reverse(R.begin(), R.end());

    if (play(L, p ^ 1) == p || play(R, p ^ 1) == p) return p;

    return p ^ 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;

    while (T--) {

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                cin >> M[i][j];
            }
        }

        cin >> s;

        int winner = play(s, 0);

        if (winner == 0) cout << "Salah\n";
        else cout << "Marzo\n";
    }

    return 0;
}
