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

	string a;cin>>a;

	if(k>n){
		cout<<a;
		int mini = 30;
		for(int i=0;i<n;i++){
			mini = min(mini,a[i]-'a');
		}
		k-=n;
		while(k>0){
			char c = mini+'a';
			cout<<c;
			k--;
		}
		cout<<endl;
	}else{
		int maxi = -1,mini = 30;
		vector<int> v;
		for(int i=0;i<n;i++){
			maxi = max(maxi,a[i]-'a');
			mini = min(mini,a[i]-'a');
			v.push_back(a[i]-'a');
		}
		sort(v.begin(),v.end());
		int idx=min(k-1,n-1);
		while(idx>=0){
			if(a[idx]-'a' != maxi){break;}
			idx--;
		}
		for(int i=0;i<min(idx,k);i++){
			cout<<a[i];
		}
		if(idx>=k){return 0;}
		vector<int>::iterator it = upper_bound(v.begin(),v.end(),a[idx]-'a');
		char c = *it + 'a';
		cout<<c;
		for(int i=idx+1;i<min(n,k);i++){
			char c = mini + 'a';
			cout<<c;
		}
		cout<<endl;
	}
}