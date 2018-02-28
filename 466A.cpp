#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;

	if(n<m){
		if(n*a > b){cout<<b<<endl;}
		else{cout<<a*n<<endl;}
	}
	else{
		int ans=0;
		while(n>=m){
			if(a*m > b){ans+=b;}
			else{ans+=(a*m);}
			n-=m;
		}
		if(n*a > b){cout<<ans+b<<endl;}
		else{cout<<ans+a*n<<endl;}
	}
}