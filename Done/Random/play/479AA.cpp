#include<bits/stdc++.h>
using namespace std;

int subtract(int x) {
    int lastDig = x % 10;

    if (lastDig == 0) return x / 10;
    return x - 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int cur = n;
    for (int i = 0; i < k; i++)
        cur = subtract(cur);

    printf("%d\n", cur);
}
