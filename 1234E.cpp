#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int x[200009];
vector<int> pos[200009];
int val[200009];

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

	for(int i=1;i<=m;i++){cin>>x[i];}

	for(int i=1;i<=m;i++){pos[x[i]].pb(i);}
	int sum = 0;

	for(int i=1;i<m;i++){sum+=(abs(x[i]-x[i+1]));val[i] = abs(x[i] - x[i+1]);}

	vector<int> res;
	res.pb(sum);
	for(int i=2;i<=n;i++){
		for(int i=1;i<m;i++){cout<<val[i]<<" ";}cout<<endl;
		int ans = sum;
		for(int j=0;j<(int)pos[i].size();j++){
			int idx = pos[i][j];

			if(idx>1){
				ans-=val[idx-1];
				if(x[idx-1] > i){ans+=abs(x[idx-1]-1);}
				else if(x[idx-1] < i){ans+=abs(x[idx-1]+1-1);}
			}
			if(idx<n){
				ans-=val[idx];
				if(x[idx+1] > i){ans+=abs(1-(x[idx+1]));}
				else if(x[idx+1] < i){ans+=abs(1-(x[idx+1]+1));}
			}
		}
		res.pb(ans);
		for(int j=0;j<(int)pos[i].size();j++){
			int idx = pos[i][j];

			if(idx>1){
				sum-=val[idx-1];
				if(x[idx-1] > i){sum+=abs(x[idx-1]-1-(i+1));val[idx-1]=abs(x[idx-1]-(i+1));}
				else{sum+=abs(x[idx-1]+1-(i+1));val[idx-1]=abs(x[idx-1]+1-(i+1));}
			}
			if(idx<n){
				sum-=val[idx];
				if(x[idx+1] > i){sum+=abs((i+1)-(x[idx+1]-1));val[idx] = abs((i+1)-(x[idx+1]));}
				else{sum+=abs((i+1)-(x[idx+1]+1));val[idx] = abs((i+1)-(x[idx+1]+1));}
			}
		}
	}
	
	for(int i=0;i<(int)res.size();i++){cout<<res[i]<<" ";}cout<<endl;
}