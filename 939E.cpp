#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr[6*100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout<<fixed<<setprecision(10);

	int q;
	cin>>q;
	int n=0,l=0;
	LL sum=0;

	while(q--){
		int t;
		cin>>t;

		if(t==1){
			cin>>arr[n++];
			while(l<n && ((long double)(sum + arr[n-1] + arr[l])/(l+2)) < (long double)(sum + arr[n-1])/(l+1)){
				sum += arr[l];
				l++;
			}
		}else{
			long double ans = (long double)(sum + arr[n-1])/(l+1);
			cout<<(arr[n-1] - ans)<<endl;
		}
	}
}