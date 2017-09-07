//This code was written by Breno Moura, Codeforces Handle: Brelf

//From University of São Paulo - USP

//If you are trying to hack me I wish you can get it, Good Luck :D

#include <bits/stdc++.h>

using namespace std;



#define debug(args...) fprintf (stderr,args)

#define pb push_back

#define mp make_pair



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



const int MAX = 112345;

const int INF = 0x3f3f3f3f;

const ll  MOD = 1000000007;



double resp[MAX];



void calc(int i, int j, double q) {

    int tam = (j - i + 1);

    //debug("%d %d %.3lf -- %.3lf\n", i, j, q, (double)tam/q);

    if (tam % 2 == 0) {

        calc(i, (i + j) / 2, q);

        calc((i + j) / 2 + 1, j, q);

        for (int k = i; k <= j; k++)

            resp[k] += (double)tam/q;

        return;

    } if (i == j) {

        resp[i] += 1.0/q;

        return;

    }



    calc(i, i + tam/2, q * 2);

    calc(i + tam/2 + 1, j, q * 2);

    calc(i, i + tam/2 - 1, q * 2);

    calc(i + tam/2, j, q * 2);



    for (int k = i; k <= j; k++) {

        resp[k] += (double)tam/q;

    }

}



int main() {

    int n;

    cin >> n;

    calc(1, n, 1);

    for (int i = 1; i <= n; i++)

        cout << fixed << setprecision(7) << resp[i] << ' ';

    cout << '\n';

}

