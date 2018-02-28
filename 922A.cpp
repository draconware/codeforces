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
	
	int x,y;
	cin>>x>>y;

	if(y<1){cout<<"no"<<endl;}
	else if(y==1){
		if(x==0){cout<<"yes"<<endl;}
		else{cout<<"no"<<endl;}
	}else{
		if(x<(y-1)){cout<<"no"<<endl;}
		else{
			x = x-(y-1);
			if(x%2 == 0){cout<<"yes"<<endl;}
			else{cout<<"no"<<endl;}
		}
	}
	return 0;
}