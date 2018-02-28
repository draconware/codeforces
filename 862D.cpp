#include<bits/stdc++.h>
using namespace std;

int n,one,zero,x;

int query(string s){
	cout<<"? "<<s<<endl;
	int ans;cin>>ans;
	return (n-ans);
}
void f0(int l,int h){
	if(l==h){zero=l;return ;}
	int m = (l+h)/2;
	string temp;
	for(int i=0;i<n;i++){temp.push_back('1');}
	for(int i=l;i<=m;i++){temp[i]='0';}
	int y = query(temp)-x;
	
	if(y != -(m-l+1)){f0(l,m);}
	else{f0(m+1,h);}
}


void f1(int l,int h){
	if(l==h){one = l;return;}
	int m = (l+h)/2;
	string temp;
	for(int i=0;i<n;i++){temp.push_back('1');}
	for(int i=l;i<=m;i++){temp[i]='0';}
	int y = query(temp)-x;
	
	if(y != (m-l+1)){f1(l,m);}
	else{f1(m+1,h);}
}

void f(int l,int h){
	int m = (l+h)/2;
	string temp;
	for(int i=0;i<n;i++){temp.push_back('1');}
	for(int i=l;i<=m;i++){temp[i]='0';}

	int y = query(temp)-x;
	if(y == (m-l+1)){
		zero=l;
		f1(m+1,h);
	}else if(y == (l-m-1)){
		one=l;
		f0(m+1,h);
	}else{
		f(l,m);
	}
}

int main(){
	cin>>n;

	string s(n,'1');
	x = query(s);

	f(0,n-1);
	cout<<"! "<<zero+1<<" "<<one+1<<endl;
}