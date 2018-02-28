#include<bits/stdc++.h>
using namespace std;

vector<int> G[300009];
int indeg[300009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;

	string s;
	cin>>s;
	memset(indeg,0,sizeof(indeg));

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;a--;b--;

		G[a].push_back(b);
		indeg[b]++;
	}
	int dp[n+9][30];
	memset(dp,0,sizeof(dp));

	queue<int> q;

	for(int i=0;i<n;i++){
		if(indeg[i]==0){
			q.push(i);
		}
		dp[i][s[i]-'a']++;
	}

	int cnt=0;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i=0;i<(int)G[u].size();i++){
			int v = G[u][i];
			for(int j=0;j<26;j++){
				if(s[v]-'a' == j){
					dp[v][j] = max(dp[v][j],dp[u][j]+1);
				}else{
					dp[v][j] = max(dp[v][j],dp[u][j]);
				}
			}
			indeg[v]--;
			if(indeg[v]==0){q.push(v);}
		}
		cnt++;
	}
	if(cnt==n){
		int ans = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<26;j++){
				ans = max(ans,dp[i][j]);
			}
		}
		cout<<ans<<endl;
	}else{
		cout<<"-1"<<endl;
	}
}