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

const int MAXN=51234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

char s[MAXN];
int tam;
int num;
set<char> l;
set<char> p;


int main() {
  scanf(" %s", s);
  num = 0;
  tam = strlen(s);
  if(tam < 26) {
    puts("-1");
    return 0;
  }

  for(int i = 0; i <= (tam - 26); i++) {
    l.clear();
    p.clear();
    num = 0;
    for(int k = i; k < i + 26; k++) {
      if(s[k] == '?') num++;
      else {
	l.insert(s[k]);
      }
    }

    for(char h = 'A'; h <= 'Z'; h++) {
      if(l.find(h) == l.end()) {
	p.insert(h);
      }
    }
    if((int)p.size() > num) {
      continue;
    }
    else {
      for(int k = i; k < tam; k++) {
	if(s[k] == '?') {
	  if(p.size() > 0) {
	    char b;
	    b = *(p.begin());
	    s[k] = b;
	    p.erase(b);
	  }
	  else {
	    s[k] = 'A';
	  }
	}
      }
      for(int k = 0; k < i; k++) if(s[k] == '?') s[k] = 'A';
      printf("%s\n", s);
      return 0;
    }
  }
  puts("-1");
  return 0;
  
}
    
