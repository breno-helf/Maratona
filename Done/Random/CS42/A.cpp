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



const int MAX = 1231;

const int INF = 0x3f3f3f3f;

const ll  MOD = 1000000007;



string s;

int f[MAX];

int main() {

    cin >> s;

    for(int i = 0; i < (int)s.size(); i++) {

        f[s[i] - '0']++;

    }

    int c = f[0];

    int ok = 1;

    for(int i = 1; i <= 9; i++) {

        if (f[i] != c) ok = 0;

    }

    cout << ok << '\n';

}


