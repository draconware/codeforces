#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int val[1009][5];
int cost[1009];

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

	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<m;j++){
			val[j][s[j]-'A']++;
		}
	}

	for(int i=0;i<m;i++){
		cin>>cost[i];
	}

	int ans=0;
	for(int i=0;i<m;i++){
		int maxi = 0;
		for(int j=0;j<5;j++){maxi = max(maxi,val[i][j]);}
		ans = ans + maxi*cost[i];
	}
	cout<<ans<<endl;
}