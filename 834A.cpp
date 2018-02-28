#include<bits/stdc++.h>
using namespace std;

int main(){
	char a,b;
	cin>>a>>b;

	int n;
	cin>>n;

	int cw=0,ccw=0;
	if(a=='^'){
		if(b=='>'){x=1;y=3;}
		else if(b=='v'){x=2;y=2;}
		else if(b=='<'){x=3;y=1;}
		else{x=4;y=4;}
	}else if(a=='>'){
		if(b=='v'){x=1;y=3;}
		else if(b=='<'){x=2;y=2;}
		else if(b=='^'){x=3;y=1;}
		else{x=4;y=4;}
	}else if(a=='v'){
		if(b=='<'){x=1;y=3;}
		else if(b=='^'){x=2;y=2;}
		else if(b=='>'){x=3;y=1;}
		else{x=4;y=4;}
	}else{
		if(b=='^'){x=1;y=3;}
		else if(b=='>'){x=2;y=2;}
		else if(b=='v'){x=3;y=1;}
		else{x=4;y=4;}
	}
	if(n==0){
		cout<<"undefined"<<endl;
	}else{	
		int res1=0,res2=0;
		bool flag1=false,flag2=false;
		res1 = n-x;res2 = n-y;
		if(res1>=0 && res1%4 == 0){
			flag1=true;
		}
		if(res2>=0 && res2%4 == 0){
			flag2=true;
		}
		if((flag1 && flag2) || (!(flag1 || flag2))){
			cout<<"undefined"<<endl;
		}else if(flag1){
			cout<<"cw"<<endl;
		}else{
			cout<<"ccw"<<endl;
		}
	}
}