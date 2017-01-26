#include <bits/stdc++.h>
using namespace std;

int round(int a, int b) {
    return (int)((double) (100 * a)/ (double) b + (double) 0.5);
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v;
    for (int i = 0,a; i < n; i++) {
        scanf("%d", &a);
        v.push_back(a);
    }

    for (int i = 1; i <= 100; i++) {
        bool ok = 1;
        for (int p : v) {
            for (int k = i; k >= 0; k--) {
                if (round(k, i) == p) {
                    break;
                } else {
                    if (k == 0) {
                        ok = 0;
                    }
                }
            }
        }

        if (ok) {
            printf("%d\n", i);
            return 0;
        }
    }
}
