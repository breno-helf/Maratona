#include <message.h>
#include <stdio.h>
#include <algorithm>
#include "oops.h"
using namespace std;

#define MASTER_NODE 0
#define DONE -1

long long INF = (long long)1e18 + 10;

int main() {
  long long N = GetN();
  long long nodes = NumberOfNodes();
  long long my_id = MyNodeId();
  long long best_so_far = 0LL;

  long long ini = (my_id * N / nodes);
  long long fim = ((my_id + 1) * N / nodes);
  //printf ("%lld %lld\n", ini, fim);
  long long mx = -INF;
  long long mn = INF;
  for (long long j = ini; j < fim; ++j) {
      long long candidate = GetNumber(j);
      mn = min(mn, candidate);
      mx = max(mx, candidate);
  }
  PutLL(MASTER_NODE, mn);
  PutLL(MASTER_NODE, mx);
  Send(MASTER_NODE);
  
  
  if (my_id == MASTER_NODE) {
      long long global_mn = INF, global_mx = -INF;
      for (int node = 0; node < nodes; ++node) {
	  long long mn = 0, mx = 0;
	  Receive(node);
	  mn = GetLL(node);
	  mx = GetLL(node);
	  global_mn = min(global_mn, mn);
	  global_mx = max(global_mx, mx);
      }
      //printf ("%lld %lld\n", global_mx, global_mn);
      
      printf("%lld\n", global_mx - global_mn);
  } 
  return 0;
}
