#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int res[n],l[n],h[n];
	l[0]=1;h[n-1]=1;
	for(int i=1;i<n-1;i++){
		l[i] = min(l[i-1]+1,arr[i]);
	}
	for(int i=n-2;i>0;i--){
		h[i] = min(h[i+1]+1,arr[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans = max(ans,min(l[i],h[i]));
	}
	cout<<ans<<endl;
}