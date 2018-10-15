#include<bits/stdc++.h>
using namespace std;

const int MAX = 3e2 + 10;
const int START = 150;

string s;
int T;
char M[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
map<char, int> C;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    C['F'] = 0; C['R'] = 1; C['L'] = 3; C['B'] = 2;
    
    cin >> T;
    
    cout << T << '\n';
    while (T--) {
        cin >> s;
        memset(M, '#', sizeof(M));
        
        int x = START, y = 0;
        
        int dir = 0;

        int X = START, Y = 0;
        int Xmin = START;
        M[x][y] = '.';
        for (int i = 0; i < (int)s.size(); i++) {
            dir = (dir + C[s[i]]) % 4;
            x = x + dx[dir];
            y = y + dy[dir];

            //dir = 0;
            X = max(x, X);
            Y = max(y, Y);
            Xmin = min(Xmin, x);
            
            M[x][y] = '.';
        }

        Xmin -= 1;
        X += 2;
        Y += 2;
        
        cout << X - Xmin << ' ' << Y << '\n';
        for (int i = Xmin; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                cout << M[i][j];
            }
            cout << '\n';
        }        
    }

    return 0;
}
