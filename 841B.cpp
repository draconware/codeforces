#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	int cnt=0;
	LL x,total=0;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x%2 == 1){cnt++;}
		total+=x;
	}
	if(total%2 == 0){
		if(cnt>0){cout<<"First"<<endl;}
		else{cout<<"Second"<<endl;}
	}else{
		cout<<"First"<<endl;
	}
	return 0;
}