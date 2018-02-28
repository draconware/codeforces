#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	while(a>0){
		int t = a;
		a = b%a;
		b = t;
	}
	return b;
}

bool check(int arr[],int n){
	int res=0;
	for(int i=0;i<n;i++){
		res = gcd(res,arr[i]);
	}
	if(res>1){return true;}
	return false;
}

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

	int arr[n];
	int arr2[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];arr2[i]=arr[i];
		if(arr[i]&1){arr[i]=1;}
		else{arr[i]=0;}
	}
	if(check(arr2,n)){cout<<"YES"<<endl;cout<<"0"<<endl;return 0;}

	vector<int> v;
	int x=0;

	for(int i=0;i<n;i++){
		if(arr[i]==0){
			if(x>0){v.push_back(x);x=0;}
		}else{
			x++;
		}
	}
	if(x>0){v.push_back(x);}

	int ans=0;

	for(int i=0;i<(int)v.size();i++){
		ans = ans + (v[i]/2) + (v[i]%2)*2;
	}
	cout<<"YES"<<endl;
	cout<<ans<<endl;
}