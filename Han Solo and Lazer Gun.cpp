#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    double a,b,p;

    cin>>n>>a>>b;

    double x[n],y[n];

    for(int i=0;i<n;i++){
        cin>>x[i] >>y[i];
    }

    map<double,int> m;

    for(int i=0;i<n;i++){
        if(x[i] == a){
            ans = 1;
        }else{
            p = (y[i] - b)/(x[i] - a);
            if(m.find(p) != m.end()){
                m[p]++;
            }else{
                m[p] = 1;
            }
        }
    }
    ans += m.size();
    cout<<ans<<endl;
}
