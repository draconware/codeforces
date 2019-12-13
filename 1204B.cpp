#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

char G[109][109];
int len[109][109];
bool mark[109];
int n;

void dfs(int s,int dis){
	for(int i=1;i<=n;i++){
		if(G[s][i]=='1'){
			if(len[s][i] > dis+1){
				len[s][i] = dis+1;
				dfs(i,dis+1);
			}
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

	cin>>n;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>G[i][j];
			len[i][j] = n;
		}
	}

	int m;
	cin>>m;

	vector<int> path;

	for(int i=0;i<m;i++){int x;cin>>x;path.pb(x);}

	dfs(path[0],0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<len[i][j]<<" ";
		}
		cout<<endl;
	}

	stack<int> st;
	st.push(path[m-1]);

	for(int i=m-1;i>0;i--){
		int v = path[i];
		int u = path[i-1];
		// cout<<u<<" "<<v<<endl;
		if(i==1){st.push(u);break;}

		int mini = n,maxi=0;
		for(int j=1;j<=n;j++){
			if(G[j][v]=='1'){mini = min(mini,len[j][v]);maxi=max(maxi,len[j][v]);}
		}
		// cout<<mini<<","<<len[u][v]<<endl;
		cout<<i<<" "<<mini<<","<<len[u][v]<<endl;

		if((mini >= len[u][v])){
			continue;
		}else{
			st.push(u);
		}
	}
	cout<<(int)st.size()<<endl;
	while(!st.empty()){
		cout<<st.top()<<" ";st.pop();
	}cout<<endl;

}