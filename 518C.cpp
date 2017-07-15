#include<bits/stdc++.h>
using namespace std;

#define MAX 100009

int c[MAX]={0};

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    int arr[n],t[m];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<m;i++){
        cin>>t[i];
    }

    long long gesture=0;

    for(int i=1;i<=n;i++){
        int a = arr[i-1];
        c[a] = i;
        //cout<<a<<" position is--> "<<i<<endl;
    }

    for(int i=0;i<m;i++){
        int a = t[i];
        int b = c[a];
        gesture += (b/k);
        if(!(b%k)){
            gesture--;
        }
        gesture++;
        //cout<<"querie element is --> "<<a<<" predefine value is --> "<<b<<" gesture is --> "<<gesture<<endl;
        if((b-1)>0){
            int d = arr[b-2];

            int temp = c[d];
            c[d] = b;
            c[a] = temp;

            temp = arr[b-1];
            arr[b-1] = arr[b-2];
            arr[b-2] = temp;
        }
    }

    cout<<gesture<<endl;
}
