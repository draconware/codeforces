#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<double> v;
	double x;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	sort(v.rbegin(),v.rend());
	double r=1,best=0,prev=0;
	for(int i=0;i<n;i++){
		double x = v[i]*r + prev*(1.0-v[i]);
		//cout<<x<<endl;
		best = max(x,best);
		prev = x;r*=(1.0-v[i]);
	}
	printf("%.12lf\n",best);
}