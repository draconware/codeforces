#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
 	freopen("output.out","w",stdout);
  	#endif
	
	int n;
	cin>>n;

	string str;
	cin>>str;

	int s=0;
	while(s<n && str[s]!='1'){
		s++;
	}
	if(s==n){cout<<"0"<<endl;return 0;}
	int arr[n+9],k=0,ans=0;
	bool flag=false;
	for(int i=s;i<n;i++){
		if(str[i]=='1'){
			ans++;flag=false;
		}else{
			if(flag){arr[k++]=0;ans=0;}
			else{arr[k++]=ans;ans=0;flag=true;}
		}
		//cout<<ans<<" "<<i<<endl;
	}
	if(ans>0){arr[k++]=ans;}
	for(int i=0;i<k;i++){
		cout<<arr[i];
	}
	cout<<endl;
}