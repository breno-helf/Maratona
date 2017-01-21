//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


int tt, n, w[MAXN];

int main() {
  cin >> tt;
  for(int t = 1; t <= tt; t++) {
    set<pii> p;
    cin >> n;
    int resp = 0;
    for(int i = 0; i < n; i++) {
      cin >> w[i];
      p.insert(mp(w[i], i));
    }
    //    sort(w, w + n);
    while(!p.empty()) {
      int k;
      int top = (prev(p.end()))->first;
      //debug("top eh %d size eh ", top);
      //cout << p.size() << endl;
      p.erase(prev(p.end()));
      for(k = 0; 50/top > k; k++);
      if(50%top == 0) k--;

      if(k > p.size())
        while(!p.empty())
          p.erase(p.begin());
      else {
        
        for(int e = 0; e < k; e++)
          p.erase(p.begin());
        resp++;
      }
    }
    cout << "Case #" << t << ": ";
    cout << resp << '\n';
  }
}
