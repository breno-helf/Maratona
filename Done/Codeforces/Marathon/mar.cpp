//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
#include<cstdlib>
#include<iostream>
#include<random>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=5123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

const int N=5000;
const int ATT=100;
const int K=2000;

string s, fix;
double pp[N+10][ATT+10];
int cor[N+10];

int main(){
  int mx = -10;
  int now = 0;
  memset(cor,INF,sizeof(cor));
  memset(pp,-1,sizeof(pp));
  mt19937 gen(19222);
  uniform_int_distribution<> go(0,1); 
  for(int i=0;i<N;i++) s += go(gen) + '0';
  for(int i=0;i<26;i++){
    cout << s << '\n';
    fflush(stdout);
    cin >> now;
    now-=1;
    if(now>mx) fix = s, mx = now;
    if(mx==N){
      return 0;
    }
    cor[now] = ((s[now]=='1') ? 0 : 1);
    for(int k=0;k<now;k++){
      if(s[k]=='1') pp[k][i] = (cor[k]!=INF) ? ((double)cor[k]) : (1 - K/(now+1));
      else pp[k][i] = (cor[k]!=INF) ? ((double)cor[k]) : (K/(now+1));
    }
    s.clear();
    for(int k=0;k<N;k++){
      s += ((cor[k]==INF) ? (go(gen) + '0') : ('0' + cor[k]) );
    }
  }
  for(int i=0;i<N;i++){
    for(int k=1;k<26;k++) pp[i][0] += pp[i][k];
    if((pp[i][0]/26)>0 && cor[i]!=INF && i!=mx){
      fix[i] = (pp[i][0]>0.5) ? '1' : '0';
    }
  }
  for(int i=0;i<N;i++) fix[i] = ((cor[i]==INF || i==mx) ? fix[i] : (cor[i] + '0'));
  for(int i=0;i<74;i++){
    if(fix[mx] == '1') fix[mx] = '0';
    else fix[mx] = '1';
    cout << fix << '\n';
    fflush(stdout);
    cin >> mx;
    mx--;
  }
  return 0;
}
