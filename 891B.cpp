#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	int arr[n+1];
	for(int i=1;i<=n;i++){cin>>arr[i];arr[i] = max(1,i-arr[i]);}
	int ans = n;
	
	int maxi = n;
	for(int i=n;i>=1;i--){
		maxi = min(maxi,i);
		if((maxi>arr[i])){
			ans = ans - (maxi-arr[i]);
			maxi = min(maxi,arr[i]);
		}
	}
	cout<<ans<<endl;
}