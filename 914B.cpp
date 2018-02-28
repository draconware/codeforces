#include<bits/stdc++.h>
using namespace std;

int cnt[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];cnt[arr[i]]++;}

	set<pair<int,int> > s;
	for(int i=0;i<n;i++){s.insert(make_pair(arr[i],cnt[arr[i]]));}

	vector<int> v;
	for(set<pair<int,int> >:: iterator it = s.begin();it!=s.end();it++){
		pair<int,int> p = *it;
		v.push_back((p.second)%2);
	}
	bool flag=false;
	n = (int)v.size();

	for(int i=n-1;i>=0;i--){
		if(v[i]%2 == 1){flag=true;break;}
	}
	if(flag){cout<<"Conan"<<endl;}
	else{cout<<"Agasa"<<endl;}
}