#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

char s[MAX], t[MAX];
int n, d;
int C[200][MAX];

int main() {    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &n, &d);
        d = min(d, n);
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < d; i++)
                C[c - 'a'][i] = 0;
        }
        scanf(" %s %s", s, t);
        for (int i = 0; i < n; i++) {
            C[s[i] - 'a'][i%d]++;
            C[t[i] - 'a'][i%d]--;
        }

        bool ok = true;
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < d; i++)
                if (C[c - 'a'][i] != 0) ok = false;
        }

        if (ok) puts("Yes");
        else puts("No");
        
    }
    return 0;
}
