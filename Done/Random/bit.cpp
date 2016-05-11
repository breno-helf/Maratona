#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

const int MAXN=212345;
const int INF=0x3f3f3f3f;

int bit[MAXN],n,idx[MAXN],resp[MAXN],dir[MAXN],esq[MAXN];

vector< pair<int,int> > r;

map<int,int> mpa,mpb;




int query(int x){
	int sum=0;
	for(int k=x+2;k!=0;k-=(k&-k)) sum+=bit[k];
	return sum;

}

void up(int x, int y){
	for(int k=x+2;k<MAXN;k+=(k&-k)) bit[k]+=y;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d", &a, &b);
		r.push_back(make_pair(a,b));
		mpb[b]=1;
		mpa[a]=1;
	}
	
	sort(r.begin(),r.end());
	int s=0;
	for(pair<const int,int>& e: mpb){
		e.second=s++;
	}
	s=0;
	for(pair<const int,int>& e: mpa){
		e.second=s++;
	}
	for(int i=n-1;i>=0;i--){
		resp[mpa[r[i].first]]=query(mpb[r[i].second]);
		up(mpb[r[i].second],1);
	}
	for(int i=0;i<n;i++) printf("%d\n", resp[i]);
	return 0;
}

