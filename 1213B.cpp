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

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
	
		vector<int> v;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			v.pb(x);
		}	
	
		vector<int> suffix(n);
	
		suffix[n-1] = v[n-1];
		for(int i=n-2;i>=0;i--){
			suffix[i] = min(v[i],suffix[i+1]);
		}
	
		int ans=0;
	
		for(int i=0;i<n-1;i++){
			if(v[i] > suffix[i+1]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}