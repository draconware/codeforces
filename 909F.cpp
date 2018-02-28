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
	int arr[n+1];

	if(n&1){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		int l=n;
		while(l>=1){
			int x = (int)ceil(log2((float)(l+1)));
			int y = (int)pow(2.0,x);
			int s=y-1-l,e=l;
			//cout<<s<<" "<<e<<endl;
			while(s<=e){
				arr[s]=e;
				arr[e]=s;
				s++;e--;
			}
			l = y-1-l-1;
		}
		for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}cout<<endl;
	}

	if(n<=5){
		cout<<"NO"<<endl;
	}else if(n==6){
		cout<<"YES"<<endl;
		cout<<"3 6 2 5 1 4"<<endl;
	}else if(n==7){
		cout<<"YES"<<endl;
		cout<<"7 3 6 5 1 2 4"<<endl;
	}else{
		if(floor(log2((float)n)) == ceil(log2((float)n))){cout<<"NO"<<endl;}
		else{
			cout<<"YES"<<endl;
			cout<<"7 3 6 5 1 2 4 ";
			int l=8;
			while(l<=n){
				for(int i=l+1;i<=min(2*l-1,n);i++){
					cout<<i<<" ";
				}
				cout<<l<<" ";
				l = 2*l;
			}
			cout<<endl;
		}
	}
}