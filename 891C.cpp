#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	while(a>0){
		int t = a;
		a = b%a;
		b = t;
	}
	return b;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	int arr[n],f=0;
	for(int i=0;i<n;i++){cin>>arr[i];if(arr[i]==1){f++;}}
	if(f>0){
		cout<<n-f<<endl;
	}else{
		int res=arr[0];
		for(int i=1;i<n;i++){
			res = gcd(res,arr[i]);
		}
		if(res!=1){cout<<"-1"<<endl;}
		else{
			int mini = n;
			for(int i=0;i<n;i++){
				int cnt=0,res=arr[i];
				for(int j=i+1;j<n;j++){
					res = gcd(res,arr[j]);
					cnt++;
					if(res==1){mini = min(mini,cnt);break;}
				}
			}
			cout<<mini+n-1<<endl;
		}
	}
}