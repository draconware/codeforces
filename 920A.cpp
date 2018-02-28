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

	int t;
	cin>>t;

	while(t--){
		int n,k;
		cin>>n>>k;

		int arr[n];
		for(int i=0;i<n;i++){arr[i]=INT_MAX;}

		for(int i=0;i<k;i++){
			int x;cin>>x;
			int c=1,l=x-2,r=x;
			arr[x-1] = min(arr[x-1],c);
			c++;
			while(l>=0 || r<n){
				if(l>=0){arr[l] = min(arr[l],c);l--;}
				if(r<n){arr[r] = min(arr[r],c);r++;}
				c++;
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			ans = max(ans,arr[i]);
		}
		cout<<ans<<endl;
	}
}