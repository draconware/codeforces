#include<bits/stdc++.h>
using namespace std;

#define LL long long
const LL inf = 999999999999999;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;
	//cout<<n<<endl;
	vector<LL> cost(n+9);
	for(int i=1;i<=n;i++){
		cin>>cost[i];
	}
	//for(int i=1;i<=n;i++){cout<<cost[i]<<" ";}cout<<endl;
	vector<string> v(n+9);
	string s;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	string pre,rpre,now,rnow;
	pre=v[1];
	for(int j=0;j<pre.length();j++){
		rpre.push_back(pre[pre.length()-j-1]);
	}
	LL dp[n+9][2];
	dp[1][0]=0;dp[1][1]=cost[1];
	//cout<<dp[1][0]<<","<<dp[1][1]<<" ";
	for(int i=2;i<=n;i++){
		now.clear();rnow.clear();
		now=v[i];
		for(int j=0;j<now.length();j++){
			rnow.push_back(now[now.length()-j-1]);
		}
		dp[i][0]=dp[i][1]=inf;
		if(pre.compare(now) <= 0){dp[i][0] = min(dp[i][0],dp[i-1][0]);}
		if(pre.compare(rnow) <= 0){dp[i][1] = min(dp[i][1],dp[i-1][0]+cost[i]);}
		if(rpre.compare(now) <= 0){dp[i][0] = min(dp[i][0],dp[i-1][1]);}
		if(rpre.compare(rnow) <= 0){dp[i][1] = min(dp[i][1],dp[i-1][1]+cost[i]);}
		//cout<<dp[i][0]<<","<<dp[i][1]<<" ";
		pre.clear();rpre.clear();
		pre=now;
		rpre=rnow;
		//cout<<pre<<" "<<rpre<<endl;
	}//cout<<endl;
	LL ans = min(dp[n][0],dp[n][1]);
	if(ans >= inf){cout<<"-1"<<endl;}
	else{cout<<ans<<endl;}
}