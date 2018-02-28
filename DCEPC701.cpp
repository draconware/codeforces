#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		char arr[n][m];
		bool mark[n][m];
		int level[n][m];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int arrt[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arrt[i][j];
				level[i][j]=INT_MAX;
			}
		}
		memset(mark,0,sizeof(mark));
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;

		multiset<pair<int,pair<int,int> > > mul;
		mul.insert(make_pair(0,make_pair(sx,sy)));
		level[sx][sy]=0;

		while(!mul.empty()){
			pair<int,pair<int,int> > p = *mul.begin();mul.erase(mul.begin());
			int x = p.second.first,y = p.second.second,w = p.first;
			
			if(mark[x][y]){continue;}
			//cout<<x<<","<<y<<","<<w<<endl;
			mark[x][y]=true;
			if(x==ex && y==ey){cout<<w<<endl;break;}

			if(x-1>=0 && !mark[x-1][y]){
				if(arrt[x-1][y] >= w+1){
					if(level[x-1][y] > w+1+arrt[x-1][y]-(w+1)){
						level[x-1][y]=w+1+arrt[x-1][y]-(w+1);
						mul.insert(make_pair(level[x-1][y],make_pair(x-1,y)));
					}
				}else{
					if(level[x-1][y] > w+1){
						level[x-1][y]=w+1;
						mul.insert(make_pair(level[x-1][y],make_pair(x-1,y)));
					}
				}
			}
			if(x+1<n && !mark[x+1][y]){
				if(arrt[x+1][y] >= w+1){
					if(level[x+1][y] > w+1+arrt[x+1][y]-(w+1)){
						level[x+1][y]=w+1+arrt[x+1][y]-(w+1);
						mul.insert(make_pair(level[x+1][y],make_pair(x+1,y)));
					}
				}else{
					if(level[x+1][y] > w+1){
						level[x+1][y]=w+1;
						mul.insert(make_pair(level[x+1][y],make_pair(x+1,y)));
					}
				}
			}
			if(y-1>=0 && !mark[x][y-1]){
				if(arrt[x][y-1] >= w+1){
					if(level[x][y-1] > w+1+arrt[x][y-1]-(w+1)){
						level[x][y-1]=w+1+arrt[x][y-1]-(w+1);
						mul.insert(make_pair(level[x][y-1],make_pair(x,y-1)));
					}
				}else{
					if(level[x][y-1] > w+1){
						level[x][y-1]=w+1;
						mul.insert(make_pair(level[x][y-1],make_pair(x,y-1)));
					}
				}
			}
			if(y+1<m && !mark[x][y+1]){
				if(arrt[x][y+1] >= w+1){
					if(level[x][y+1] > w+1+arrt[x][y+1]-(w+1)){
						level[x][y+1]=w+1+arrt[x][y+1]-(w+1);
						mul.insert(make_pair(level[x][y+1],make_pair(x,y+1)));
					}
				}else{
					if(level[x][y+1] > w+1){
						level[x][y+1]=w+1;
						mul.insert(make_pair(level[x][y+1],make_pair(x,y+1)));
					}
				}
			}
		}
	}
}