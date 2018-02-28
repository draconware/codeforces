#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	while(a>0){
		int temp = a;
		a = b%a;
		b=temp;
	}
	return b;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n;
	cin>>n;

	int p=1,q=n-1;
	for(int i=2;i<=(n/2);i++){
		if(gcd(i,n-i) == 1){p=i;q=n-i;}
	}
	cout<<p<<" "<<q<<endl;
}