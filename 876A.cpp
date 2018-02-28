#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINR_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int a,b,c;
	cin>>a>>b>>c;

	int f=1,ans=0;n--;
	while(n--){
		//cout<<f<<","<<ans<<endl;
		if(f==1){ans+=min(a,b);if(min(a,b)==a){f=2;}else{f=3;}}
		else if(f==2){ans+=min(a,c);if(min(a,c)==a){f=1;}else{f=3;}}
		else if(f==3){ans+=min(b,c);if(min(b,c)==b){f=1;}else{f=2;}}
	}
	cout<<ans<<endl;
}