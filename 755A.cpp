#include<bits/stdc++.h>
using namespace std;

int main(){
	bool mark[1000009];
	memset(mark,1,sizeof(mark));

	for(int i=2;i*i<1000009;i++){
		if(mark[i]){
			for(int j=i*i;j<1000009;j+=i){
				mark[j]=false;
			}
		}
	}

	int n;
	cin>>n;

	for(int i=1;i<=1000;i++){
		if(!mark[n*i+1]){cout<<i<<endl;break;}
	}
	return 0;
}