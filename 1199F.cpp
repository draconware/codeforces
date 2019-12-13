#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int arr[60][60];
int dp[60][60][60][60];

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

	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='#'){arr[i+1][j+1] = 1;}
		}
	}

	for(int leni = 1;leni<=n;leni++){
		for(int i=1;i<=n-leni+1;i++){
			for(int lenj=1;lenj<=n;lenj++){
				for(int j=1;j<=n-lenj+1;j++){
					int a = i+leni-1;
					int b = j+lenj-1;
					if(leni==1 && lenj==1){
						dp[i][j][a][b] = arr[i][j];
					}else{
						int maxi = max(leni,lenj);
						dp[i][j][a][b] = maxi;

						for(int k=i;k<a;k++){
							dp[i][j][a][b] = min(dp[i][j][a][b],dp[i][j][k][b] + dp[k+1][j][a][b]);
						}
						for(int k=j;k<b;k++){
							dp[i][j][a][b] = min(dp[i][j][a][b],dp[i][j][a][k] + dp[i][k+1][a][b]);
						}
					}
				}
			}
		}
	}
	cout<<dp[1][1][n][n]<<endl;
}