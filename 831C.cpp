#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,k,n,temp=0;
	cin>>k>>n;

	vector<int> v,polycarp,sum;
	for(int i=0;i<k;i++){
		cin>>x;temp+=x;
		v.push_back(x);sum.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cin>>x;
		polycarp.push_back(x);
	}
	sort(pplycarp.begin(),polycarp.end());
	set<int> res;
	for(int i=0;i<n;i++){
		int x = polcarp[i];
		for(int i=0;i<k;i++){
			res.insert(x-sum[i]);
		}
	}

	set<int>::iterator it=s.begin();
	for(;it!=s.end();it++){
		for(int i=0;i<k;i++){
			
		}
	}
}