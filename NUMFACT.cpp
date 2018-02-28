#include<bits/stdc++.h>
using namespace std;

int arr[1000009];

int main(){
	int t;
	cin>>t;

	while(t--){
		memset(arr,0,sizeof(arr));
		set<int> s;
		int n,x;
		cin>>n;

		vector<int> v;
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		for(int i=0;i<n;i++){
			x = v[i];
			for(int j=2;j*j<=x;j++){
				if(x%j == 0){
					s.insert(j);
					while(x%j == 0){
						x/=j;
						arr[j]++;
					}
					//cout<<j<<" "<<arr[j]<<endl;
				}
			}
			if(x>1){arr[x]++;s.insert(x);}
		}
		set<int>::iterator it;
		int ans=1;
		for(it=s.begin();it!=s.end();it++){
			ans *= (arr[ *it ]+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}