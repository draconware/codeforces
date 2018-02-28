#include <bits/stdc++.h>
using namespace std;
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
    int a, b, cnt = 0, temp;
    cin >> a >> b;
    if (a < b) temp = true;
    else temp = false;
    while (a > 0 && b > 0) {
        if (a == 1 && b == 1) break;
        if (temp == true) {
            a += 1;
            b -= 2;
            if (b < 3) temp = false;
        }
        else {
            b += 1;
            a -= 2;
            if (a < 3) temp = true;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}