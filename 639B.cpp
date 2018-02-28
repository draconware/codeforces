#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,d,h;
	cin>>n>>d>>h;

	if(2*h<d || (h==1 && d==1 && n>2)){cout<<"-1"<<endl;}
	else if(h<d){
		int x=h,a=1,c=2;
		while(x--){
			cout<<a<<" "<<c<<endl;
			a=c;c++;
		}
		x=d-h;a=1;
		while(x--){
			cout<<a<<" "<<c<<endl;
			a=c;c++;
		}
		for(;c<=n;c++){
			cout<<"1 "<<c<<endl; 
		}
	}else if(h==d){
		int x=h,a=1,c=2;
		while(x--){
			cout<<a<<" "<<c<<endl;
			a=c;c++;
		}
		x=0;a=1;
		while(x--){
			cout<<a<<" "<<c<<endl;
			a=c;c++;
		}
		for(;c<=n;c++){
			cout<<"2 "<<c<<endl; 
		}
	}
}