#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL n,q;
	cin>>n>>q;

	LL arr[n];
	for(LL i=0;i<n;i++){cin>>arr[i];}

	while(q--){
		LL x;
		cin>>x;
		if(x==1){
			LL i,k,y;
			cin>>i>>k;y=i;
			while(i<n && k>0){
				LL x = arr[i-1];
				LL j = i+1;
				while(j<=n){
					if(arr[j-1] > x){break;}
					j++;
				}
				k--;
				if(j-i>100){break;}
				y=j;
				i=j;
			}
			cout<<y<<endl;
		}else{
			LL a,b,c;
			cin>>a>>b>>c;
			for(LL i=a-1;i<b;i++){
				arr[i]+=c;
			}
		}
	}
	return 0;
}