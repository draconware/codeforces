#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string s;
	cin>>s;

	int n = (int)s.length();
	vector<string> v;
	v.push_back("Danil");v.push_back("Olya");v.push_back("Slava");v.push_back("Ann");v.push_back("Nikita");

	int res=0,x=0;

	for(int i=0;i<n;i++){
		int w=(int)v[x].length(),y=0;
		for(int j=i;j<w+i && j<n;j++){
			if(s[j]!=v[x][j-i]){break;}
			y++;
		}
		//cout<<i<<" "<<y<<endl;
		if(y==w){res++;}
	}x++;
	for(int i=0;i<n;i++){
		int w=(int)v[x].length(),y=0;
		for(int j=i;j<w+i && j<n;j++){
			if(s[j]!=v[x][j-i]){break;}
			y++;
		}
		if(y==w){res++;}
	}x++;
	for(int i=0;i<n;i++){
		int w=(int)v[x].length(),y=0;
		for(int j=i;j<w+i && j<n;j++){
			if(s[j]!=v[x][j-i]){break;}
			y++;
		}
		if(y==w){res++;}
	}x++;
	for(int i=0;i<n;i++){
		int w=(int)v[x].length(),y=0;
		for(int j=i;j<w+i && j<n;j++){
			if(s[j]!=v[x][j-i]){break;}
			y++;
		}
		if(y==w){res++;}
	}x++;
	for(int i=0;i<n;i++){
		int w=(int)v[x].length(),y=0;
		for(int j=i;j<w+i && j<n;j++){
			if(s[j]!=v[x][j-i]){break;}
			y++;
		}
		if(y==w){res++;}
	}	
	if(res!=1){cout<<"NO"<<endl;}
	else{cout<<"YES"<<endl;}
}