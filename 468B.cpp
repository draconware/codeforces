#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,a,b;
	cin>>n>>a>>b;

	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mp[arr[i]] = i;
	}

	int res[n+1];
	memset(res,-1,sizeof(res));
	for(int i=1;i<=n;i++){
		if(res[i]==-1){
			if(mp[a-arr[i]]>0 && res[mp[a-arr[i]]]==-1){res[mp[a-arr[i]]]=0;res[i]=0;}
			else if(mp[b-arr[i]]>0 && res[mp[b-arr[i]]]==-1){res[mp[b-arr[i]]]=1;res[i]=1;}
			else{cout<<"NO"<<endl;return 0;}
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++){cout<<res[i]<<" ";}cout<<endl;
}