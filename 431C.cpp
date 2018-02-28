#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k,d;
	cin>>n>>k>>d;

	int f[n+9],f_[n+9];
	memset(f,0,sizeof(f));
	memset(f_,0,sizeof(f_));
	for(int i=0;i<d;i++){
		f[i]=0;
	}
	f_[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				f_[i]+=f_[i-j];
			}
		}
	}
	for(int i=d;i<=n;i++){
		for(int j=1;j<d;j++){
			f[i]+=f[i-j];
		}
		for(int j=d;j<=k;j++){
			if(i-j>=0){
				f[i]+=f_[i-j];
			}
		}
	}
	cout<<f[n]<<endl;
}