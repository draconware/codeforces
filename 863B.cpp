#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[2*n];
	for(int i=0;i<2*n;i++){cin>>arr[i];}

	sort(arr,arr+2*n);
	//for(int i=0;i<2*n;i++){cout<<arr[i]<<" ";}cout<<endl;
	
	n = 2*n;
	vector<int> v;
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			v.clear();
			for(int k=0;k<n;k++){
				if(k!=i && k!=j){v.push_back(arr[k]);}
			}
			int temp=0;
			//for(int k=0;k<(v.size());k++){cout<<v[k]<<" ";}cout<<endl;
			for(int k=1;k<(v.size());k+=2){
				temp += (v[k]-v[k-1]);
				//cout<<temp<<" ";
			}
			//cout<<endl;
			//cout<<"for "<<i<<","<<j<<" ------ "<<temp<<endl;
			ans = min(ans,temp);
		}
	}
	cout<<ans<<endl;
}