#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const int MAXB=24;

int n,m,dist[MAXN],marc[MAXN];
char v1[112],v2[112];
vector<pii> adj[MAXN];
char ax[13];
set<pii> dij;

void dijkstra(){
  memset(marc,0,sizeof(marc));
  dij.insert(make_pair(0,(1<<n)-1));
  dist[(1<<n)-1]=0;
  while(!dij.empty()){
    int at=(dij.begin())->second;
    //marc[at]=1;
    int tam=adj[at].size();
    for(int i=0;i<tam;i++){
      int nxt=adj[at][i].first;
      int w=adj[at][i].second;
      if(dist[at]+w<dist[nxt]){
	if(dist[nxt]!=INF){
	  dij.erase(make_pair(dist[nxt],nxt));
	  dist[nxt]=dist[at]+w;
	  dij.insert(make_pair(dist[nxt],nxt));
	}
	else{
	  dist[nxt]=dist[at]+w;
	  dij.insert(make_pair(dist[nxt],nxt));
	}
      }
    }
    dij.erase(dij.begin());
  }
}

int main(){
  int t=1;
  while(1){
    memset(dist,INF,sizeof(dist));
    memset(v1,0,sizeof(v1));
    memset(v2,0,sizeof(v2));
    for(int i=0;i<1100000;i++) adj[i].clear();
    dij.clear();
    scanf("%d%d", &n, &m);
    if(n==0 && m==0) break;
    for(int h=0;h<m;h++){
      int p;
      int b1=0,b2=0;
      int d1=0,d2=0;
      int z1=0,z2=0;
      scanf("%d", &p);
      scanf(" %s", v1);
      scanf(" %s", v2);
      for(int i=0;i<n;i++){
	if(v1[i]=='+') b1+=(1<<i);
	else if(v1[i]=='0'){
	  d1+=(1<<i);
	  z1++;
	}
	if(v2[i]=='+') b2+=(1<<i);
	else if(v2[i]=='0'){
	  d2+=(1<<i);
	  z2++;
	}
      }
      //  adj[b1].pb(make_pair(b2,p));
      int mx=(1<<(z1/*+z2*/));
      //    printf(" prim %d\n", b2);
      for(int i=0;i<mx;i++){ 
	int f1=0;//,f2=z1;
	for(int k=0;k<n;k++){
	  if(d1&(1<<k)){
	    b1 |= (1<<k);
	    if(!(i&(1<<f1))) b1^=(1<<k);
	    f1++;
	  }
	  if(d2&(1<<k)){
	    b2-=b2&(1<<k);
	    b2^=(b1&(1<<k));
	    //   b2 |= (1<<k);
	    //   if(!(i&(1<<f2))) b2^=(1<<k);
	    //   f2++;
	  }
	}
	/*      int tam=adj[b1].size();
		int yes=1;
		for(int j=0;j<tam;j++){
		if(adj[b1][j].first==b2){
		if(adj[b1][j].second<p) yes=0;
		else if(adj[b1][j].second>p){
		swap(adj[b1][j],adj[b1][tam-1]);
		adj[b1].pop_back();
		}
		}
		}
		if(yes) */
	//printf("[-->] %d\n", b2);
	if(b1!=b2) adj[b1].pb(make_pair(b2,p));
      }
    }
    dijkstra();
    // int lim=(1<<3);
    // for(int i=0;i<lim;i++){
    //   int tam=adj[i].size();
    //   memset(ax,0,sizeof(ax));
    //   for(int k=0;k<3;k++){
    //     if(i&(1<<k)) ax[k]='+';
    //     else ax[k]='-';
    //   }
    //   //printf("V %s ->", ax);
    //   printf("V %d -->", i);
    //   for(int k=0;k<tam;k++){
    //     memset(ax,0,sizeof(ax));
    //     int prox=adj[i][k].first;
    //     int pes=adj[i][k].second;
    //     for(int f=0;f<3;f++){
    //     	if(prox&(1<<f)) ax[f]='+';
    //     	else ax[f]='-';
    //     }
    //     //printf("  %s  ", ax);
    //     printf("  %d-%d  ", prox, pes);
    //   }
    //   printf("\n");
    // }
    printf("Product %d\n", t++);
    (dist[0]==INF) ? printf("Bugs cannot be fixed.\n\n") : printf("Fastest sequence takes %d seconds.\n\n", dist[0]);
  }
  return 0;
}
