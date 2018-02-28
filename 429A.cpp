#include<bits/stdc++.h>
using namespace std;

vector<int> G[100009];
int val[100009],goal[100009];
vector<int> res;
bool mark[100009];	

void dfs(int s,int even,int odd,int level){
	//cout<<s<<" "<<even<<" "<<odd<<" "<<level<<endl;
	mark[s]=true;
	if((level%2 == 0) && (even%2 == 1)){val[s]=1-val[s];}
	if((level%2 == 1) && (odd%2 == 1)){val[s]=1-val[s];}
	if(val[s] != goal[s]){res.push_back(s);val[s]=goal[s];if(level%2 == 0){even++;}else{odd++;}}
	for(int i=0;i<G[s].size();i++){
		if(!mark[G[s][i]]){dfs(G[s][i],even,odd,level+1);}	
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
		int x,y;cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++){cin>>val[i];}
	for(int i=1;i<=n;i++){cin>>goal[i];}
	memset(mark,0,sizeof(mark));

	dfs(1,0,0,0);
	int ans = (int)res.size();
	cout<<ans<<endl;
	for(int i=0;i<ans;i++){cout<<res[i]<<endl;}
}