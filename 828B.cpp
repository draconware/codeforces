#include<bits/stdc++.h>
using namespace std;

#define P make_pair(-1,-1);
#define MAX 100000

int ans,n,m,value;
char arr[109][109];

bool f(int c){
	bool flag=false;
	for(int i=0;i<=n-c;i++){
		for(int j=0;j<=m-c;j++){
			int temp=0;
			for(int p=i;p<i+c;p++){
				for(int q=j;q<j+c;q++){
					//cout<<p<<","<<q<<","<<arr[p][q]<<" ";
					if(arr[p][q] == 'B'){temp++;}
				}
				//cout<<endl;
			}
			if(temp==value){ans=min(ans,c*c - value);flag=true;}
			//cout<<temp<<endl;
		}
	}
	if(flag){return true;}
	else{return false;}
}

int main(){
	cin>>n>>m;
	value=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='B'){value++;}
		}
	}
	//cout<<value<<endl;
	int l=1,h=min(n,m);
	ans=MAX;
	while(l<=h){
		int c = (l+h)/2;
		if(f(c)){
			h=c-1;
		}else{
			l=c+1;
		}
	}
	if(ans==MAX){cout<<"-1"<<endl;}
	else{cout<<ans<<endl;}
}