#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	LL n;
	LL k;
	cin>>n>>k;

	LL arr[k];
	for(LL i=0;i<k;i++){cin>>arr[i];}

	LL type=0,amount = (n/arr[0]),ans =(n - (n/arr[0])*arr[0]);
	for(LL i=1;i<k;i++){
		if(ans > (n - (n/arr[i])*arr[i])){
			ans = (n - (n/arr[i])*arr[i]);
			type = i;
			amount = n/arr[i];
		}
	}
	cout<<type+1<<" "<<amount<<endl;
}	