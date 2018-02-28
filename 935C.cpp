#include<bits/stdc++.h>
using namespace std;

#define LD long double

LD dist(LD x1,LD y1,LD x2,LD y2){
	return (((y2-y1)*(y2-y1)) + ((x2-x1)*(x2-x1)));
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(17);
	LD r,x1,y1,x2,y2;
	cin>>r>>x1>>y1>>x2>>y2;

	if(dist(x1,y1,x2,y2) >= (r*r)){
		cout<<x1<<" "<<y1<<" "<<r<<endl;
	}else{
		LD d = dist(x1,y1,x2,y2);
		d = (LD)sqrt(d);
		if(d==0){
			cout<<(2*x1 + r)/2 <<" "<<y1<<" "<<r/2<<endl;return 0;
		}

		LD ansx = x1,ansy = y1;
		ansy = ansy + r*((y1 - y2)/d);
		ansx = ansx + r*((x1 - x2)/d);
		ansx = (ansx + x2)/2;
		ansy = (ansy + y2)/2;
		LD ansr = dist(x2,y2,ansx,ansy);
		ansr = (LD)sqrt(ansr);
		cout<<ansx<<" "<<ansy<<" "<<ansr<<endl;
	}
}