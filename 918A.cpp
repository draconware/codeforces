#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	bool mark[2000];
	memset(mark,0,sizeof(mark));
	int a=1,b=1,c=2;
	mark[1]=true;

	while(c<2000){
	//	cout<<c<<" ";
		mark[c]=true;
		int t = c;
		c = c+b;
		a = b;
		b = t;
	}
	//cout<<endl;

	char arr[n];
	for(int i=0;i<n;i++){
		if(mark[i+1]){
			cout<<"O";
		}else{
			cout<<"o";
		}
	}
}