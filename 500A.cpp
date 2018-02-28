#include<bits/stdc++.h>
using namespace std;

bool mark[30009];
vector<int> v[30009];

void dfs(int s){
	mark[s]=true;

	for(int i=0;i<v[s].size();i++){
		if(!mark[v[s][i]]){
			return dfs(v[s][i]);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,t,x,y;
	cin>>n>>t;
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=n-1;i++){
		cin>>x;
		v[i].push_back(i+x);
	}
	dfs(1);
	if(mark[t]){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}