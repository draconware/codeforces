#include<bits/stdc++.h>
using namespace std;

bool check(int a){
    int temp;
    while(a){
        temp = a%10;
        if((temp != 4)&&(temp != 7)){
            return false;
        }
    }
    return true;
}

int main(){
    int n,flag=1;
    cin>>n;

    for(int i=2;i<=n;i++){
        if(!(n%i)){
            if(check(i)){
                cout<<"YES"<<endl;
                flag=0;
                break;
            }
        }
    }
    if(flag){
        cout<<"NO"<<endl;
    }
}
