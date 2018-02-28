#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int x,n,m=0;
		cin>>n;

		vector<int> v;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>x;
			if(x==0){m++;}
			v.push_back(x);
			sum+=x;
		}
		if(sum>100){
			if(sum-n+m < 100){cout<<"YES"<<endl;}
			else{cout<<"NO"<<endl;}
		}else if(sum==100){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}