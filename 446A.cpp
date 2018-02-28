#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n+9],l[n+9],r[n+9];
	memset(arr,0,sizeof(arr));
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));

	for(int i=1;i<=n;i++){cin>>arr[i];}
	arr[n+1]=INT_MAX;
	for(int i=1;i<=n;i++){
		if(arr[i] > arr[i-1]){
			l[i]=l[i-1]+1;
		}else{
			l[i]=1;
		}
	}
	for(int i=n;i>0;i--){
		if(arr[i+1] > arr[i]){r[i]=r[i+1]+1;}
		else{r[i]=1;}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans = max(ans,l[i-1]+1);
		ans = max(ans,r[i+1]+1);
		if(arr[i+1]-arr[i-1]>1){ans=max(ans,l[i-1]+1+r[i+1]);}
	}
	cout<<ans<<endl;
}