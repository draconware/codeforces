#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	int q=0,val[100009],arr[n],res[n];
	memset(val,0,sizeof(val));

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		if(val[arr[i]] == 0){
			//val[arr[i]]++;
			q++;
		}
		val[arr[i]]++;
	}
	res[0]=q;
	for(int i=1;i<n;i++){
		val[arr[i-1]]--;
		if(val[arr[i-1]] == 0){
			res[i] = res[i-1]-1;
		}else{
			res[i]=res[i-1];
		}
	}
	int x;
	while(m--){
		cin>>x;
		cout<<res[x-1]<<endl;
	}
}