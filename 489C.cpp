#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int m,s,x;
	cin>>m>>s;x=s;

	if(9*m < s){
		cout<<"-1 -1"<<endl;
	}else if(m>1 && s<1){
		cout<<"-1 -1"<<endl;
	}else{
		int a[m],b[m];
		for(int i=0;i<m;i++){
			if(i==0 && s>0){
				if(9*(m-i-1) >= s){a[i]=1;}
				else{a[i] = s - 9*(m-i-1);}	
			}else{
				if(9*(m-i-1) >= s){a[i]=0;}
				else{a[i] = s - 9*(m-i-1);}
			}
			s-=a[i];
			cout<<a[i];
		}
		cout<<" ";
		for(int i=0;i<m;i++){
			if(x>=9){b[i]=9;}
			else{b[i]=x;}
			x-=b[i];
			cout<<b[i];
		}
		//cout<<" ";
		
		//cout<<" ";
		cout<<endl;
	}
	return 0;
}