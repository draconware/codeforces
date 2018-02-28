#include<bits/stdc++.h>
using namespace std;

vector<int> G[1009];
int ans=0,maxi;
bool mark[1009];
int dist[1009];
stack<int> st;
int inf = -100000000;

void dfs(int s){
	mark[s]=true;
	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(!mark[v]){dfs(v);}
	}
	st.push(s);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	scanf("%d %d", &n, &m);

	int arr[m+1][n+1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &arr[i][j]);			
		}
	}

	int cnt[n+1][n+1];
	memset(cnt,0,sizeof(cnt));

	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt[arr[k][i]][arr[k][j]]++;
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(cnt[i][j]==m){G[i].push_back(j);}
			}
		}
	}
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=n;i++){
		if(!mark[i]){dfs(i);}
	}

	vector<int> sorted;
	while(!st.empty()){
		sorted.push_back(st.top());st.pop();
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){dist[j]=inf;}
		dist[i]=0;
		for(int j=0;j<(int)sorted.size();j++){
			for(int k=0;k<(int)G[sorted[j]].size();k++){
				int v = G[sorted[j]][k];
				if(dist[v] < dist[sorted[j]]+1){dist[v]=dist[sorted[j]]+1;}
			}
		}
		maxi=0;
		for(int j=1;j<=n;j++){maxi = max(maxi,dist[j]);}
		ans = max(ans,maxi);
	}
	
	printf("%d\n",ans+1);
}