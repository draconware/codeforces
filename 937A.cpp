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

	set<int> s;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(a!=0){s.insert(a);}
	}
	cout<<s.size()<<endl;
}