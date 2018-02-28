#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	int p[n],arr[n];
	for(int i=0;i<n;i++){
		cin>>p[i];p[i]--;
		arr[i]=0;
	}
	cout<<"1"<<" ";
	int x=n-1;
	for(int i=0;i<n-1;i++){
		arr[p[i]]=1;

		while(arr[x]!=0){x--;}
		cout<<i+2-(n-x-1)<<" ";
	}
	cout<<"1"<<endl;
}