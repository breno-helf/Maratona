		
		
		
		
		
		
		
		
		
		
//-------------------------------------------------------------------------------------------------------------//		
		if(y>0){
			if((dist[x][y]+1+func(0,dir))<dist[x][y]){
				if(mark[x][y+1]==0 && dist[x][y+1]!=INF){
					s.erase(make_pair(dist[x][y+1],make_pair((x)*(n-1)+y+1,0)));
					dist[x][y+1]=dist[x][y]+1+func(0,dir);
					s.insert(make_pair(dist[x][y+1],make_pair((x)*(n-1)+y+1,0)));
				}
				else{
					dist[x][y+1]=dist[x][y]+1+func(0,dir);
					s.insert(make_pair(dist[x][y+1],make_pair((x)*(n-1)+y+1,0)));
				}
			}
		}
//--------------------------------------------------------------------------------------------------------------//
