#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[101];
	memset(arr,0,sizeof(arr));

	for(int i=0,x;i<n;i++){
		cin>>x;arr[x]++;
	}
	int cnt=0;
	for(int i=1;i<=100;i++){
		if(arr[i]>0){cnt++;}
	}
	if(cnt>2 || cnt==1){cout<<"NO"<<endl;}
	else{
		int x=0,y=0,i=0;
		while(x==0){
			if(arr[i]>0){x=i;}
			i++;
		}
		while(y==0){
			if(arr[i]>0){y=i;}
			i++;
		}
		if(arr[x]==arr[y]){cout<<"YES\n"<<x<<" "<<y<<endl;}
		else{cout<<"NO"<<endl;}
	}
}