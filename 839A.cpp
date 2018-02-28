#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	LL n,k;
	cin>>n>>k;

	vector<LL> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	LL r=0;
	for(int i=0;i<n;i++){
		v[i]+=r;r=0;
		if(v[i]>8){
			r = v[i]-8;
			v[i]=8;
		}
	}
	int i;
	bool flag=false;
	for(i=0;i<n;i++){
		if(v[i]>k){
			flag=true;break;
		}else{
			k-=v[i];
		}
	}
	if(flag){cout<<i+1<<endl;}
	else{cout<<"-1"<<endl;}
}