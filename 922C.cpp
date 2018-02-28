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
	
	long long n,k;
	cin>>n>>k;

	if(n%2 == 0){
		if(k==1){cout<<"yes"<<endl;}
		else{cout<<"no"<<endl;}
	}else{
		multiset<long long> mul;
		for(long long i=1;i<=k;i++){
			long long r = n%i;
			if(mul.find(r) == mul.end()){
				mul.insert(r);
			}else{
				cout<<"no"<<endl;return 0;
			}
		}
		cout<<"yes"<<endl;
	}
}