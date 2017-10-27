//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int brelf(int n, ll k, vector<int> a) {
    if (k >= n) {
	return n;
    } else {
	int cnt = 3 * n;
	queue<int> Q;
	int p1 = 0;
	int p2 = 1;
	for (int i = 2; i < n; i++) Q.push(i);
	int winner = -1;
	int wins = 0;

	int best = 0;
	int guy = -1;
	while (cnt--) {
	    if (a[p1] > a[p2]) {
		if (winner == p1) wins++;
		else {
		    winner = p1;
		    wins = 1;
		}
	    } else {
		if (winner == p2) wins++;
		else {
		    winner = p2;
		    wins = 1;
		}
	    }

	    if (wins > best) {
		best = wins;
		guy = winner;
	    }

	    if (best == k) break;

	    if (winner == p1) {
		Q.push(p2);
		p2 = Q.front();
		Q.pop();
	    } else {
		Q.push(p1);
		p1 = Q.front();
		Q.pop();
	    }
	}

	if (best == k) return a[guy];
	else return n;
    }
}

int keepo(int n, ll k, vector<int> a) {
    int cnt[MAX];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
	int j = i + 1;
	while (a[i] > a[j]) {
	    cnt[i]++;
	    j++;
	    j %= n;
	    if (j == i) break;
	}
    }

    for (int i = 0; i < n;  i++) {
	if (cnt[i] >= k) {
	    return a[i];
	}
    }

    int mx = 0, res = 0;

    for (int i = 0; i < n; i++) {
	if (cnt[i] > mx) {
	    mx = cnt[i];
	    res = a[i];
	}
    }
    return res;
}

int paregrine_falcon(int n, ll k, vector<int> a) {
    ll i, x, maxi = -1, index, flag = 0;

    vector<pair<ll, ll> > vec;
    pair<ll, ll> p;

    for (i = 0; i < n; i++) {
	x = a[i];
	vec.pb(mp(x, 0));
	if (x > maxi) {
	    index = i;
	}

	maxi = max(maxi, x);
    }

    if (index == 0 || k >= index) {
	flag = 1;
	return maxi;
    }

    while (flag == 0) {
	if (vec[0] > vec[1]) {
	    p = vec[1];
	    vec.erase(vec.begin() + 1);

	    vec.pb(mp(p.first, p.second));
	    vec[0].second++;

	    if (vec[0].second == k)
		return vec[0].first;
	} else {
	    p = vec[0];
	    vec.erase(vec.begin());
	    vec.pb(mp(p.first, p.second));
	    vec[1].second++;
	    if (vec[1].second == k)
		return vec[1].first;
	}
    }
    return -1;
}

int yogi10(int n, ll k, vector<int> a) {
    int wp = 0;
    ll wt = 0;
    int p[510];
    int i;
    for (i = 0; i < n; i++) {
	p[i] = a[i];
	wp = p[0];
    }

    for (i = 1; i < n; i++) {
	if (p[i] > wp) {
	    wp = p[i];
	    wt = 1;
	} else wt++;

	if (wt == k) return wp;
    }

    if (i == n) return wp;

    return -1;
}

int umbrella25(int n, ll k, vector<int> a) {
    ll l = 0;
    int curr = a[0];
    int streak = 0, s = a[n - 1];
    l++;
    while (curr != n && streak < k) {
	if (curr > a[l]) {
	    streak++;
	    s = a[l];
	    l++;
	    a.pb(s);
	} else {
	    s = curr;
	    curr = a[l];
	    l++;
	    a.pb(s);
	    streak = 0;
	}
    }
    return curr;
}

int kmbredis(int n, ll k, vector<int> a) {
    int mxy, wins = 0;

    mxy = a[0];
    
    for (int i = 1; i < n; i++) {
	int p;
	p = a[i];

	if (mxy > p) {
	    ++wins;
	    if (wins >= k) break;

	} else {
	    mxy = p;
	    wins = 0;
	    
	}
    }

    return mxy;
}

int nsei(int n, ll k, vector<int> a) {

    ll ini = k;
    int h = a[0];
    
    for (int i = 1; i < n; i++) {

	int g = a[i];
	
	if (k == 0) {
	    return h;
	}

	if (h > g) k--;

	else if (h < g) {
	    k = ini;
	    h = g;
	}
	
    }

    return h;
}

int main() {
    srand(time(NULL));

    int (*hacked)(int, ll, vector<int>);
    hacked = nsei;
    
    vector<pll> NK;
    vector<vector<int> > arr;
    vector<int> O, ans;
    
    NK.pb(pll(2, 2));
    O.pb(1); O.pb(2);
    arr.pb(O);
    O.clear();
    ans.pb(2);
    
    
    NK.pb(pll(4, 2));
    O.pb(3); O.pb(1); O.pb(2); O.pb(4);
    arr.pb(O);
    O.clear();
    ans.pb(3);
    
    NK.pb(pll(6, 2));
    O.pb(6); O.pb(5); O.pb(3); O.pb(1); O.pb(2); O.pb(4);
    arr.pb(O);
    O.clear();
    ans.pb(6);
    
    NK.pb(pll(2, 10000000000LL));
    O.pb(2); O.pb(1);
    arr.pb(O);
    O.clear();
    ans.pb(2);
    int n;
    ll k;
    vector<int> a(MAX);
    
    for (int i = 0; i < (int)NK.size(); i++) {
	n = NK[i].first; k = NK[i].second;
	for (int j = 0; j < (int)arr[i].size(); j++) {
	    a[j] = arr[i][j];
	}

	assert(brelf(n, k, a) == ans[i]);
	assert(hacked(n, k, a) == ans[i]);
    }

    vector<int> T;
    n = 10;
    for (int i = 1; i <= n; i++) {
	T.pb(i);
    }

    for (int i = 0; i < n * 10; i++) {
	random_shuffle(T.begin(), T.end());
	k = rand() % n + 2;
	int B = brelf(n, k, T);
	int H = hacked(n, k, T);
	if (B != H) {
	    
	    printf("%d %lld\n", n, k);
	    for (int j = 0; j < n; j++)
		printf ("%d ", T[j]);
	    printf("\n\n\n");
	    printf("(%d) %d -- %d\n", i, B, H);
	    assert(B == H);
	}
    }

    return 0;
}


