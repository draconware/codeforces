#include<bits/stdc++.h>
using namespace std;

vector<int> v[100009];
int color[100009];
bool mark[100009];

void dfs(int s){
	mark[s]=true;
	for(int i=0;i<(int)v[s].size();i++){
		if(!mark[v[s][i]]){
			color[v[s][i]] = 1-color[s];
			dfs(v[s][i]);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(color,-1,sizeof(color));
	memset(mark,0,sizeof(mark));
	//for(int i=0;i<=n;i++){if(mark[i]){cout<<"executed"<<endl;}}
	color[1]=0;
	dfs(1);

	long long x=0,y=0;
	for(int i=1;i<=n;i++){
		if(color[i]==0){x++;}
		else{y++;}
	}
	long long ans = (x*y) - (long long)(n-1);
	cout<<ans<<endl;
}