#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,a,b;
        cin>>n;

        vector< pair<int,int> > v;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            v.push_back(make_pair(b,a));
        }
        sort(v.begin(),v.end());
        int i=1,ans=1;a=v[0].first;
        while(i<n){
            if(v[i].second >= a){
                ans++;
                a = v[i].first;
            }
            cout<<v[i].second<<","<<v[i].first<<endl;
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
