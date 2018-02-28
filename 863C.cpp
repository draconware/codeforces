#include <bits/stdc++.h>
#define int long long 
#define ulld unsigned 
using namespace std;

bool win(int a, int b) {
    return (a - b == 1) || (a - b == -2);
}

int A[5][5], B[5][5];
int was[5][5];
int sa[1024], sb[1024];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int k, a, b;
    cin >> k >> a >> b;

    for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
        cin >> A[i][j];
    for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
        cin >> B[i][j];

    int i = 1;
    int alice = 0, bob = 0;

    while (i <= k) {
      //  cout << a << " " << b << endl;
        if (!was[a][b]) {
            if (win(a, b)) alice++;
            if (win(b, a)) bob++;
            sa[i] = alice;
            sb[i] = bob;

            was[a][b] = i++;
            int na = A[a][b];
            int nb = B[a][b];
            a = na;
            b = nb;

        }
        else {
            int dif = i - was[a][b];
            //cout << "dif " << dif << endl;
            int times = (k - i ) / dif;
            int alice_mean = alice - sa[was[a][b] - 1];
            int bob_mean = bob - sb[was[a][b] - 1];

            alice += times * alice_mean;
            bob += times * bob_mean;

            i += times * dif;

            while (i <= k) {
                if (win(a, b)) alice++;
                if (win(b, a)) bob++;

                int na = A[a][b];
                int nb = B[a][b];
                a = na;
                b = nb;
                i++;
            }
            break;
        }
    }

    cout << alice << " " << bob << endl;
    return 0;
}