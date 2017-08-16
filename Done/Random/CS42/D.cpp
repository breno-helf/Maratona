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



int n;

pii a[MAX];

int c[MAX];



void intercala(int s, int t, int p, int q) {

    vector<pii> aux;    

    int i = s;

    int j = p;

    int id = 0;

    //debug("Intercalando [%d,%d] com [%d,%d]\n", s, t, p, q);

    while (i <= t && j <= q) {

        if (a[i].first <= a[j].first) {

	        aux.pb(a[i++]);

        } else {

            c[a[j].second] += (t + 1 - s) - (i - s);

            aux.pb(a[j++]);

        } //else aux.pb(a[i++]);

    }

    

    while (i <= t) {

	    aux.pb(a[i++]);

    }

    while (j <= q) {

        c[a[j].second] += (t + 1 - s) - (i - s);

        aux.pb(a[j++]);

    }

    for (int k = s; k <= q; k++) a[k] = aux[k - s];

}

void merge_sort(int i, int j) {

    if (i >= j) return;

    int m = (i + j) / 2;

    merge_sort(i, m);

    merge_sort(m + 1, j);

    intercala(i, m, m + 1, j);

}





int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf("%d", &a[i].first);

        a[i].second = i;

    }

    merge_sort(1, n);

    int cnt = 0;

    // for (int i = 1; i <= n; i++)

    // 	debug("%d ", a[i].first);

    // debug("\n");

    // for (int i = 1; i <= n; i++)

    // 	debug("%d ", a[i].second);

    // debug("\n");

    for (int i = 1; i <= n; i++) cnt = max(cnt, c[i]);

    printf("%d\n", cnt + 1);

}

