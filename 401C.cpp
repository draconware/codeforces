#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	string s;

	bool flag=true;
	if(n>=m){
		if(n-m > 1){
			flag=false;
		}else{
			int i=n,j=m;
			while(i>=0 && j>=0){
				s.push_back('0');
				s.push_back('1');
				i--;j--;
			}
			while(i>=0){
				s.push_back('0');i--;
			}
		}
	}else{
		if(m-n == 1){
			int i=n,j=m;
			while(i>=0 && j>=0){
				s.push_back('1');
				s.push_back('0');
				i--;j--;
			}
			while(i>=0){s.push_back('1');m--;}
		}else{
			int i=n;j=m;
			while(j-i > 1){
				s.push_back('1');
				s.push_back('1');
				s.push_back('0');
				i--;j-=2;
			}
			while(i>=0 && j>=0){
				s.push_back('1');
				s.push_back('0');
				i--;j--;
			}
			while(i>=0){
				s.push_back('1');i--;
			}
		}
	}
	cout<<s<<endl;
}