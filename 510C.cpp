#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	vector<string> v;
	string temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	int dep[30];
	memset(dep,0,sizeof(dep));
	vector<int> v1[30];

	bool flag=true;
	for(int i=0;i<n-1;i++){
		string s1=v[i],s2=v[i+1];
		int n1=s1.length(),n2=s2.length();
		int j=0,k=0;

		while(j<n1 && k<n2){
			if(s1[j] != s2[k]){
				v1[s1[j]-'a'].push_back(s2[k]-'a');
				dep[s2[k]-'a']++;
				break;
			}
			j++;k++;
		}
		if(k==n2 && j<n1){flag=false;break;}
	}
	if(!flag){cout<<"Impossible"<<endl;return 0;}
	int ans[26],k=0;
	//cout<<"executed"<<endl;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			if(dep[j]==0){
				ans[k++]=j;
				dep[j]--;
				for(int c=0;c<v1[j].size();c++){
					dep[v1[j][c]]--;
				}
			}
		}
	}
	if(k==26){
		for(int i=0;i<26;i++){cout<< (char)(ans[i]+97);}cout<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
}