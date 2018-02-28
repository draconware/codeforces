#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int x=n,y=2*n,z=0;

	for(int i=0;i<n;i++){
		if(v[i]>=4){
			if(x>=(v[i]/4)){
				x-=(v[i]/4);v[i]-=((v[i]/4)*4);
			}else{
				v[i]-=(x*4);
				x=0;
			}
		}
	}
	if(x>0){z+=x;y+=x;}
	for(int i=0;i<n;i++){
		if(v[i]>=2){
			if(y>=(v[i]/2)){
				y-=(v[i]/2);v[i]-=((v[i]/2)*2);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(v[i]>=1){
			if(z>=v[i]){
				z-=v[i];
				v[i]=0;
			}
		}
	}
	bool flag=true;
	for(int i=0;i<n;i++){
		if(v[i]>0){flag=false;break;}
	}
	if(flag){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}