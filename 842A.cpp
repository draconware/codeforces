#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int l,r,x,y;
	double k;
	cin>>l>>r>>x>>y>>k;

	bool flag=false;
	for(int i=x;i<=y;i++)
		if(floor(i*k) == ceil(i*k)){
			if((int)(i*k)>=l && (int)(i*k)<=r){flag=true;break;}
		}
	}
	if(flag){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}