#include<bits/stdc++.h>
using namespace std;

int fact(int x){
	int res=1;
	for(int i=2;i<=x;i++){
		res*=i;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	string a,b;
	cin>>a>>b;

	int x1=0,y1=0,q=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='+'){x1++;}
		if(a[i]=='-'){y1++;}
	}
	for(int i=0;i<b.length();i++){
		if(b[i]=='+'){x1--;}
		if(b[i]=='-'){y1--;}
		if(b[i]=='?'){q++;}
	}
	if(x1 < 0 || y1 < 0){cout<<"0.000000000000"<<endl;}
	else{
		//cout<<q<<" "<<x1<<" "<<y1<<endl;
		double p = (double)(( fact(q) )/( fact(x1) * fact(y1) ));
		double q1 = pow(2,q);
		//cout<<p<<","<<q1<<endl;
		cout.precision(12);
		cout<<fixed<<(p/q1)<<endl;
	}
	return 0;
}