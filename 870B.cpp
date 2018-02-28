#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}

	if(k==1){
		int ans=INT_MAX;
		for(int i=0;i<n;i++){ans = min(ans,arr[i]);}
		cout<<ans<<endl;
	}else if(k>=3){
		int ans=INT_MIN;
		for(int i=0;i<n;i++){ans = max(ans,arr[i]);}
		cout<<ans<<endl;
	}else{
		multiset<int> q;
		for(int i=1;i<n;i++){q.insert(arr[i]);}
		int ans = INT_MIN,x=arr[0];
		for(int i=1;i<n;i++){
			ans = max(ans,max(x, *q.begin()));
			q.erase(q.find(arr[i]));
			x = min(x,arr[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}