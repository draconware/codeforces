#include<bits/stdc++.h>
using namespace std;

int inf = (int)(1e8);

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin>>s;

	int m;
	cin>>m;

	int n = (int)s.length();
	int cost[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j<i){cost[i][j] = cost[j][i];}
			else{
				cost[i][j] = 0;
				int a = i,b = j;
				while(a<=b){
					if(s[a-1] != s[b-1]){cost[i][j]++;}
					a++;b--;
				}
			}
			//cout<<cost[i][j]<<" ";
		}
		//cout<<endl;
	}
//	cout<<cost[4][19]<<endl;
	int dp[m+9][n+9];
	int backtrack[m+9][n+9];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for(int i=1;i<=min(n,m);i++){
		dp[i][i] = 0;
		backtrack[i][i] = i;
	}

	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			//cout<<"for ----- "<<i<<" "<<j<<" with ini value "<<dp[i][j]<<" -------- ";
			for(int k=1;k<=j;k++){
				if(dp[i][j] > (dp[i-1][k-1]+cost[k][j])){
					backtrack[i][j] = k;
				//	if(i==2 && k==4 && j==19){cout<<dp[i-1][k-1]<<" "<<cost[k][j]<<endl;}
					dp[i][j] = dp[i-1][k-1]+cost[k][j];
				}
			//	cout<<k<<","<<dp[i][j]<<" ";
			}
		//	cout<<endl;
		}
	}
	int ans = inf;
	for(int i=1;i<=m;i++){
		ans = min(dp[i][n],ans);
	}
	cout<<ans<<endl;

	stack<char> st;
	int i = n,k;
	for(int i=1;i<=m;i++){
		if(ans == dp[i][n]){k=i;break;}
	}
	int cnt=0;
	while(i>0){
		if(cnt>=1){st.push('+');}
		int j = backtrack[k][i];
		//cout<<i<<" "<<j<<" "<<k<<endl;
		int a=j,b=i;
		while(a<=b){
			if(s[a-1] != s[b-1]){s[a-1]=s[b-1];}
			a++;b--;
		}
		for(int l=i;l>=j;l--){
			st.push(s[l-1]);
		}
		i = j-1;
		k = k-1;
		cnt++;
	}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
	cout<<endl;
}