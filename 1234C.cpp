#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

vector<int> v[2];
bool dp[2][200009][3];

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
		int n;
		cin>>n;

		for(int i=0;i<2;i++){v[i].clear();}

		for(int i=0;i<2;i++){
			string s;cin>>s;
			for(int j=0;j<n;j++){
				v[i].pb(s[j]-'0');
			}
		}
		memset(dp,0,sizeof(dp));

		for(int i=0;i<n;i++){
			// first one
			if(i==0){
				if(v[0][i] <= 2){dp[0][i][1] = true;}
				else{dp[0][i][2] = true;}

				if(v[1][i] > 2){
					if(dp[0][i][2]){dp[1][i][1] = true;}
				}
			}else{
				if(v[0][i] <= 2){
					if(dp[0][i-1][1]){dp[0][i][1] = true;}
				}else{
					if(dp[0][i-1][1]){dp[0][i][2] = true;}
				}

				if(v[1][i] <= 2){
					if(dp[1][i-1][1]){dp[1][i][1] = true;}
				}else{
					if(dp[1][i-1][1]){dp[1][i][0] = true;}
				}

				if(v[0][i] > 2){
					if(dp[1][i][0]){dp[0][i][1] = true;}
				}
				if(v[1][i] > 2){
					if(dp[0][i][2]){dp[1][i][1] = true;}
				}
			}
		}

		if(dp[1][n-1][1]){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}