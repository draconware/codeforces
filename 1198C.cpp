#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

bool mark[500009];
int indegree[300009];
vector<int> G[300009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		int nodes = 3*n;

		vector<int> ans;

		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			indegree[x]++;
			indegree[y]++;
			G[x].pb(y);
			G[y].pb(x);

			if(!mark[x] && !mark[y] && (int)ans.size()<n){
				ans.push_back(i);
				mark[x] = true;
				mark[y] = true;
			}
		}
		if((int)ans.size() == n){
			cout<<"Matching"<<endl;
			for(int i=0;i<(int)ans.size();i++){cout<<ans[i]<<" ";}cout<<endl;
		}else{
			cout<<"IndSet"<<endl;
			int cnt=0;
			for(int i=1;i<=nodes;i++){
				if(!mark[i]){cout<<i<<" ";cnt++;}
				else{continue;}
				if(cnt == n){break;}
			}
			cout<<endl;
		}
		for(int i=1;i<=nodes;i++){G[i].clear();}
		for(int i=1;i<=nodes;i++){mark[i]=false;indegree[i]=0;}
	}
}