#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 2e5+5;

int dp[MAXN];
int order[MAXN], can_change[MAXN];

int main(){
    io;
    int n;
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> order[i];
    }
    string s;
    cin >> s;
    for(int i = 0;i < s.size(); i++){
        if(s[i] == '1')
            can_change[i+1] = 1;
    }
    for(int i = n-1;i >= 1; i--){
        if(can_change[i] == 0)
            dp[i] = 0;
        else
            dp[i] = dp[i+1] + 1;
    }
    for(int i = 1;i <= n; i++){
        int maxx = i + dp[i];
        if(maxx >= order[i]){
            
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}