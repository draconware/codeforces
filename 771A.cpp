#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<LL> v[150009];
bool mark[150009];
LL count1=0,count2=0;
LL degree[150009];

void dfs(int s){
	mark[s]=true;
	count1++;count2+=degree[s];
	for(int i=0;i<v[s].size();i++){
		if(!mark[v[s][i]]){dfs(v[s][i]);}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	memset(degree,0,sizeof(degree));

	for(int i=0,x,y;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		degree[i] = (LL)v[i].size();
	}
	memset(mark,0,sizeof(mark));
	bool flag=true; 
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			count1=0;count2=0;
			dfs(i);
			count1 = (count1*(count1-1))/2;
			if(count1*2 != count2){flag=false;break;}
		}
	}
	if(flag){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}