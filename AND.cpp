#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	LL n,x;
	cin>>n;

	vector<LL> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	int arr[n][32];
	memset(arr,0,sizeof(arr));

	LL ans=0;
	for(int i=0;i<n;i++){
		x = v[i];
		for(int i=31;i>=0 && x>0;i--){
			LL y = (LL)pow(2,i);
			if(x/y > 0){
				arr[v[i]][i]=1;
				x%=y;
			}
		}
	}
	for(int i=0;i<32;i++){
		x=0;
		for(int j=0;j<n;j++){
			if(arr[j][i]==1){x++;}
		}
		ans += ((x*(x-1))/2)((LL)pow(2,i));

	}
	cout<<ans<<endl;
}