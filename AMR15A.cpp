#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,n;
	cin>>n;

	int r=0,nr=0;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x%2 == 0){r++;}
		else{nr++;}
	}
	if(nr<r){cout<<"READY FOR BATTLE"<<endl;}
	else{cout<<"NOT READY"<<endl;}
}