#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    map<string,int> m;
    string str;

    while(n--){
        cin>>str;
        if(m.find(str) != m.end() ){
            m[str]++;
            cout<< str << m[str] << endl;
        }else{
            m[str] = 0;
            cout<<"OK"<<endl;
        }
    }
    return 0;
}
