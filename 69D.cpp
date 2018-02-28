#include<bits/stdc++.h>
using namespace std;

vector<int> G[100009];
vector<int> l;

void dfs(int s,int p){
	int c=0;
	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(v!=p){dfs(v,s);c++;}
	}
	if(c==0){l.push_back(s);}
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
		int a,b;
		cin>>a>>b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1,0);

	int ans = (int)l.size();
	ans = (ans-1)/2;
	ans++;

	cout<<ans<<endl;

	n = (int)l.size();
	if(n&1){
		int i=1,j=n-1;
		while(i<j){
			cout<<l[i]<<" "<<l[j]<<endl;
			i++;j--;
		}
		cout<<"1 "<<l[0]<<endl;
	}else{
		int i=0,j=n-1;
		while(i<j){
			cout<<l[i]<<" "<<l[j]<<endl;
			i++;j--;
		}
	}
}