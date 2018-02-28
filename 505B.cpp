#include<bits/stdc++.h>
using namespace std;

int v[109][109];
bool mark[109];
bool vis[109];
int u,v,n,m;

void dfs(int s,int lastcolor,int p){
	if(s==v){
		if(p==1){mark[lastcolor]=true;}
	}else{
		vis[s]=true;
		for(int i=1;i<=n;i++){
			if(v[s][i]>0 && (v[s][i]==p || p==0){
				dfs()
			}
		}
	}
}

int main(){
	cin>>n>>m;

	memset(vis,0,sizeof(vis));
	for(int x,y,w,i=0;i<m;i++){
		cin>>x>>y>>w;
		v[x][y]=w;
		v[y][x]=w;
	}
	int q;
	cin>>q;
	while(q--){
		cin>>u>>v;
		memset(mark,0,sizeof(mark));
		memset(vis,0,sizeof(vis));
		dfs(u,0,1);
	}
}