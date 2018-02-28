#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	LL p,q,r;
	cin>>n>>p>>q>>r;

	LL arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}

	LL left_min[n],right_min[n],left_max[n],right_max[n];
	left_min[0]=arr[0];left_max[0]=arr[0];
	for(int i=1;i<n;i++){
		left_min[i] = min(arr[i],left_min[i-1]);
		left_max[i] = max(arr[i],left_max[i-1]);
	}
	right_min[n-1]=arr[n-1];right_max[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--){
		right_min[i] = min(right_min[i+1],arr[i]);
		right_max[i] = max(right_max[i+1],arr[i]);
	}

	if(p>=0 && q>=0 && r>=0){
		LL ans = arr[0]*(p+q+r);
		for(int i=1;i<n;i++){
			ans = max(ans,arr[i]*(p+q+r));
		}
		cout<<ans<<endl;
	}else if(p>=0 && q<=0 && r<=0){
		LL ans = arr[0]*p + right_min[0]*(q+r);
		for(int i=1;i<n;i++){
			ans = max(ans,arr[i]*p + right_min[i]*(q+r));
		}
		cout<<ans<<endl;
	}else if(p>=0 && q<=0 && r>=0){
		LL ans = arr[0]*q + right_max[0]*r + left_max[0]*p;
		for(int i=1;i<n;i++){
			ans = max(ans,arr[i]*q + right_max[i]*r + left_max[i]*p);
		}
		cout<<ans<<endl;
	}else if(p>=0 && q>=0 && r<=0){
		LL ans = arr[0]*(p+q) + right_min[0]*r;
		for(int i=1;i<n;i++){
			ans = max(ans,arr[i]*(p+q) + right_min[i]*r);
		}
		cout<<ans<<endl;
	}else if(p<=0 && q>=0 && r>=0){
		LL ans = arr[0]*p + right_max[0]*(q+r);
		for(int i=1;i<n;i++){
			ans = max(ans,arr[i]*p + right_max[i]*(q+r));
		}
		cout<<ans<<endl;
	}else if(p<=0 && q<=0 && r<=0){
		LL ans = arr[0]*(p+q+r);
		for(int i=1;i<n;i++){
			ans = max(ans,arr[i]*(p+q+r));
		}
		cout<<ans<<endl;
	}else if(p<=0 && q<=0 && r>=0){
		LL ans = arr[0]*(p+q) + right_max[0]*r;
		for(int i=1;i<n;i++){
			ans = max(ans, arr[i]*(p+q) + right_max[i]*r);
		}
		cout<<ans<<endl;
	}else if(p<=0 && q>=0 && r<=0){
		LL ans = arr[0]*q + left_min[0]*p + right_min[0]*r;
		for(int i=1;i<n;i++){
			ans = max(ans,arr[i]*q + left_min[i]*p + right_min[i]*r);
		}
		cout<<ans<<endl;
	}
}