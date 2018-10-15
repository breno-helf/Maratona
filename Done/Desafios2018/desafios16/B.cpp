#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e4 + 10;

int n;
long long int A[MAX];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", A + i);

    sort(A, A + n);

    for (int i = 0; i < n - 2; i++) {
        if (A[i + 2] < A[i] + A[i + 1]) {
            puts("possible");
            return 0;
        }
    }

    puts("impossible");
    return 0;
}
