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
		int n,curr;
		cin>>n>>curr;
	
		vector<pii> v;
		for(int i=0;i<n;i++){
			int x,y;cin>>x>>y;
			v.pb(mp(x,y));
		}
	
		vector<int> a,b;
	
		for(int i=0;i<n;i++){
			a.pb(v[i].ff);
			b.pb(v[i].ss - v[i].ff);
		}
	
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
	
		int ans=0;
		int maxi = a[n-1];
		int mini = b[0];

		if(curr>maxi){
			if(mini>=0){cout<<"-1"<<endl;}
			else{
				mini = -mini;
				ans = (curr - maxi)/(mini);
				if((curr-maxi)%mini){ans++;}
				cout<<ans+1<<endl;
			}
		}else{
			cout<<"1"<<endl;
		}
	}
}