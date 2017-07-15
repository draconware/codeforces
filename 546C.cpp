#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    deque<int> s1,s2;
    int n;
    cin>>n;

    int y,x;
    cin>>x;
    while(x--){
        cin>>y;
        s1.push_back(y);
    }
    cin>>x;
    while(x--){
        cin>>y;
        s2.push_back(y);
    }

    LL sol=1,ans=0;
    for(int i=2;i<=n;i++){
        sol*=i;
    }
    int flag=0;
    while(sol--){
        if(s1.empty()){
            flag=1;
            break;
        }
        if(s2.empty()){
            flag=2;
            break;
        }
        ans++;
        int p=s1.front(),q=s2.front();
        s1.pop_front();s2.pop_front();
        //cout<<p<<","<<q<<endl;
        if(p > q){
            s1.push_back(q);
            s1.push_back(p);
        }else{
            s2.push_back(p);
            s2.push_back(q);
        }
    }
    if(flag==0){
        cout<<"-1"<<endl;
    }else if(flag==1){
        cout<<ans<<" 2"<<endl;
    }else{
        cout<<ans<<" 1"<<endl;
    }
    return 0;
}
