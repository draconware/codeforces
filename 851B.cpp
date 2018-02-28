#include<bits/stdc++.h>
using namespace std;

#define LD long double

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	LD x1,x2,y1,y2,z1,z2;
	cin>>x1>>x2>>y1>>y2>>z1>>z2;

	LD d1 = sqrt((x1-y1)*(x1-y1)+(x2-y2)*(x2-y2));
	LD d2 = sqrt((x1-z1)*(x1-z1)+(x2-z2)*(x2-z2));
	LD d3 = sqrt((z1-y1)*(z1-y1)+(z2-y2)*(z2-y2));

	vector<LD> v;
	v.push_back(d1);v.push_back(d2);v.push_back(d3);
	sort(v.begin(),v.end());
	//cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	if(v[2]>=v[1]+v[0]){cout<<"No"<<endl;}
	else{
		if(d1 == d3){cout<<"Yes"<<endl;}
		else{cout<<"No"<<endl;}
	}
}