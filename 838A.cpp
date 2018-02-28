#include <cstdio>

int n, m;

char arr[2547][2547];

bool prime[50];

int check(int k) {
    int ans = 0;
    int loss = k * k;

    int tmp;

    for (int i = 0; i < n / k + 1; ++i) {
        for (int j = 0; j < m / k + 1; ++j) {
            tmp = 0;

            for (int s = 0; s < k; ++s) {
                for (int t = 0; t < k; ++t) {
                    tmp += arr[s + i * k][t + j * k];
                }
            }

            if (tmp <= loss / 2) {
                ans += tmp;
            } else {
                ans += loss - tmp;
            }
        }
    }

    return ans;
}

int main() {
    scanf("%d%d", &n, &m);

    int i, j, k;

    for (i = 0; i < n; ++i) {
        scanf("\n");

        for (int j = 0; j < m; ++j) {
            scanf("%c", &arr[i][j]);
            arr[i][j] -= '0';
        }
    }

    for (i = 2; i < 50; ++i) {
        if (prime[i] == false) {
            for (j = i * 2; j < 50; j += i) {
                prime[j] = true;
            }
        }
    }

    int min = n * m;
    
    int ans;

    if (m > n) {
        ans = m;
    } else {
        ans = n;
    }

    int tmp;

    for (k = 2; k < 50; ++k) {
        if (prime[k] == false) {
            tmp = check(k);

            if (min >= tmp) {
                min = tmp;
                ans = k;
            }
        }
    }

    printf("%d", min);
}