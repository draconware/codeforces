#include<bits/stdc++.h>
using namespace std;

vector<int> v[1009];
int mark[1009];
int deg[1009];
int val[1009];
int vertices,edges,s;
bool vis[1009];
int gov[1009];

void dfs(int x){
	vis[x]=true;
	vertices++;
	edges+=deg[x];
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]]){
			mark[v[x][i]]=s;
			dfs(v[x][i]);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int n,m,k,res=0;
	cin>>n>>m>>k;

	for(int i=0;i<=n;i++){mark[i]=i;deg[i]=0;val[i]=0;}
	for(int i=0;i<k;i++){cin>>gov[i];}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//cout<<"executed"<<endl;
	for(int i=1;i<=n;i++){deg[i]=(int)(v[i].size());}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<k;i++){
		int x=gov[i];
		vertices=0;edges=0;s=x;
		dfs(x);
		res += (vertices*(vertices-1))/2 - edges/2;
		val[x]=vertices;
	}
	//cout<<"executed"<<endl;
	//for(int i=0;i<k;i++){cout<<val[gov[i]]<<" ";}cout<<endl;
	//for(int i=1;i<=n;i++){cout<<mark[i]<<" ";}cout<<endl;
	int comp=0;
	for(int i=0;i<k;i++){
		comp=max(comp,val[gov[i]]);
		mark[gov[i]]=0;
	}
	//comp = 
	for(int i=1;i<=n;i++){
		if(mark[i]==i){
			//cout<<i<<" ";
			vertices=0;edges=0;s=i;
			dfs(i);
			//cout<<vertices<<" "<<edges<<endl;
			res += (vertices*(vertices-1))/2 - edges/2;
			res += comp*vertices;
			comp += vertices;
		}
	}
	//cout<<"executed"<<endl;
	cout<<res<<endl;
}