#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	vector<pair<int,int> > marker,cap;
	vector<int> marker1,cap1;
	for(int i=0,x,y;i<n;i++){
		cin>>x>>y;
		marker.push_back(make_pair(y,x));
		marker1.push_back(y);
	}
	for(int i=0,x,y;i<m;i++){
		cin>>x>>y;
		cap.push_back(make_pair(y,x));
		cap1.push_back(y);
	}
	sort(marker.begin(),marker.end());
	sort(cap.begin(),cap.end());
	sort(marker1.begin(),marker1.end());
	sort(cap1.begin(),cap1.end());

	int i=0,j=0,q=0,p=0;
	
	while(i<n && j<m){
		if(marker[i].first == cap[j].first){
			if(marker[i].second == cap[j].second){j++;q++;i++;}
			else if(marker[i].second > cap[j].second){j++;}
			else{i++;}
		}
		else if(marker[i].first > cap[j].first){j++;}
		else{i++;}
	}
	i=0;j=0;
	while(i<n && j<m){
		if(marker1[i] == cap1[j]){
			j++;i++;p++;
		}else if(marker1[i] > cap1[j]){
			j++;
		}else{
			i++;
		}
	}
	cout<<p<<" "<<q<<endl;
}