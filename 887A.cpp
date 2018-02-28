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

	string s,temp;
	cin>>s;

	int n = (int)s.length();
	for(int i=n-1;i>=0;i--){
		temp.push_back(s[i]);
	}
	//cout<<n<<endl;
	if(n<7){cout<<"no"<<endl;}
	else{
		int x=0;
		for(int i=0;i<6;i++){
			if(temp[i]=='1'){x++;}
		}
		int idx=6;
		while(idx<n && x>0){
			x--;
			if(temp[idx]=='1'){x++;}
			idx++;
		}
		bool flag=false;
		for(int i=idx;i<n;i++){
			if(temp[i]=='1'){flag=true;}
		}
		if(flag){cout<<"yes"<<endl;}
		else{cout<<"no"<<endl;}
	}
}