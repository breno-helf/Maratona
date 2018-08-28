//If you are trying to hack me I wish you can get it, Good Luck :D.

// 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 

// 1, 2,  3,  4,  5,  6,   7,   8,   9,  10,  11,  12,  13,  14,   15,

// ^      ^                ^                                        ^

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

int dig(int x) {
    int ret = 0;
    while (x > 0) {
        ret++;
        x /= 10;
    }

    return ret;
}

int translate(int x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }

    reverse(digits.begin(), digits.end());

    int ret = 0;

    for (int d : digits) {
        ret <<= 1;
        if (d == 7) ret |= 1;
    }

    return ret;
}

int main() {
    cin >> n;
    int d = dig(n);
    int st = (1<<d) - 1;

    int tg = translate(n);

    //cout << st << ' ' << tg << '\n';
    
    cout << st + tg << '\n';
}

