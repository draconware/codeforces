#include<bits/stdc++.h>
using namespace std;

int n,k;
string s;

bool f(int m){
	int i,best=-1;
	queue<char> q;
	int arr[30];
	memset(arr,0,sizeof(arr));
	for(i=0;i<m;i++){
		arr[s[i]-'a']++;
		best = max(best,arr[s[i]-'a']);
		q.push(s[i]);
	}
	//cout<<best<<" ";
	if(m-best <= k){return true;}
	while(i<n){
		arr[q.front() - 'a']--;q.pop();
		arr[s[i]-'a']++;
		q.push(s[i]);best=-1;
		for(int j=0;j<30;j++){best = max(best,arr[j]);}
		//cout<<best<<" ";
		if(m-best <= k){return true;}
		i++;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>n>>k;
	cin>>s;

	int ans=1,l=1,h=n;
	while(l<=h){
		int m = (l+h)/2;
	//	cout<<"for m "<<m<<" ------"<<endl;
		if(f(m)){
			ans=m;
			l=m+1;
		}else{
			h=m-1;
		}
	//	cout<<endl;
	}
	cout<<ans<<endl;
}