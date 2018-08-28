//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;

int main() {
    cin >> s;
    int n = s.size() - 1;
    ll ans = 0;
    for (int i = 0; i < (1<<n); i++) {
        string cur = string(1, s[0]);
        ll num = 0;
        //cout << "Teste: " << cur << endl;
        for(int k = 1; k < s.size(); k++) {
            if ((1<<(k - 1)) & i) {
                num += stoll(cur);
                cur = "";
            }
            cur += s[k];            
        }        
        num += stoll(cur);
        //cout << "Num: " << num << " Cur: " << cur << '\n';
        ans += num;
    }

    cout << ans << '\n';
}
