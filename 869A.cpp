#include<bits/stdc++.h>
using namespace std;

bool mark[4000007];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;

	int arr[2*n];
	memset(mark,0,sizeof(mark));
	for(int i=0;i<2*n;i++){
		cin>>arr[i];
		mark[arr[i]]=true;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=n;j<2*n;j++){
			if(mark[arr[i]^arr[j]]){ans++;}
		}
	}
	//cout<<ans<<endl;
	if(ans%2){cout<<"Koyomi"<<endl;}
	else{cout<<"Karen"<<endl;}
}