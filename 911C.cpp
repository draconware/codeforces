#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a,b,c;
	cin>>a>>b>>c;

	int x1=0,x2=0,x3=0,x4=0;
	if(a==1 || b==1 || c==1){x1++;}
	if(a==2){x2++;}
	if(a==3){x3++;}
	if(a==4){x4++;}
	if(b==2){x2++;}
	if(b==3){x3++;}
	if(b==4){x4++;}
	if(c==2){x2++;}
	if(c==3){x3++;}
	if(c==4){x4++;}
	//cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
	if((x1==1) || (x2>=2) || (x3==3) || (x4==2 && x2==1)){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}