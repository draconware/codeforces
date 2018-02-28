#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    while(T--)
    {
        int n,k;
        cin >> n >> k;
        int arr[n];
        for (int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        map<int, int> m;
        for (int i=0;i<n;i++)
        {
            arr[i]%=(k+1);
            m[arr[i]]++;
        }
        if (m.size()<=2)
        {
            map<int, int>::iterator it;
            int bol = 0;
            for (it=m.begin(); it!=m.end();++it)
            {
                if (it->second==n-1 || it->second == n)
                {
                   bol = 1;
                   cout << "YES" << endl;
                   break;
                }
            }
            if (!bol) 
            {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
	return 0;
}