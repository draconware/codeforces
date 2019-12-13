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

	vector<int> v;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.pb(x);
	}

	map<int,int> mp;
	int ans = 0;

	for(int i=0;i<n;i++){
		// cout<<i<<" ---- "<<endl;
		mp.clear();
		bool flag=true;
		int idx = i-1;
		for(int j=0;j<i;j++){
			mp[v[j]]++;
			if(mp[v[j]]==2){flag=false;idx = j-1;mp[v[j]]--;break;}
		}

		int idx2=i;
		for(int j=n-1;j>=i;j--){
			mp[v[j]]++;
			// cout<<mp[v[j]]<<","<<v[j]<<endl;
			if(mp[v[j]]==2){idx2 = j+1;break;}
		}
		// cout<<idx<<" "<<idx2<<endl;

		ans = max(ans,idx+1+n-idx2);

		if(!flag){
			break;
		}
	}
	cout<<n-ans<<endl;
}