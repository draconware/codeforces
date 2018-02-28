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

	int k;
	cin>>k;

	if(k>36){cout<<"-1"<<endl;}
	else{
		if(k&1){
			cout<<"6";k--;
		}
		for(int i=0;i<k;i+=2){
			cout<<"8";
		}
		cout<<endl;
	}
}