#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;	
	LL m,k,ans=0,total;
	cin>>n>>k>>m;
	total = n*m;
	int arr[n];

	for(int i=0;i<n;i++){cin>>arr[i];}
	
	vector<pair<int,LL> > v;
	int x=1;

	for(int i=1;i<n;i++){
		if(arr[i]==arr[i-1]){x++;}
		else{
			if(x>=k){ans+=(m*k*(x/k));x-=(k*(x/k));}
			if(x!=0){v.push_back(make_pair(arr[i-1],x));}
			x=1;
		}
	}
	if(x>=k){ans+=(m*k*(x/k));x-=(k*(x/k));}
	if(x!=0){v.push_back(make_pair(arr[n-1],x));}

	n = (int)v.size();
	//for(int i=0;i<n;i++){cout<<v[i].first<<","<<v[i].second<<" ";}cout<<endl;
	int l = 0;
	while(l<(n/2)){
		if(v[l].first == v[n-l-1].first){
			ans += ((m-1)*k*((v[l].second+v[n-l-1].second)/k));
			if((v[l].second+v[n-l-1].second)%k != 0){
				break;
			}
		}else{
			break;
		}
		l++;
	}
	//cout<<l<<" "<<ans<<endl;
	if(l==n/2){
		ans += (k*((m*v[l].second)/k));
		if((m*v[l].second)%k == 0){
			for(int i=0;i<l;i++){
				ans += (v[i].second + v[n-i-1].second);
			}
		}
	}
	//cout<<ans<<endl;
	cout<<total - ans<<endl;
}