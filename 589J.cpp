#include<bits/stdc++.h>
using namespace std;

char arr[11][11];
bool mark[11][11][5];
bool tile[11][11];

int w,h,c;

void dfs(int x,int y,int dir){
	//cout<<x<<","<<y<<","<<dir<<endl;
	if(!tile[x][y]){c++;}
	tile[x][y]=true;
	if(mark[x][y][dir]){return;}
	mark[x][y][dir]=true;
	if(dir==1){
		if(x-1>=0 && arr[x-1][y]!='*'){dfs(x-1,y,1);}
		else{
			if(y+1<h && arr[x][y+1]!='*'){dfs(x,y+1,2);}
			else if(x+1<w && arr[x+1][y]!='*'){dfs(x+1,y,3);}
			else if(y-1>=0 && arr[x][y-1]!='*'){dfs(x,y-1,4);}
		}
	}
	if(dir==2){
		if(y+1<h && arr[x][y+1]!='*'){dfs(x,y+1,2);}
		else{
			if(x+1<w && arr[x+1][y]!='*'){dfs(x+1,y,3);}
			else if(y-1>=0 && arr[x][y-1]!='*'){dfs(x,y-1,4);}
			else if(x-1>=0 && arr[x-1][y]!='*'){dfs(x-1,y,1);}
		}
	}
	if(dir==3){
		if(x+1<w && arr[x+1][y]!='*'){dfs(x+1,y,3);}
		else{
			if(y-1>=0 && arr[x][y-1]!='*'){dfs(x,y-1,4);}
			else if(x-1>=0 && arr[x-1][y]!='*'){dfs(x-1,y,1);}
			else if(y+1<h && arr[x][y+1]!='*'){dfs(x,y+1,2);}
		}
	}
	if(dir==4){
		if(y-1>=0 && arr[x][y-1]!='*'){dfs(x,y-1,4);}
		else{
			if(x-1>=0 && arr[x-1][y]!='*'){dfs(x-1,y,1);}
			else if(y+1<h && arr[x][y+1]!='*'){dfs(x,y+1,2);}
			else if(x+1<w && arr[x+1][y]!='*'){dfs(x+1,y,3);}
		}
	}
}

int main(){
	cin>>w>>h;

	memset(mark,0,sizeof(mark));
	memset(tile,0,sizeof(tile));

	int sx=0,sy=0,dir;
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			cin>>arr[i][j];
			if(arr[i][j]>='A' && arr[i][j]<='Z'){sx=i;sy=j;if(arr[i][j]=='U'){dir=1;}else if(arr[i][j]=='R'){dir=2;}else if(arr[i][j]=='D'){dir=3;}else{dir=4;}}
		}
	}
	c=0;
	//cout<<sx<<","<<sy<<","<<dir<<endl;
	dfs(sx,sy,dir);
	cout<<c<<endl;
}