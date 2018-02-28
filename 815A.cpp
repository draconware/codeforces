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

	int n,m;
	cin>>n>>m;
	vector<int> a,b;

	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}

	if(n>m){
		for(int j=0;j<m;j++){
			int mini = INT_MAX;
			for(int i=0;i<n;i++){
				mini = min(mini,arr[i][j]);
			}
			if(mini>0){
				int x = mini;
				while(x>0){
					b.push_back(j+1);
					x--;
				}
				for(int i=0;i<n;i++){
					arr[i][j] -= mini;
				}
			}
		}

		for(int i=0;i<n;i++){
			int mini = INT_MAX;
			for(int j=0;j<m;j++){
				mini = min(mini,arr[i][j]);
			}
			if(mini > 0){
				int x = mini;
				while(x>0){
					a.push_back(i+1);
					x--;
				}
				for(int j=0;j<m;j++){
					arr[i][j] -= mini;
				}
			}
		}
	}else{
		for(int i=0;i<n;i++){
		int mini = INT_MAX;
		for(int j=0;j<m;j++){
			mini = min(mini,arr[i][j]);
		}
		if(mini > 0){
			int x = mini;
			while(x>0){
				a.push_back(i+1);
				x--;
			}
			for(int j=0;j<m;j++){
				arr[i][j] -= mini;
			}
		}
	}

	for(int j=0;j<m;j++){
		int mini = INT_MAX;
		for(int i=0;i<n;i++){
			mini = min(mini,arr[i][j]);
		}
		if(mini>0){
			int x = mini;
			while(x>0){
				b.push_back(j+1);
				x--;
			}
			for(int i=0;i<n;i++){
				arr[i][j] -= mini;
			}
		}
	}
	}

	bool flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] > 0){flag=false;break;}
		}
		if(!flag){break;}
	}

	if(!flag){cout<<"-1"<<endl;}
	else{
		cout<<(a.size() + b.size())<<endl;
		for(int i=0;i<(int)a.size();i++){
			cout<<"row "<<a[i]<<endl;
		}
		for(int i=0;i<(int)b.size();i++){
			cout<<"col "<<b[i]<<endl;
		}
	}
}