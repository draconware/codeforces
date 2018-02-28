#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL cube_root(LL x){
	LL s=1,h=x;
	while(s<=h){
		LL m = (s+h)/2;
		if(m*m*m == x){return m;}
		else if(m*m*m < x){s=m+1;}
		else{h=m-1;}
	}
	return -1;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		LL a,b;
		cin>>a>>b;

		LL x = cube_root(a*b);
		if(x==-1){
			cout<<"No"<<endl;
		}else{
			if(a%x==0 && b%x==0){cout<<"Yes"<<endl;}
			else{cout<<"No"<<endl;}
		}
	}
	return 0;
}