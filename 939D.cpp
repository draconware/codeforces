#include<bits/stdc++.h>
using namespace std;

vector<int> G[30];
int parent[30];
bool mark[30];

int root(int x){
	while(x != parent[x]){
		x = parent[x];
	}
	return x;
}

void merge(int x,int y){
	parent[max(x,y)] = min(x,y);
}

void dfs(int s){
	mark[s] = true;
	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(!mark[v]){
			char c1 = s+'a';
			char c2 = v+'a';
			cout<<c1<<" "<<c2<<endl;
			dfs(v);
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

	string a,b;
	cin>>a>>b;
	for(int i=0;i<26;i++){
		parent[i] = i;
	}

	for(int i=0;i<n;i++){
		int x = a[i] - 'a';
		int y = b[i] - 'a';
		int l = root(x);
		int r = root(y);
		if(l != r){
			G[x].push_back(y);
			G[y].push_back(x);
			merge(l,r);
		}
	}

	int ans = 0;
	for(int i=0;i<26;i++){
		ans = ans + (int)G[i].size();
	}

	cout<<(ans/2)<<endl;

	for(int i=0;i<26;i++){
		if(!mark[i]){
			dfs(i);
		}
	}
}