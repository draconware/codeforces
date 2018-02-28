#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	cin>>n;

	vector<pair<int,int> > v;
	vector<int> arr;

	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		arr.push_back(x);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(make_pair(x,i));
	}
	sort(v.begin(),v.end());
	int res[n];
	for(int i=0;i<n;i++){
		int idx = v[i].second;
		res[idx] = arr[n-1-i];
	}
	for(int i=0;i<n;i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}