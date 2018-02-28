#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,r;
	cin>>n>>r;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}

	double res[n];

	for(int i=0;i<n;i++){
		double ans = r;
		for(int j=0;j<i;j++){
			if(abs(arr[i]-arr[j])<=2*r){
				double x = (4*r*r) - ((arr[i]-arr[j])*(arr[i]-arr[j])) + 0.0;
				ans = max(ans,sqrt(x) + res[j]);
			}
		}
		res[i]=ans;
	}
	for(int i=0;i<n;i++){
		cout<<fixed<<setprecision(11)<<res[i]<<" ";
	}
	cout<<endl;
}