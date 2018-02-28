#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m,k;
	cin>>n>>m>>k;

	char arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		int x=0;
		for(int j=0;j<m;j++){
			if(arr[i][j] == '.'){x++;}
			else{
				if(x>=k){ans += (x-k+1);}
				x=0;
			}
		}
		if(x>=k){ans += (x-k+1);}
	}
	if(k==1){cout<<ans<<endl;return 0;}
	for(int i=0;i<m;i++){
		int x=0;
		for(int j=0;j<n;j++){
			if(arr[j][i]=='.'){x++;}
			else{
				if(x>=k){ans += (x-k+1);}
				x=0;
			}
		}
		if(x>=k){ans += (x-k+1);}
	}
	cout<<ans<<endl;
}