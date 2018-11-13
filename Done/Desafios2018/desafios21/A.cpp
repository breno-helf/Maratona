#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e2 + 10;

int n, a[MAX];

int hamming_dist(int a, int b) {
    int dist = 0;
    for (int i = 0; i < 30; i++) {
        int bit = (1<<i);
        if ((a&bit) != (b&bit)) dist++;
    }

    return dist;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, hamming_dist(a[i], a[j]));
            }        
        }

        printf("%d\n", ans);
    }

    return 0;
}
