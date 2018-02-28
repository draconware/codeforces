#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k,l,c,d,p,x,y;
	cin>>n>>k>>l>>c>>d>>p>>x>>y;

	int a = k*l;
	int b = c*d;

	cout<<(min(a/x,min(b,p/y)))/n<<endl;
}