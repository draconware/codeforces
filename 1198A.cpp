#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int prefix[400009],suffix[400009],arr[400009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,i;
	cin>>n>>i;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);

	vector<pair<int,int> > v;
	for(int i=0;i<n;){
		int j = i,cnt=0;
		while(j<n){
			if(arr[j]==arr[i]){cnt++;j++;}
			else{break;}
		}
		v.push_back(make_pair(arr[i],cnt));
		i = j;
	}

	// for(int i=0;i<(int)v.size();i++){cout<<v[i].first<<","<<v[i].second<<" ";}cout<<endl;

	int m = (int)v.size();

	for(int i=0;i<m;i++){
		if(i==0){prefix[i] = v[i].second;}
		else{prefix[i] = prefix[i-1] + v[i].second;}
	}
	for(int i=m-1;i>=0;i--){
		if(i==m-1){suffix[i] = v[i].second;}
		else{suffix[i] = suffix[i+1] + v[i].second;}
	}

	i = 8*i;
	if((i/n) >= 19){
		cout<<"0"<<endl;
	}else{
		int val = i/n;
		val = (1<<val);
		// cout<<val<<endl;

		if(val >= m){
			cout<<"0"<<endl;
		}else{
			int ans=n;
			int i = 0,j = val-1;
			while(j<m){
				int res=0;
				if(i>0){res+=(prefix[i-1]);}
				if(j<m-1){res+=(suffix[j+1]);}
				// cout<<i<<","<<j<<","<<res<<endl;
				ans = min(ans,res);
				j++;i++;
			}
			cout<<ans<<endl;
		}
	}
}