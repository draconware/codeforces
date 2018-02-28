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

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	string s;
	cin>>s;

	int a=4,b=0;
	int l=INT_MIN,r=INT_MAX,mini=INT_MAX,maxi=INT_MIN;
	vector<int> v,temp;
	for(int i=0;i<4;i++){
		v.push_back(arr[i]);
	}
	for(int i=4;i<n;i++){
		v.push_back(arr[i]);
		mini = v[0];maxi = v[0];
		for(int i=1;i<(int)v.size();i++){
			mini = min(mini,v[i]);
			temp.push_back(v[i]);
			maxi = max(maxi,v[i]);
		}
		//cout<<maxi<<" "<<mini<<endl;
		v.clear();
		v = temp;
		temp.clear();

		if(s[i]=='0'){
			if(s[i-1]=='0'){
				if(a==4 && l>maxi){
					l = maxi-1;
				}
			}else{
				if(b==4 && mini>r){

				}else{
					r = mini-1;
				}
			}
		}else{
			if(s[i-1]=='1'){
				if(b==4 && r<mini){
					r = mini+1;
				}
			}else{
				if(a==4 && maxi<l){

				}else{
					l = maxi+1;
				}
			}
		}
		if(s[i-4] == '0'){a--;}
		else{b--;}
		if(s[i]=='0'){a++;}
		else{b++;}
		//cout<<l<<" "<<r<<endl;
	}
	cout<<max(l,-1000000000)<<" "<<min(r,1000000000)<<endl;
}