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

const int MAXN=11234567;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

struct tree{
  int ja;
  int esq;
  int dir;
  int val;
}trie[MAXN];

int q, tam;

map<int,int> ms;

void coloca(int x) {
  int idx = 1;
  for(int i = 30; i >= 0; i--) {
    if(!trie[idx].ja) {
      trie[idx].ja = 1;
      trie[idx].esq = tam++;
      trie[idx].dir = tam++;
    }
    int e = trie[idx].esq;
    int d = trie[idx].dir;

    if((1<<i)&x) {
      trie[d].val++;
      idx = d;
    }
    else {
      trie[e].val++;
      idx = e;
    }
  }
}

void remove(int x) {
  int idx = 1;
  for(int i = 30; i >= 0; i--) {
    if(!trie[idx].ja) {
      trie[idx].ja = 1;
      trie[idx].esq = tam++;
      trie[idx].dir = tam++;
    }
    int e = trie[idx].esq;
    int d = trie[idx].dir;
    
    if((1<<i)&x) {
      trie[d].val--;
      idx = d;
    }
    else {
      trie[e].val--;
      idx = e;
    }
  }
}

int chora(int x) {
  int idx = 1;
  int ret = 0;
  for(int i = 30; i >= 0; i--) {
    if(!trie[idx].ja) {
     trie[idx].ja = 1;
      trie[idx].esq = tam++;
      trie[idx].dir = tam++;
    }
    int e = trie[idx].esq;
    int d = trie[idx].dir;

    if((1<<i)&x) {
      if(trie[e].val != 0) {
      ret += (1<<i);
      idx = e;
      }
      else {
	idx = d;
      }
    }
    else {
      if(trie[d].val != 0) {
	ret += (1<<i);
	idx = d;
      }
      else {
	idx = e;
      }
    }
  }
  return ret;
}

int main() {
  scanf("%d", &q);
  tam = 2;
  coloca(0);
  for(int i = 0; i < q; i++) {
    char c;
    int x;
    scanf(" %c %d", &c, &x);
    if(c == '+') {
      ms[x]++;
      if(ms[x] == 1) coloca(x);
    }

    else if(c == '-') {
      ms[x]--;
      if(ms[x] == 0) remove(x);
    }

    else printf("%d\n", chora(x));
  }
  return 0;
}










