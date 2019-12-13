#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

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

	vector<pair<LL,LL> > v;
	for(int i=0;i<n;i++){
		LL x,y;cin>>x>>y;
		v.push_back(make_pair(x,y));
	}

	int dp[n][3];
	memset(dp,0,sizeof(dp));

	if(n<=2){cout<<n<<endl;return 0;}

	for(int i=0;i<n;i++){
		if(i == 0){
			dp[i][1] = 1;
			if(v[i].first + v[i].second < v[i+1].first){dp[i][2] = 1;}
		}else if(i == n-1){
			dp[i][0] = max(dp[i-1][0] , max(dp[i-1][1] , dp[i-1][2]));
			if(v[i-1].first < (v[i].first - v[i].second)){
				dp[i][1] = max(dp[i-1][0] , dp[i-1][1]) + 1;
				if(v[i-1].first + v[i-1].second < (v[i].first - v[i].second)){
					dp[i][1] = max(dp[i-1][1] , 1 + dp[i-1][2]);
				}
			}
			dp[i][2] = max(dp[i-1][0] , dp[i-1][1]) + 1;
			if(v[i-1].first + v[i-1].second < v[i].first){
				dp[i][2] = max(dp[i][2] , dp[i-1][2]+1);
			}
		}else{
			dp[i][0] = max(dp[i-1][0] , max(dp[i-1][1] , dp[i-1][2]));
			if(v[i-1].first < (v[i].first - v[i].second)){
				dp[i][1] = max(dp[i-1][0] , dp[i-1][1]) + 1;
				if(v[i-1].first + v[i-1].second < (v[i].first - v[i].second)){
					dp[i][1] = max(dp[i-1][1] , 1 + dp[i-1][2]);
				}
			}
			if(v[i].first + v[i].second < v[i+1].first){
				dp[i][2] = max(dp[i-1][0] , dp[i-1][1]) + 1;
				if(v[i-1].first + v[i-1].second < v[i].first){
					dp[i][2] = max(dp[i][2] , dp[i-1][2] + 1);
				}
			}
		}
	}
	cout<<max(dp[n-1][0] , max(dp[n-1][1] , dp[n-1][2]))<<endl;
}