#include<bits/stdc++.h>
using namespace std;


int main() {
    int y, b, r;
    int ans;
    scanf("%d %d %d", &y, &b, &r);
    
    ans = 3 * y + 3;
    ans = min(ans, 3 * b);
    ans = min(ans, 3 * r - 3);

    printf("%d\n", ans);

    return 0;
}
