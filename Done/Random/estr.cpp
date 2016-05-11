#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr, args) 

const int MAXN=212;
const int INF=0x3f3f3f3f;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

dir
x + dx[dir];
y + dy[dir];

dist[x+dx[dir]][y+dy[dir]]; // andar pra frente
dist[x][y][(dir+1)%4]; // girar pra esquerda


int dist[MAXN][MAXN][4];
	
