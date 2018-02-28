#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int m;
	cin>>m;
	vector<int> b(m);
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	sort(b.begin(),b.end());

	int i=0,j=0,ans=0;
	while(i<n && j<m){
		if(abs(a[i]-b[j]) <=1){
			ans++;i++;j++;
		}else if(a[i]>b[j]){
			j++;
		}else{
			i++;
		}
	}
	cout<<ans<<endl;
}