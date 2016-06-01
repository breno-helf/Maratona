//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int n, k, sa[MAXN], sb[MAXN];
char s[MAXN];

vector<int> ab;

int resp = 0;


int main(){
  scanf("%d%d", &n, &k);
  scanf("%s", s);
 
  for(int i=0;i<n;i++){
    sa[i] = (s[i]=='a');
    sb[i] = (s[i]=='b');
  }

  int j = 0, mx = 0, bestl = 0, bestr = -1, din = k;
  for(int i=0;i<n;i++){
    while(j<n && (sa[j] || din>0)){
      if(!sa[j]) din--;
      j++;
    }
    if(j-i > mx) bestl = i, bestr = j -1;
    mx = max(mx, j-i);
    if(i==j){
      j++;
      continue;
    }
    if(!sa[i]) din++;
  }
  resp = max(resp, mx);

  j = 0, mx = 0, bestl = 0, bestr = -1, din = k;
  for(int i=0;i<n;i++){
    while(j<n && (sb[j] || din>0)){
      if(!sb[j]) din--;
      j++;
    }
    if(j-i > mx) bestl = i, bestr = j -1;
    mx = max(mx, j-i);
    if(i==j){
      j++;
      continue;
    }
    if(!sb[i]) din++;
  }
  resp = max(resp, mx);
  printf("%d\n", resp);
  return 0;
}
