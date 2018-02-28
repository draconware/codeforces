#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b=0,c;
	cin>>n>>a>>c;
	c*=2;

	int x,ans=0;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x==1){
			if(a>0){a--;}
			else if(c>0){c-=2;b++;}
			else if(b>0){b--;}
			else{ans++;}
		}else{
			if(c>0){c-=2;}
			else{ans+=2;}
		}
	}
	cout<<ans<<endl;
}