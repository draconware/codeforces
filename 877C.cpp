#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	cout<<(3*n)/2<<endl;
	for(int i=2;i<=n;i+=2){cout<<i<<" ";}
	for(int i=1;i<=n;i+=2){cout<<i<<" ";}
	for(int i=2;i<=n;i+=2){cout<<i<<" ";}
	cout<<endl;
}