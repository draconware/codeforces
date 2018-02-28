#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> first,second,arr;
	for(int i=0,x;i<2*n;i++){
		cin>>x;
		arr.push_back(x);
	}
	sort(arr.begin(),arr.end());
	for(int i=2*n-1;i>=n;i--){
		first.push_back(arr[i]);
	}
	for(int i=n-1;i>=0;i--){
		second.push_back(arr[i]);
	}
	if(first[n-1] > second[0]){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}