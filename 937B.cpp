#include<bits/stdc++.h>
using namespace std;

int factor(int x){
	for(int i=2;(i*i)<=x;i++){
		if(x%i == 0){
			return min(i,x/i);
		}
	}
	return -1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;

	if(n==m){cout<<"-1"<<endl;return 0;}

	for(int i=m;i>n;i--){
		int x = factor(i);
		if(x==-1 || x>n){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
}