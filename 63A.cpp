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
    
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    
    int b[m];
    for(int i=0;i<m;i++){cin>>b[i];}
    
    int ans=0;
    for(int i=0;i<=m-n;i++){
        bool flag=true;
        for(int j=i;j<i+n;j++){
            if(a[j-i]+b[j]!=1){flag=false;}
        }
        if(flag){ans++;}
    }
    cout<<ans<<endl;
}