#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,n;
    cin>>n;

    queue<int> x,y,z;

    int arr[4];
    for(int i=0;i<4;i++){arr[i]=0;}
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a]++;
        if(a == 1){x.push(i+1);}
        else if(a==2){y.push(i+1);}
        else{z.push(i+1);}
    }
    cout<<min(arr[1],min(arr[2],arr[3]))<<endl;
    while((!x.empty())&&(!y.empty())&&(!z.empty())){
        cout<<x.front()<<" "<<y.front()<<" "<<z.front()<<endl;
        x.pop();y.pop();z.pop();
    }
    return 0;
}
