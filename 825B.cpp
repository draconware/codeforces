#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif

	char arr[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin>>arr[i][j];
		}
	}
	int x,dot;
	bool flag=false;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			int l=i,m=j;x=0;dot=0;
			while(m<5+j && m<10){
				if(arr[l][m]=='X'){x++;}
				if(arr[l][m]=='.'){dot++;}
				m++;
			}
			if(x==4 && dot==1){
				flag=true;
				break;
			}
			l=i;m=j;x=0;dot=0;
			while(l<5+i && l<10){
				if(arr[l][m]=='X'){x++;}
				if(arr[l][m]=='.'){dot++;}
				l++;
			}
			if(x==4 && dot==1){
				flag=true;
				break;
			}
			l=i;m=j;x=0;dot=0;
			while(l<5+i && l<10 && m<5+j && m<10){
				if(arr[l][m]=='X'){x++;}
				if(arr[l][m]=='.'){dot++;}
				l++;m++;
			}
			if(x==4 && dot==1){
				flag=true;
				break;
			}
			l=i;m=j;x=0;dot=0;
			while(l<5+i && l<10 && m>=0 && m>j-5){
				if(arr[l][m]=='X'){x++;}
				if(arr[l][m]=='.'){dot++;}
				l++;m--;
			}
			if(x==4 && dot==1){
				flag=true;
				break;
			}
			l=i;m=j;x=0;dot=0;
		}
		if(flag){break;}
	}
	if(flag){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}