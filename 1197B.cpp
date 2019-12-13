#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

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

	vector<int> v;

	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.pb(x);
	}

	int idx=0;
	for(int i=0;i<n;i++){
		if(v[i] > v[idx]){idx = i;}
	}

	int l = idx-1,r = idx+1;
	int curr = v[idx];

	while((l>=0) && (r<n)){
		if(v[l]>=v[r]){
			if(curr > v[l]){
				curr = v[l];l--;
			}else{
				cout<<"NO"<<endl;return 0;
			}
		}else{
			if(curr > v[r]){
				curr = v[r];r++;
			}else{
				cout<<"NO"<<endl;return 0;
			}
		}
	}
	while(l>=0){
		if(curr > v[l]){
			curr = v[l];l--;
		}else{
			cout<<"NO"<<endl;return 0;
		}
	}
	while(r<n){
		if(curr > v[r]){
			curr = v[r];r++;
		}else{
			cout<<"NO"<<endl;return 0;
		}
	}
	cout<<"YEs"<<endl;
}