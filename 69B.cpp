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

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}

	bool flag=false;
	int l=-1,r=-1;

	for(int i=1;i<n;i++){
		if(flag){
			if(arr[i]<=arr[i-1]){r++;}
			else{break;}
		}else{
			if(arr[i] < arr[i-1]){l=i-1;r=i;flag=true;}
		}
	}
//	cout<<l<<" "<<r<<endl;

	if(l==-1){
		map<int,long long> mp;
		long long ans = 0;
		for(int i=0;i<n;i++){
			mp[arr[i]]++;
		}
		for(auto it = mp.begin();it!=mp.end();it++){
			ans += (it->second * (it->second - 1))/2;
			ans += (it->second);
		}
		cout<<ans<<endl;
		cout<<"1 1"<<endl;
	}else{
		for(int i=l;i>0;i--){
			if(arr[i] == arr[i-1]){l--;}
			else{break;}
		}
	//	cout<<l<<" "<<r<<endl;
		int brr[n];
		for(int i=0;i<n;i++){brr[i] = arr[i];}

		for(int i=l,j=r;i<=r;i++,j--){
			brr[i] = arr[j];
		}
		bool flag=true;
		for(int i=1;i<n;i++){
			if(brr[i]<brr[i-1]){flag=false;break;}
		}
		if(!flag){cout<<"0"<<endl;}
		else{
			cout<<"1"<<endl;
			cout<<l+1<<" "<<r+1<<endl;
		}
	}
}