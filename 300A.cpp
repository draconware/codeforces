#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a;
    cin>>n;

    vector<int> pos,neg,zero;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>0){pos.push_back(a);}
        else if(a<0){neg.push_back(a);}
        else{zero.push_back(a);}
    }
    int y,z,x,new_x,new_y,new_z;
    x=neg.size();y=pos.size();z=zero.size();
    new_x=x;new_y=y,new_z=z;
    if(x%2 == 0){
        if(x==2){
            zero.push_back(neg[0]);
            neg[0]=0;x--;z++;
        }else{
            zero.push_back(neg[0]);neg[0]=0;x--;z++;
            pos.push_back(neg[1]);neg[1]=0;x--;y++;
            pos.push_back(neg[2]);neg[2]=0;x--;y++;
        }
    }else{
        if(x > 1){
            pos.push_back(neg[0]);neg[0]=0;x--;y++;
            pos.push_back(neg[1]);neg[1]=0;x--;y++;
        }
    }
    new_x=max(new_x,x);new_y=max(new_y,y);new_z=max(new_z,z);
    if(x>0){
        cout<<x<<" ";
        for(int i=0;i<new_x;i++){
            if(neg[i]!=0){cout<<neg[i]<<" ";}
        }
        cout<<endl;
    }
    if(y>0){
        cout<<y<<" ";
        for(int i=0;i<new_y;i++){
            cout<<pos[i]<<" ";
        }
        cout<<endl;
    }
    if(z>0){
        cout<<z<<" ";
        for(int i=0;i<new_z;i++){
            cout<<zero[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
