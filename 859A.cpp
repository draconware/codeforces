#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int k;
	cin>>k;

	int arr[k];
	for(int i=0;i<k;i++){cin>>arr[i];}

	bool mark[1000009];
	memset(mark,0,sizeof(mark));
	for(int i=0;i<k;i++){
		mark[arr[i]]=true;
	}

	int x=0;
	for(int i=1;i<=25;i++){
		if(mark[i]){x++;}
	}
	int ans = (k-x);
	int i=26;
	while(x!=k){
		if(mark[i]){x++;}
		else{ans++;}
		i++;
	}
	cout<<ans<<endl;
}