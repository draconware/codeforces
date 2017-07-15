#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<string> v(n);
    string s;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<char> s1,s2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i==j)||(j==n-i-1)){
                s1.insert(v[i][j]);
            }else{
                s2.insert(v[i][j]);
            }
        }
    }
    set<char>::iterator it1=s1.begin(),it2=s2.begin();
    if((s1.size() == 1)&&(s2.size() == 1)&&(*it1 != *it2)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
