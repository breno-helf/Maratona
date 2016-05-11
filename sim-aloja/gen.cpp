#include <bits/stdc++.h>
using namespace std;

#include "testlib.h"

int main(int argn, char **args) {
	registerGen(argn, args, 1);
	int n = rnd.next(1, 1000);
	int m = rnd.next(1, 1000);
	printf("%d %d\n", n, m);
	for(int i=0;i<n;i++){
	  for(int j=0;j<m;j++){
	    int a = rnd.next(1,10);
	    if(a<=4) printf(".");
	    if(a>4 && a<=9) printf("_");
	    if(a>9) printf("L");
	  }
	  printf("\n");
	}
	return 0;
}
