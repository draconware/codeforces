#include<bits/stdc++.h>
using namespace std;

int c[200009];
vector<int> v[200009];
vector<int> vertices;
bool mark[200009];
int val[200009];

void dfs(int s){
	vertices.push_back(s);
	mark[s]=true;
	for(int i=0;i<v[s].size();i++){
		if(!mark[v[s][i]]){dfs(v[s][i]);}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m,k;
	cin>>n>>m>>k;

	for(int i=1;i<=n;i++){cin>>c[i];}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(mark,0,sizeof(mark));
	memset(val,0,sizeof(val));
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			vertices.clear();
			dfs(i);
			for(int i=0;i<(int)(vertices.size());i++){
				val[c[vertices[i]]]=0;
			}
			for(int i=0;i<(int)(vertices.size());i++){
				val[c[vertices[i]]]++;
			}
			int x = -1;
			for(int i=0;i<(int)(vertices.size());i++){
				x = max(x,val[c[vertices[i]]]);
			}
			//for(int i=0;i<(int)vertices.size();i++){cout<<vertices[i]<<" ";}cout<<endl;
			//cout<<i<<","<<vertices.size()<<","<<x<<endl;
			ans = ans + ((int)(vertices.size())) - x;
		}
	}
	cout<<ans<<endl;
}