#include<bits/stdc++.h>
using namespace std;

vector<int> v[200009];
bool mark[200009];
int val[200009];

void dfs(int s){
	mark[s]=true;
	int c=1;
	set<int> ss;
	for(int i=0;i<v[s].size();i++){
		if(val[v[s][i]]>0){ss.insert(val[v[s][i]]);}
	}
	while(ss.find(c) != ss.end()){c++;}
	val[s]=c;ss.insert(c);
	for(int i=0;i<v[s].size();i++){
		if(!mark[v[s][i]]){
			while(ss.fins(c) != ss.end()){c++;}
			val[v[s][i]]=c;
			ss.insert(c);
			dfs(v[s][i]);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	memset(val,-1,sizeof(val));

	dfs(1);
	int ans=0;
	bool vis[200009];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(!vis[val[i]]){ans++;vis[val[i]]=true;}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){cout<<val[i]<<" ";}cout<<endl;
}