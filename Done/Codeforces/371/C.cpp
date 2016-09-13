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

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll t;
string num;
char op;
string b;
map<string, ll> par;

void coloca(string x) {
  int tam = x.size();
  string add = "";
  for(int i = tam - 1; i >= 0; i--) {
    if((x[i] - '0')%2) {
      add += '1';
      par[add]++;
    }
    else {
      add += '0';
      par[add]++;
    }
  }
}

void remove(string x) {
  int tam = x.size();
  string add = "";
  for(int i = tam - 1; i >= 0; i--) {
    if((x[i] - '0')%2) {
      add += '1';
      par[add]--;
    }
    else {
      add += '0';
      par[add]--;
    }
  }
}

ll query(string x) {
  string q = "";
  int s = 0;
  if(x.size() == 1) return par[x];
  for(int i = 0; i < x.size(); i++) {
    if(x[i] != '0') s++;
    if(s) {
      q+= x[i];
    }
  }
  return par[q];
}

int main() {
  cin >> t;
  while(t--) {
    cin >> op;
    if(op == '-') {
      cin >> num;
      remove(num);
    }
    if(op == '+') {
      cin >> num;
      coloca(num);
    }
    else if(op == '?'){
      cin >> b;
      printf("%lld\n", query(b));
    }
  }
}
