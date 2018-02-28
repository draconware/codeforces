#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[10][2];
	for(int i=0;i<10;i++){
		arr[i][0]=0;
		arr[i][1]=1;
	}
	for(int i=0;i<n;i++){
		char c;int m;
		cin>>c>>m;
		for(int j=0;j<10;j++){
			int x = (m & (1<<j))?1:0;
			if(c=='|'){
				arr[j][0] |= x;
				arr[j][1] |= x;
			}else if(c=='&'){
				arr[j][0] &= x;
				arr[j][1] &= x;
			}else{
				arr[j][0] ^= x;
				arr[j][1] ^= x;
			}
		} 
	}
	int ans_and=(1<<10)-1,ans_or=0,ans_xor=0;
	for(int i=0;i<10;i++){
		if(arr[i][0]==1){
			if(arr[i][1]==1){ans_or^=(1<<i);}
			else{ans_xor^=(1<<i);}
		}else if(arr[i][0]==0 && arr[i][1]==0){ans_and^=(1<<i);}
	}
	cout<<"3"<<endl;
	cout<<"& "<<ans_and<<endl;
	cout<<"| "<<ans_or<<endl;
	cout<<"^ "<<ans_xor<<endl;
}