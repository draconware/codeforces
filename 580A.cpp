#include<bits/stdc++.h>
using namespace std;

struct node{
	int first,second;
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
	#endif

	int n,ans=0;
	cin>>n;

	int arr[n];
	struct node v[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		v[i].first=1;
		v[i].second=arr[i];
	}
	int k=1,m=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>=m){
			k++;m=arr[i];
		}else{
			ans = max(ans,k);k=1;
			m=arr[i];
		}
		//cout<<k<<endl;
	}
	ans = max(ans,k);
	cout<<ans<<endl;
	return 0;
}