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

int a[MAXN], n;

map<int,int> qtd;

map<int,int> cmp;

set<int> s;

vector<int> num;

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
    qtd[a[i]]++;
    s.insert(a[i]);
  }
  for(auto e : qtd){
    num.pb(e.first);
  }
  int val = 1;
  int j = 0;
  int tam = num.size();
  int resp = num[tam-1] + 1;
  while(j < tam){
    while((num[j] <= val || qtd[num[j]]==0) && j<tam) j++;
    if(s.find(val) == s.end() ){
      qtd[num[j]]--;
      s.insert(val);
      if(qtd[num[j]] == 0){
	s.erase(num[j]);
	if(j==(tam-1)) resp = val+1;
      }
    }
    val++;
  }
  printf("%d\n", resp);
  return 0;
}







