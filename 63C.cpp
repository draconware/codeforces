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

	int a[n];
	for(int i=0;i<n;i++){cin>>a[i];}

	int b[n];
	for(int i=0;i<n;i++){cin>>b[i];}

	for(int i=0;i<n;i++){
		if(a[i]<b[i]){cout<<"-1"<<endl;return 0;}
	}

	int t=0;
	for(int i=0;i<n;i++){
		if(a[i] == b[i]){t++;}
	}
	if(t==n){
		int maxi=0;
		for(int i=0;i<n;i++){maxi = max(maxi , a[i]);}
		cout<<maxi+1<<endl;
		return 0;
	}else if(t>0){
		cout<<"-1"<<endl;
		return 0;
	}

	int x = a[0] - b[0];
	vector<int> v;
	for(int i=1;i*i <= x;i++){
		if(x%i == 0){
			v.push_back(i);
			v.push_back(x/i);
		}
	}
	sort(v.begin(),v.end());
	int ans = -1;
	for(int i=0;i<(int)v.size();i++){
		bool flag=true;
		for(int j=0;j<n;j++){
			if((a[j]/v[i])*v[i] != a[j]-b[j]){flag=false;}
		}
		if(flag){
			ans = v[i];
			break;
		}
	}
	cout<<ans<<endl;
}