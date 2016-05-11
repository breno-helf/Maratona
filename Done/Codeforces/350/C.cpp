//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define deb(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=212345;
const int INF=0x3f3f3f3f;

int a[MAXN],b[MAXN],c[MAXN],n,m;

map<int,int> lan;

map<int, vector<int> > fil, sub;

pii s[MAXN];

int resp, sa, al;


int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
    lan[a[i]]++;
  }
  int t=0;
  for(auto& e: lan){
    s[t].first = e.second;
    s[t].second = e.first;
    t++;
  }
  sort(&s[0],&s[t]);
  scanf("%d", &m);
  for(int i=0;i<m;i++){
    scanf("%d", &b[i]);
    fil[b[i]].pb(i);
  }
  
  resp = 0;
  sa = 0;
  al = 0;

  for(int i=0;i<m;i++){
    scanf("%d", &c[i]);
    sub[c[i]].pb(i);
  }
  for(int i=t-1;i>=0;i--){
    if(s[i].first < sa) break;
    
    if(fil[s[i].second].size()>0 || sub[s[i].second].size()>0){
      int tam = fil[s[i].second].size();
      for(int k=0;k<tam;k++){
	if((lan[c[fil[s[i].second][k]]]>al || s[i].first > sa)){
	  sa = s[i].first;
	  resp = fil[s[i].second][k];
	  al = lan[c[fil[s[i].second][k]]];
	}
      }
      tam = sub[s[i].second].size();
      
      for(int k=0;k<tam;k++){
	if((lan[b[sub[s[i].second][k]]]>=sa && s[i].first > al)){
	  sa = lan[b[sub[s[i].second][k]]];
	  resp = sub[s[i].second][k];
	  al = s[i].first;
	}
      }
    }
  }
  printf("%d\n", resp + 1);
  return 0;
}
	    



