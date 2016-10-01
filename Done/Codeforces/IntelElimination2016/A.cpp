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

const int MAXN=123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int f;

string h;


int main() {
  cin >> f;
  cin >> h;
  if(f == 12) {
    if(((h[3] - '0')*10 + (h[4] - '0')) > 59) {
      h[3] = '0';
    }
    int aux = ((h[0] - '0')*10 + (h[1] - '0'));
    if(aux == 0 || aux > 12) {
      if(aux == 0) h[0] = '1';
      else {
	if(h[0] == '1') h[1] = '1';
	else if(h[1] == '2' || h[1] == '0' || h[1] == '1') h[0] = '1';
	else {
	  h[0] = '0';
	}
      }
    }
  }

  else {
    if(((h[3] - '0')*10 + (h[4] - '0')) > 59) {
      h[3] = '0';
    }
    int aux = ((h[0] - '0')*10 + (h[1] - '0'));
    if(aux > 23) {
      h[0] = '1';
    }
  }

  cout << h << '\n';
}


