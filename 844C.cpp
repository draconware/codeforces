#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k=0;
	cin>>n;

	int arr[n+9];
	vector<int> v;
	vector<vector<int> > res(n+9);
	for(int i=1;i<=n;i++){cin>>arr[i];v.push_back(arr[i]);}
	sort(v.begin(),v.end());

	int idx[n+9];
	bool mark[n+9];
	memset(mark,0,sizeof(mark));
	vector<int> temp;
	for(int i=1;i<=n;i++){
		temp.clear();
		vector<int>::iterator it = lower_bound(v.begin(),v.end(),arr[i]);
		int j = it-v.begin();j++;
		cout<<i<<" "<<j<<endl;
		idx[i]=j;
		if(i==j){temp.push_back(i);res.push_back(temp);mark[i]=true;k++;}
	}
	for(int i=1;i<=n;i++){
		int best=0;temp.clear();
		while(i<=n){
			if(mark[i]){i++;continue;}
			best = max(best,idx[i]);
			temp.push_back(i);
			if(best == i){break;}
			i++;
		}
		if(temp.size() > 0){res.push_back(temp);k++;}
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i].size()<<" ";
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}