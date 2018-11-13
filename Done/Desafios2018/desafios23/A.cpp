#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e2 + 10;

int T;
int q, m;
set<char> ans[MAX];
set<char> err[MAX];
int inv[MAX];

int main() {
    scanf("%d", &T);

    while (T--) {
        for (int i = 0; i < MAX; i++) {
            ans[i].clear();
            err[i].clear();
        }
        memset(inv, 0, sizeof(inv));
        
        scanf("%d%d", &q, &m);
        for (int k = 0; k < m; k++) {
            for (int i = 0; i < q; i++) {
                char A, C;
                scanf(" %c %c", &A, &C);
                
                if (C == 'T') {
                    ans[i].insert(A);
                } else {
                    err[i].insert(A);
                }
            }
        }

        for (int i = 0; i < q; i++) {
            char c = '?';
            if (ans[i].size() > 1) inv[i] = 1;
            if (err[i].size() == 4) inv[i] = 1;

            if (!ans[i].empty()) {
                c = *ans[i].begin();
                if (err[i].find(c) != err[i].end()) inv[i] = 1;
            }

            if (err[i].size() == 3) {
                for (char k = 'A'; k <= 'D'; k++) {
                    if (err[i].find(k) == err[i].end()) c = k;
                }
            }
            
            if (inv[i] == 1) c = '?';
            
            printf("%c", c);
            if (i == (q - 1)) printf("\n");
            else printf(" ");
        }
    }

    return 0;
}
