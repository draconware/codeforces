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
		int h,n;
		cin>>h>>n;

		vector<int> v;
		for(int i=0;i<n;i++){int x;cin>>x;v.pb(x);}

		int ans=0;

		for(int i=1;i<n;){
			if((i+1)>=n){
				if(v[i]+1 > 2){ans++;}
				break;
			}
			if((v[i]-v[i+1]) == 1){i+=2;}
			else{i++;ans++;}
		}
		cout<<ans<<endl;
	}
}